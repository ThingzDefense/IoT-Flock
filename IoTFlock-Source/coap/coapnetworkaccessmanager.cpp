/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2015-2016 Simon Stuerz <simon.stuerz@guh.guru>           *
 *                                                                         *
 *  This file is part of QtCoap.                                           *
 *                                                                         *
 *  QtCoap is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, version 3 of the License.                *
 *                                                                         *
 *  QtCoap is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with QtCoap. If not, see <http://www.gnu.org/licenses/>.         *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*!
    \class CoapNetworkAccessManager
    \brief The client connection class to a CoAP server.

    \ingroup coap

    The CoapNetworkAccessManager class provides a signal solt based communication with a \l{https://tools.ietf.org/html/rfc7252}{CoAP (Constrained Application Protocol)}
    server. The API of this class was inspired by the \l{http://doc.qt.io/qt-5/qnetworkaccessmanager.html}{QNetworkAccessManager} and was
    written according to the \l{https://tools.ietf.org/html/rfc7252}{RFC7252}.
    This class supports also blockwise transfere according to the \l{https://tools.ietf.org/html/draft-ietf-core-block-18}{IETF V18} specifications and
    observing resources according to the \l{https://tools.ietf.org/html/rfc7641}{RFC7641}.

    \sa CoapReply, CoapRequest

    \section2 Example
    \code
        MyClass::MyClass(QObject *parent) :
          QObject(parent)
        {
          CoapNetworkAccessManager *coap = new CoapNetworkAccessManager(this);
          connect(coap, SIGNAL(replyFinished(CoapReply*)), this, SLOT(onReplyFinished(CoapReply*)));

          CoapRequest request(QUrl("coap://coap.me/hello"));
          coap->get(request);
        }
    \endcode

    \code
        void MyClass::onReplyFinished(CoapReply *reply)
        {
          if (reply->error() != CoapReply::NoError) {
            qWarning() << "Reply finished with error" << reply->errorString();
            reply->deleteLater();
            return;
          }

          qDebug() << "Reply finished" << reply;
          reply->deleteLater();
        }
    \endcode
*/

/*! \fn void CoapNetworkAccessManager::replyFinished(CoapReply *reply);
    This signal is emitted when a \a reply is finished.
*/

/*! \fn void CoapNetworkAccessManager::notificationReceived(const CoapObserveResource &resource, const int &notificationNumber, const QByteArray &payload);
    This signal is emitted when a value of an observed \a resource changed. The \a notificationNumber specifies the the count of the notification
    to keep the correct order. The value can be parsed from the \a payload.
*/

#include "coapnetworkaccessmanager.h"
#include "coappdu.h"
#include "coapoption.h"

Q_LOGGING_CATEGORY(dcCoap, "CoAP")

/*! Constructs a coap access manager with the given \a parent and \a port. */
CoapNetworkAccessManager::CoapNetworkAccessManager(QObject *parent, const quint16 &port,const QString &IP) :
    QObject(parent),
    m_port(port)
{
    m_socket = new QUdpSocket(this);

    // if (!m_socket->bind(QHostAddress::Any, 0, QAbstractSocket::ShareAddress))
   qDebug()<<"Coap IP---------------"<<IP<<endl;
   if (!m_socket->bind(QHostAddress(IP),0, QAbstractSocket::ShareAddress))
   {
            qDebug()<<"Assigned Port No:" <<  m_socket->peerPort() <<"\n";
            qCWarning(dcCoap) << "Could not bind to port" << m_port << m_socket->errorString();

   }
    qDebug()<<"Assigned Port No1:" <<  m_socket->peerPort() <<"\n";
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
  }

/*! Performs a ping request to the CoAP server specified in the given \a request.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::ping(const CoapRequest &request)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Empty);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

/*! Performs a GET request to the CoAP server specified in the given \a request.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::get(const CoapRequest &request)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Get);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

/*! Performs a PUT request to the CoAP server specified in the given \a request and \a data.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::put(const CoapRequest &request, const QByteArray &data)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Put);
    reply->setRequestPayload(data);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

/*! Performs a POST request to the CoAP server specified in the given \a request and \a data.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::post(const CoapRequest &request, const QByteArray &data)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Post);
    reply->setRequestPayload(data);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

/*! Performs a DELETE request to the CoAP server specified in the given \a request.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::deleteResource(const CoapRequest &request)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Delete);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

/*! Enables notifications (observing) on the CoAP server for the resource specified in the
 *  given \a request.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::enableResourceNotifications(const CoapRequest &request)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Get);
    reply->setObservation(true);
    reply->setObservationEnable(true);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

/*! Disables notifications (observing) on the CoAP server for the resource specified in the
 *  given \a request.
 *  Returns a \l{CoapReply} to match the response with the request. */
CoapReply *CoapNetworkAccessManager::disableNotifications(const CoapRequest &request)
{
    CoapReply *reply = new CoapReply(request, this);
    reply->setRequestMethod(CoapPdu::Get);
    reply->setMessageType(CoapPdu::Reset);
    reply->setObservation(true);
    reply->setObservationEnable(false);

    connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
    connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

    lookupHost(reply);

    return reply;
}

void CoapNetworkAccessManager::lookupHost(CoapReply *reply)
{
    int lookupId = QHostInfo::lookupHost(reply->request().url().host(), this, SLOT(onHostLookupFinished(QHostInfo)));
    m_runningHostLookups.insert(lookupId, reply);
}

void CoapNetworkAccessManager::sendRequest(CoapReply *reply, const bool &lookedUp)
{
    CoapPdu pdu;
    pdu.setMessageType(reply->request().messageType());
    pdu.setStatusCode(reply->requestMethod());
    pdu.createMessageId();
    pdu.createToken();

    // Add the options in correct order
    // Option number 3
    if (lookedUp)
        pdu.addOption(CoapOption::UriHost, reply->request().url().host().toUtf8());

    if (reply->observation() && reply->requestMethod() == CoapPdu::Get) {
        if (reply->observationEnable()) {
            // Option number 6
            pdu.addOption(CoapOption::Observe, 0);
        } else {
            // if disable, we should use the sam token as the notifications
            CoapTarget *target = findTarget(reply);
            foreach (const CoapObserveResource &resource, target->observationResources()) {
                if (resource.url() == reply->request().url()) {
                    pdu.setToken(resource.token());
                }
            }
            // Option number 6
            pdu.addOption(CoapOption::Observe, QByteArray::number(1));
        }
    }

    // Option number 7
    if (reply->port() != 5683)
        pdu.addOption(CoapOption::UriPort, QByteArray::number(reply->request().url().port()));

    QStringList urlTokens = reply->request().url().path().split("/");
    urlTokens.removeAll(QString());

    // Option number 11
    foreach (const QString &token, urlTokens)
        pdu.addOption(CoapOption::UriPath, token.toUtf8());

    // Option number 12
    if (reply->requestMethod() == CoapPdu::Post || reply->requestMethod() == CoapPdu::Put) {
        pdu.addOption(CoapOption::ContentFormat, QByteArray(1, ((quint8)reply->request().contentType())));

        // check if we have to block the payload
        if (reply->requestPayload().size() > 64) {
            pdu.addOption(CoapOption::Block1, CoapPduBlock::createBlock(0, 2, true));
            pdu.setPayload(reply->requestPayload().mid(0, 64));
        } else {
            pdu.setPayload(reply->requestPayload());
        }
    }

    // Option number 15
    if (reply->request().url().hasQuery())
        pdu.addOption(CoapOption::UriQuery, reply->request().url().query().toUtf8());

    // Option number 23
   if (reply->requestMethod() == CoapPdu::Get)
        pdu.addOption(CoapOption::Block2, CoapPduBlock::createBlock(0));

    QByteArray pduData = pdu.pack();
    reply->setRequestData(pduData);
    reply->setMessageId(pdu.messageId());
    reply->setMessageToken(pdu.token());
    reply->m_lockedUp = lookedUp;
    reply->m_timer->start();

    qCDebug(dcCoap) << "--->" << reply->hostAddress() << pdu;

    // send the data
    if (reply->request().messageType() == CoapPdu::NonConfirmable) {
        sendData(reply->hostAddress(), reply->port(), pduData);
        reply->setFinished();
    } else {
        sendData(reply->hostAddress(), reply->port(), pduData);
    }
}

void CoapNetworkAccessManager::sendData(const QHostAddress &hostAddress, const quint16 &port, const QByteArray &data)
{
    m_socket->writeDatagram(data, hostAddress, port);
}

void CoapNetworkAccessManager::sendCoapPdu(const QHostAddress &hostAddress, const quint16 &port, const CoapPdu &pdu)
{
    m_socket->writeDatagram(pdu.pack(), hostAddress, port);
}

void CoapNetworkAccessManager::processResponse(const CoapPdu &pdu, const QHostAddress &address, const quint16 &port)
{
    CoapTarget *target = findTarget(address);
    if (!target) {
        qCDebug(dcCoap) << "Got message without request or registered observe resource from" << address << endl << "<---" << pdu;
//        CoapPdu responsePdu;
//        responsePdu.setMessageType(CoapPdu::Reset);
//        responsePdu.setMessageId(pdu.messageId());
//        responsePdu.setToken(pdu.token());
//        qCDebug(dcCoap) << "--->" << responsePdu;
//        sendCoapPdu(address, port, responsePdu);
        return;
    }

    // Check if this is the current reply for this target
    if (target->currentReply()) {
        CoapReply *reply = target->currentReply();
        qCDebug(dcCoap) << "<---" << address << pdu;

        // Check if PDU is valid
        if (!pdu.isValid()) {
            qCWarning(dcCoap) << "Received invalid PDU.";
            reply->setError(CoapReply::InvalidPduError);
            reply->setFinished();
            return;
        }

        // Check if the message is a response to a reply (message id based check)
        if (reply->messageId() == pdu.messageId()) {
            processIdBasedResponse(target, reply, pdu);
            return;
        }

        // Check if this is a disable notifications Response
        if (reply->observation() && !reply->observationEnable()) {
            reply->setMessageType(pdu.messageType());
            reply->setStatusCode(pdu.statusCode());
            reply->setContentType(pdu.contentType());
            reply->appendPayloadData(pdu.payload());
            reply->setFinished();
            return;
        }
    }

    // Check if we know the message by token (async response)
    if (target->hasAsyncReply(pdu.token())) {
        qCDebug(dcCoap) << "<---" << address << pdu;

        CoapReply *reply = target->asyncReply(pdu.token());
        // Separate Response received
        CoapPdu responsePdu;
        responsePdu.setMessageType(CoapPdu::Acknowledgement);
        responsePdu.setStatusCode(CoapPdu::Empty);
        responsePdu.setMessageId(pdu.messageId());
        qCDebug(dcCoap) << "--->" << reply->hostAddress() << responsePdu;
        sendCoapPdu(reply->hostAddress(), reply->port(), responsePdu);

        reply->setStatusCode(pdu.statusCode());
        reply->setContentType(pdu.contentType());
        reply->appendPayloadData(pdu.payload());
        reply->setFinished();
        return;
    }

    // Check if this is a blocked notification reply
    if (target->hasRunningObservationReply()) {
        processBlock2Notification(target, pdu);
        return;
    }

    // check if this is a notification
    if (target->hasObservationResource(pdu.token())) {
        processNotification(target, pdu, address, port);
        return;
    }

}

void CoapNetworkAccessManager::processIdBasedResponse(CoapTarget *target, CoapReply *reply, const CoapPdu &pdu)
{
    // check if this is an empty ACK response (which indicates a separated response)
    if (pdu.statusCode() == CoapPdu::Empty && pdu.messageType() == CoapPdu::Acknowledgement) {
        qCDebug(dcCoap) << "Got empty ACK. Data will be sent separated.";
        reply->m_timer->stop();
        target->clearCurrentReply();
        target->addAsyncReply(reply);
        return;
    }

    // check if this is a Block1 pdu
    if (pdu.messageType() == CoapPdu::Acknowledgement && pdu.hasOption(CoapOption::Block1)) {
        processBlock1Response(reply, pdu);
        return;
    }

    // check if this is a Block2 pdu
    if (pdu.messageType() == CoapPdu::Acknowledgement && pdu.hasOption(CoapOption::Block2)) {
        processBlock2Response(reply, pdu);
        return;
    }

    // Piggybacked response
    reply->setMessageType(pdu.messageType());
    reply->setStatusCode(pdu.statusCode());
    reply->setContentType(pdu.contentType());
    reply->appendPayloadData(pdu.payload());
    reply->setFinished();
}

void CoapNetworkAccessManager::processBlock1Response(CoapReply *reply, const CoapPdu &pdu)
{
    qCDebug(dcCoap) << QString("Sent successfully block #%1").arg(pdu.block().blockNumber());

    // create next block
    int index = (pdu.block().blockNumber() * 64) + 64;
    QByteArray newBlockData = reply->requestPayload().mid(index, 64);
    bool moreFlag = true;

    // check if this was the last block
    if (newBlockData.isEmpty()) {
        reply->setStatusCode(pdu.statusCode());
        reply->setContentType(pdu.contentType());
        reply->setFinished();
        return;
    }

    // check if this is the last block or there will be no next block
    if (newBlockData.size() < 64 || (index + 64) == reply->requestPayload().size())
        moreFlag = false;

    CoapPdu nextBlockRequest;
    nextBlockRequest.setContentType(reply->request().contentType());
    nextBlockRequest.setMessageType(reply->request().messageType());
    nextBlockRequest.setStatusCode(reply->requestMethod());
    nextBlockRequest.setMessageId(pdu.messageId() + 1);
    nextBlockRequest.setToken(pdu.token());

    // Add the options in correct order
    // Option number 3
    if (reply->m_lockedUp)
        nextBlockRequest.addOption(CoapOption::UriHost, reply->request().url().host().toUtf8());

    // Option number 7
    if (reply->port() != 5683)
        nextBlockRequest.addOption(CoapOption::UriPort, QByteArray::number(reply->request().url().port()));

    QStringList urlTokens = reply->request().url().path().split("/");
    urlTokens.removeAll(QString());

    // Option number 11
    foreach (const QString &token, urlTokens)
        nextBlockRequest.addOption(CoapOption::UriPath, token.toUtf8());

    // Option number 15
    if (reply->request().url().hasQuery())
        nextBlockRequest.addOption(CoapOption::UriQuery, reply->request().url().query().toUtf8());

    // Option number 27
    nextBlockRequest.addOption(CoapOption::Block1, CoapPduBlock::createBlock(pdu.block().blockNumber() + 1, 2, moreFlag));

    nextBlockRequest.setPayload(newBlockData);

    QByteArray pduData = nextBlockRequest.pack();
    reply->setRequestData(pduData);
    reply->m_timer->start();
    reply->m_retransmissions = 1;

    reply->setMessageId(nextBlockRequest.messageId());

    qCDebug(dcCoap) << "--->" << reply->hostAddress() << nextBlockRequest;
    sendData(reply->hostAddress(), reply->port(), pduData);
}

void CoapNetworkAccessManager::processBlock2Response(CoapReply *reply, const CoapPdu &pdu)
{
    reply->appendPayloadData(pdu.payload());

    // check if this was the last block
    if (!pdu.block().moreFlag()) {
        reply->setMessageType(pdu.messageType());
        reply->setStatusCode(pdu.statusCode());
        reply->setContentType(pdu.contentType());
        reply->setFinished();
        return;
    }

    CoapPdu nextBlockRequest;
    nextBlockRequest.setContentType(reply->request().contentType());
    nextBlockRequest.setMessageType(reply->request().messageType());
    nextBlockRequest.setStatusCode(reply->requestMethod());
    nextBlockRequest.setMessageId(pdu.messageId() + 1);
    nextBlockRequest.setToken(pdu.token());

    // Add the options in correct order
    // Option number 3
    if (reply->m_lockedUp)
        nextBlockRequest.addOption(CoapOption::UriHost, reply->request().url().host().toUtf8());

    // Option number 7
    if (reply->port() != 5683)
        nextBlockRequest.addOption(CoapOption::UriPort, QByteArray::number(reply->request().url().port()));

    QStringList urlTokens = reply->request().url().path().split("/");
    urlTokens.removeAll(QString());

    // Option number 11
    foreach (const QString &token, urlTokens)
        nextBlockRequest.addOption(CoapOption::UriPath, token.toUtf8());

    // Option number 15
    if (reply->request().url().hasQuery())
        nextBlockRequest.addOption(CoapOption::UriQuery, reply->request().url().query().toUtf8());

    // Option number 23
    nextBlockRequest.addOption(CoapOption::Block2, CoapPduBlock::createBlock(pdu.block().blockNumber() + 1, 2, false));

    QByteArray pduData = nextBlockRequest.pack();
    reply->setRequestData(pduData);
    reply->m_timer->start();

    reply->setMessageId(nextBlockRequest.messageId());

    qCDebug(dcCoap) << "--->" << reply->hostAddress() << nextBlockRequest;
    sendData(reply->hostAddress(), reply->port(), pduData);
}

void CoapNetworkAccessManager::processNotification(CoapTarget *target, const CoapPdu &pdu, const QHostAddress &address, const quint16 &port)
{
    qCDebug(dcCoap) << "<--- Notification" << address << pdu;

    // Check if this target has an observation resource for this token
    if (!target->hasObservationResource(pdu.token())) {
        qCWarning(dcCoap()) << "No observe resource for this notification.";
        return;
    }

    CoapObserveResource resource = target->getObservationResource(pdu.token());

    // check if it is a blockwise notification
    if (pdu.hasOption(CoapOption::Block2)) {

        // First part of the blocked notification
        // respond with ACK
        CoapPdu responsePdu;
        responsePdu.setMessageType(CoapPdu::Acknowledgement);
        responsePdu.setStatusCode(CoapPdu::Empty);
        responsePdu.setMessageId(pdu.messageId());
        responsePdu.setToken(pdu.token());

        qCDebug(dcCoap) << "---> Notification:" << address << responsePdu;
        sendCoapPdu(address, port, responsePdu);

        // create reply for blockwise transfere
        if (target->hasRunningObservationReply()) {
            CoapReply *oldReply = target->currentObservationReply();
            oldReply->deleteLater();
            target->removeReply(oldReply);
        }

        CoapReply *reply = new CoapReply(CoapRequest(resource.url()), this);
        reply->setRequestMethod(CoapPdu::Get);
        reply->appendPayloadData(pdu.payload());

        // Lets store the observation number
        int notificationNumber = 0;
        foreach (const CoapOption &option, pdu.options()) {
            if (option.option() == CoapOption::Observe) {
                notificationNumber = option.data().toHex().toInt(0, 16);
            }
        }

        target->setCurrentObservationReply(reply);
        m_observeBlockwise.insert(reply, notificationNumber);

        connect(reply, &CoapReply::timeout, this, &CoapNetworkAccessManager::onReplyTimeout);
        connect(reply, &CoapReply::finished, this, &CoapNetworkAccessManager::onReplyFinished);

        CoapPdu pdu;
        pdu.setMessageType(reply->request().messageType());
        pdu.setStatusCode(reply->requestMethod());
        pdu.createMessageId();
        pdu.createToken();

        // Add the options in correct order
        // Option number 3
        pdu.addOption(CoapOption::UriHost, reply->request().url().host().toUtf8());

        QStringList urlTokens = reply->request().url().path().split("/");
        urlTokens.removeAll(QString());

        // Option number 11
        foreach (const QString &token, urlTokens)
            pdu.addOption(CoapOption::UriPath, token.toUtf8());

        // Option number 15
        if (reply->request().url().hasQuery())
            pdu.addOption(CoapOption::UriQuery, reply->request().url().query().toUtf8());

        // Option number 23
        pdu.addOption(CoapOption::Block2, CoapPduBlock::createBlock(1, 2, true));

        QByteArray pduData = pdu.pack();
        reply->setRequestData(pduData);
        reply->setHostAddress(address);
        reply->setPort(port);
        reply->m_timer->start();

        qCDebug(dcCoap) << "---> Notification" << address << pdu;
        sendData(address, port, pduData);

    } else {

        // Respond with ACK
        CoapPdu responsePdu;
        responsePdu.setMessageType(CoapPdu::Acknowledgement);
        responsePdu.setStatusCode(CoapPdu::Empty);
        responsePdu.setMessageId(pdu.messageId());
        responsePdu.setToken(pdu.token());

        qCDebug(dcCoap) << "---> Notification" << address << responsePdu;
        sendCoapPdu(address, port, responsePdu);

        // Get notification number
        int notificationNumber = 0;
        foreach (const CoapOption &option, pdu.options()) {
            if (option.option() == CoapOption::Observe) {
                notificationNumber = option.data().toHex().toInt(0, 16);
            }
        }
        emit notificationReceived(resource, notificationNumber, pdu.payload());
    }
}

void CoapNetworkAccessManager::processBlock2Notification(CoapTarget *target, const CoapPdu &pdu)
{
    CoapObserveResource resource = target->getObservationResource(pdu.token());
    CoapReply *reply = target->currentObservationReply();

    // Respond Block2

    // Check if this was the last block
    if (!pdu.block().moreFlag()) {
        // respond with ACK
        CoapPdu responsePdu;
        responsePdu.setMessageType(CoapPdu::Acknowledgement);
        responsePdu.setStatusCode(CoapPdu::Empty);
        responsePdu.setMessageId(pdu.messageId());
        responsePdu.setToken(pdu.token());
        qCDebug(dcCoap) << "---> Notification" << reply->hostAddress() << responsePdu;
        sendCoapPdu(reply->hostAddress(), reply->port(), responsePdu);

        reply->appendPayloadData(pdu.payload());

        emit notificationReceived(resource, m_observeBlockwise.take(reply), reply->payload());

        // Clean up
        target->removeReply(reply);
        reply->deleteLater();
        return;
    }

    // Not the last block
    reply->appendPayloadData(pdu.payload());

    // Request the next block data
    CoapPdu nextBlockRequest;
    nextBlockRequest.setContentType(reply->request().contentType());
    nextBlockRequest.setMessageType(reply->request().messageType());
    nextBlockRequest.setStatusCode(reply->requestMethod());
    nextBlockRequest.setMessageId(pdu.messageId() + 1);
    nextBlockRequest.setToken(pdu.token());

    // Add the options in correct order
    // Option number 3
    if (reply->m_lockedUp)
        nextBlockRequest.addOption(CoapOption::UriHost, reply->request().url().host().toUtf8());

    // Option number 7
    if (reply->port() != 5683)
        nextBlockRequest.addOption(CoapOption::UriPort, QByteArray::number(reply->request().url().port()));

    QStringList urlTokens = reply->request().url().path().split("/");
    urlTokens.removeAll(QString());

    // Option number 11
    foreach (const QString &token, urlTokens)
        nextBlockRequest.addOption(CoapOption::UriPath, token.toUtf8());

    // Option number 15
    if (reply->request().url().hasQuery())
        nextBlockRequest.addOption(CoapOption::UriQuery, reply->request().url().query().toUtf8());

    // Option number 23
    nextBlockRequest.addOption(CoapOption::Block2, CoapPduBlock::createBlock(pdu.block().blockNumber() + 1, 2, false));

    QByteArray pduData = nextBlockRequest.pack();
    reply->setRequestData(pduData);
    reply->m_timer->start();

    reply->setMessageId(nextBlockRequest.messageId());

    qCDebug(dcCoap) << "---> Notification" << reply->hostAddress() << nextBlockRequest;
    sendData(reply->hostAddress(), reply->port(), pduData);
}

CoapTarget *CoapNetworkAccessManager::findTarget(const QHostAddress &address)
{
    foreach (CoapTarget *target, m_coapTargets) {
        if (QHostAddress(target->address().toIPv6Address()) == QHostAddress(address.toIPv6Address()))
            return target;
    }
    return NULL;
}

CoapTarget *CoapNetworkAccessManager::findTarget(CoapReply *reply)
{
    CoapTarget *target = findTarget(reply->hostAddress());
    if (target && target->hasReply(reply))
        return target;

    return NULL;
}

void CoapNetworkAccessManager::onHostLookupFinished(const QHostInfo &hostInfo)
{
    CoapReply *reply = m_runningHostLookups.take(hostInfo.lookupId());

    // Check here (not earlier) the url scheme
    // to make the reply always async, never sync
    if (reply->request().url().scheme() != "coap") {
        reply->setError(CoapReply::InvalidUrlSchemeError);
        reply->setFinished();
        return;
    }

    // Check if host lookup was successfull
    if (hostInfo.error() != QHostInfo::NoError) {
        qCDebug(dcCoap) << "Host lookup for" << reply->request().url().host() << "failed:" << hostInfo.errorString();
        reply->setError(CoapReply::HostNotFoundError);
        reply->setFinished();
        return;
    }

    QHostAddress hostAddress(hostInfo.addresses().first());
    reply->setHostAddress(hostAddress);
    reply->setPort(reply->request().url().port(5683));

    // Get the target for this host
    CoapTarget *target = findTarget(hostAddress);
    if (!target) {
        // Create the target for this host address
        target = new CoapTarget(hostAddress, this);
        m_coapTargets.append(target);
    }

    // Check if a reply is still running for this target
    if (target->hasRunningReply()) {
        target->enqueueReply(reply);
        return;
    } else {
        // set the current reply of target
        target->setCurrentReply(reply);
    }

    // check if the url had to be looked up
    if (reply->request().url().host() != hostAddress.toString()) {
        qCDebug(dcCoap) << reply->request().url().host() << " -> " << hostAddress;
        sendRequest(reply, true);
    } else {
        sendRequest(reply);
    }
}

void CoapNetworkAccessManager::onSocketError(QAbstractSocket::SocketError error)
{
    qCWarning(dcCoap()) << "Socket error" << error << m_socket->errorString();
    m_socket->close();
}

void CoapNetworkAccessManager::onReadyRead()
{
    QHostAddress hostAddress;
    QByteArray data;
    quint16 port;

    while (m_socket->hasPendingDatagrams()) {
        data.resize(m_socket->pendingDatagramSize());
        m_socket->readDatagram(data.data(), data.size(), &hostAddress, &port);
    }

    processResponse(CoapPdu(data), hostAddress, port);


//    if (hostAddress.protocol() == QAbstractSocket::IPv4Protocol) {
//        processResponse(CoapPdu(data), QHostAddress(hostAddress.toIPv4Address()), port);
//    } else {
//        processResponse(CoapPdu(data), QHostAddress(hostAddress.toIPv6Address()), port);
//    }
}

void CoapNetworkAccessManager::onReplyTimeout()
{
    CoapReply *reply = qobject_cast<CoapReply *>(sender());
    if (reply->m_retransmissions < 5)
        qCDebug(dcCoap) << QString("Reply timeout: resending message %1/4").arg(reply->m_retransmissions);

    reply->resend();
    qCDebug(dcCoap()) << "--->" << reply->hostAddress() << CoapPdu(reply->requestData());
    m_socket->writeDatagram(reply->requestData(), reply->hostAddress(), reply->port());
}

void CoapNetworkAccessManager::onReplyFinished()
{
    CoapReply *reply = qobject_cast<CoapReply *>(sender());
    CoapTarget *target = findTarget(reply);

    // If this reply has no target, something went wrong before sending
    if (!target) {
        emit replyFinished(reply);
        return;
    }

    // Check if this is the current running reply
    if (target->currentReply().data() == reply) {
        target->removeReply(reply);

        // Check if this was an enable/disable reply
        if (reply->observation()) {
            // Check if enable/disable was successfull
            if (reply->statusCode() == CoapPdu::Content) {
                if (reply->observationEnable()) {
                    target->addObservationResource(CoapObserveResource(reply->request().url(), reply->messageToken()));
                } else {
                    target->removeObservationResource(reply->messageToken());
                }
            }
        }

        // Start the next request of the queue
        if (!target->queue().isEmpty()) {
            CoapReply *newReply = target->dequeueReply();
            target->setCurrentReply(newReply);
            lookupHost(newReply);
        }
    }

    // Check if this was an async reply
    if (target->asyncReplies().contains(reply)) {
        target->removeReply(reply);

        // Start the next request of the queue
        if (!target->queue().isEmpty() && !target->hasRunningReply()) {
            CoapReply *newReply = target->dequeueReply();
            target->setCurrentReply(newReply);
            lookupHost(newReply);
        }
    }

    if (target->hasRunningObservationReply() && target->currentObservationReply() == reply) {
        target->removeReply(reply);
        reply->deleteLater();
        qCWarning(dcCoap) << "Notification reply (blocked) finished with error" << reply->errorString();
        return;
    }

    // Remove the whole reply from this targert, it is finished
    target->removeReply(reply);

    emit replyFinished(reply);

    // Remove the target if this was the last reply from it
    if (target->isEmpty()) {
        m_coapTargets.removeAll(target);
        m_socket->close();
        target->deleteLater();
    }
}
