/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2016 Simon Stuerz <simon.stuerz@guh.guru>                *
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

#include "coaptarget.h"

CoapTarget::CoapTarget(const QHostAddress &address, QObject *parent) :
    QObject(parent),
    m_address(address)
{

}

QHostAddress CoapTarget::address() const
{
    return m_address;
}

QPointer<CoapReply> CoapTarget::currentObservationReply() const
{
    return m_currentObservationReply;
}

void CoapTarget::setCurrentObservationReply(CoapReply *reply)
{
    m_currentObservationReply = reply;
}

QList<CoapObserveResource> CoapTarget::observationResources() const
{
    return m_observationResources;
}

void CoapTarget::addObservationResource(const CoapObserveResource &observationResource)
{
    m_observationResources.append(observationResource);
}

void CoapTarget::removeObservationResource(const QByteArray &token)
{
    foreach (const CoapObserveResource &resource, m_observationResources) {
        if (resource.token() == token)
            m_observationResources.removeAll(resource);
    }
}

CoapObserveResource CoapTarget::getObservationResource(const QByteArray &token)
{
    foreach (const CoapObserveResource &resource, m_observationResources) {
        if (resource.token() == token)
            return resource;
    }
    return CoapObserveResource();
}

QPointer<CoapReply> CoapTarget::currentReply() const
{
    return m_currentReply;
}

void CoapTarget::setCurrentReply(CoapReply *reply)
{
    m_currentReply = QPointer<CoapReply>(reply);
}

void CoapTarget::clearCurrentReply()
{
    m_currentReply.clear();
}

QList<CoapReply *> CoapTarget::asyncReplies() const
{
    return m_asyncReplies;
}

QPointer<CoapReply> CoapTarget::asyncReply(const QByteArray &token) const
{
    foreach (CoapReply *reply, m_asyncReplies) {
        if (reply->messageToken() == token)
            return reply;
    }
    return NULL;
}

void CoapTarget::addAsyncReply(CoapReply *reply)
{
    m_asyncReplies.append(reply);
}

QQueue<CoapReply *> CoapTarget::queue() const
{
    return m_replyQueue;
}

void CoapTarget::enqueueReply(CoapReply *reply)
{
    m_replyQueue.enqueue(reply);
}

CoapReply *CoapTarget::dequeueReply()
{
    return m_replyQueue.dequeue();
}

void CoapTarget::removeReply(CoapReply *reply)
{
    if (m_currentReply.data() == reply)
        m_currentReply.clear();

    if (m_currentObservationReply.data() == reply)
        m_currentObservationReply.clear();

    if (m_replyQueue.contains(reply))
        m_replyQueue.removeAll(reply);

    if (m_asyncReplies.contains(reply))
        m_asyncReplies.removeAll(reply);

}

bool CoapTarget::isEmpty() const
{
    return m_currentReply.isNull() &&
            m_currentObservationReply.isNull() &&
            m_observationResources.isEmpty() &&
            m_replyQueue.isEmpty() &&
            m_asyncReplies.isEmpty();
}

bool CoapTarget::hasRunningReply() const
{
    return !m_currentReply.isNull() && m_currentReply->isRunning();
}

bool CoapTarget::hasRunningObservationReply() const
{
    return !m_currentObservationReply.isNull() && m_currentObservationReply->isRunning();
}

bool CoapTarget::hasAsyncReply(const QByteArray &token)
{
    foreach (CoapReply *reply, m_asyncReplies) {
        if (reply->messageToken() == token)
            return true;
    }
    return false;
}

bool CoapTarget::hasObservationResource(const QByteArray &token)
{
    foreach (const CoapObserveResource &resource, m_observationResources) {
        if (resource.token() == token)
            return true;
    }
    return false;
}

bool CoapTarget::hasReply(CoapReply *reply) const
{
    if (m_currentReply && m_currentReply.data() == reply)
        return true;

    if (m_replyQueue.contains(reply))
        return true;

    if (m_asyncReplies.contains(reply))
        return true;

    if (m_currentObservationReply && m_currentObservationReply.data() == reply)
        return true;

    return false;
}


