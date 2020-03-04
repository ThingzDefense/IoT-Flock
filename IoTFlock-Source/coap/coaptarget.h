/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2016 Simon Stuerz <simon.stuerz@guh.guru>           *
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

#ifndef COAPTARGET_H
#define COAPTARGET_H

#include <QObject>
#include <QPointer>
#include <QQueue>

#include "coapreply.h"
#include "coapobserveresource.h"

class CoapTarget : public QObject
{
    Q_OBJECT
public:
    explicit CoapTarget(const QHostAddress &address, QObject *parent = 0);

    QHostAddress address() const;

    QPointer<CoapReply> currentObservationReply() const;
    void setCurrentObservationReply(CoapReply *reply);

    QList<CoapObserveResource> observationResources() const;
    void addObservationResource(const CoapObserveResource &observationResource);
    void removeObservationResource(const QByteArray &token);
    CoapObserveResource getObservationResource(const QByteArray &token);

    QPointer<CoapReply> currentReply() const;
    void setCurrentReply(CoapReply *reply);
    void clearCurrentReply();

    QList<CoapReply *> asyncReplies() const;
    QPointer<CoapReply> asyncReply(const QByteArray &token) const;
    void addAsyncReply(CoapReply *reply);

    QQueue<CoapReply *> queue() const;
    void enqueueReply(CoapReply *reply);
    CoapReply *dequeueReply();

    void removeReply(CoapReply *reply);

    bool isEmpty() const;
    bool hasRunningReply() const;
    bool hasRunningObservationReply() const;
    bool hasAsyncReply(const QByteArray &token);
    bool hasObservationResource(const QByteArray &token);
    bool hasReply(CoapReply *reply) const;

private:
    QHostAddress m_address;
    QPointer<CoapReply> m_currentReply;
    QList<CoapReply *> m_asyncReplies;
    QPointer<CoapReply> m_currentObservationReply;
    QList<CoapObserveResource> m_observationResources;
    QQueue<CoapReply *> m_replyQueue;

};

#endif // COAPTARGET_H
