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

#ifndef COAPNETWORKACCESSMANAGER_H
#define COAPNETWORKACCESSMANAGER_H

#include <QObject>
#include <QHostInfo>
#include <QUdpSocket>
#include <QHostAddress>
#include <QLoggingCategory>
#include <QPointer>
#include <QQueue>

#include "coaprequest.h"
#include "coapreply.h"
#include "coaptarget.h"
#include "coapobserveresource.h"

/* Information about CoAP
 *
 * The Constrained Application Protocol (CoAP)         : https://tools.ietf.org/html/rfc7252
 * Blockwise transfers in CoAP                         : https://tools.ietf.org/html/draft-ietf-core-block-18
 * Constrained RESTful Environments (CoRE) Link Format : http://tools.ietf.org/html/rfc6690
 * Observing Resources in CoAP                         : https://tools.ietf.org/html/rfc7641
 *
 */

Q_DECLARE_LOGGING_CATEGORY(dcCoap)

class CoapNetworkAccessManager : public QObject
{
    Q_OBJECT
public:
    explicit CoapNetworkAccessManager(QObject *parent = 0, const quint16 &port = 5683,const QString &IP="");

    // Methods
    CoapReply *ping(const CoapRequest &request);
    CoapReply *get(const CoapRequest &request);
    CoapReply *put(const CoapRequest &request, const QByteArray &data = QByteArray());
    CoapReply *post(const CoapRequest &request, const QByteArray &data = QByteArray());
    CoapReply *deleteResource(const CoapRequest &request);

    // Notifications for observable resources
    CoapReply *enableResourceNotifications(const CoapRequest &request);
    CoapReply *disableNotifications(const CoapRequest &request);

private:
    QUdpSocket *m_socket;
    quint16 m_port;

    QList<CoapTarget *> m_coapTargets;
    QHash<int, CoapReply *> m_runningHostLookups; // lookupId | reply
    QHash<CoapReply *, int> m_observeBlockwise; // reply | observe nr.

    void lookupHost(CoapReply *reply);
    void sendRequest(CoapReply *reply, const bool &lookedUp = false);
    void sendData(const QHostAddress &hostAddress, const quint16 &port, const QByteArray &data);
    void sendCoapPdu(const QHostAddress &address, const quint16 &port, const CoapPdu &pdu);

    // Process response
    void processResponse(const CoapPdu &pdu, const QHostAddress &address, const quint16 &port);
    void processIdBasedResponse(CoapTarget *target, CoapReply *reply, const CoapPdu &pdu);

    // Process blocked response
    void processBlock1Response(CoapReply *reply, const CoapPdu &pdu);
    void processBlock2Response(CoapReply *reply, const CoapPdu &pdu);

    // Process notifications
    void processNotification(CoapTarget *target, const CoapPdu &pdu, const QHostAddress &address, const quint16 &port);
    void processBlock2Notification(CoapTarget *target, const CoapPdu &pdu);

    // Search methods
    CoapTarget *findTarget(const QHostAddress &address);
    CoapTarget *findTarget(CoapReply *reply);

signals:
    void replyFinished(CoapReply *reply);
    void notificationReceived(const CoapObserveResource &resource, const int &notificationNumber, const QByteArray &payload);

private slots:
    void onHostLookupFinished(const QHostInfo &hostInfo);
    void onSocketError(QAbstractSocket::SocketError error);
    void onReadyRead();
    void onReplyTimeout();
    void onReplyFinished();
};

#endif // COAPNETWORKACCESSMANAGER_H
