/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2019 IRIL Lab, KICS, UET Lahore <iril@kics.edu.pk>       *
 *                                                                         *
 *  This file is part of IRIL Advanced Data Generator.                     *                                         *
 *                                                                         *
 *  IRIL Advanced Data Generator is free software: you can redistribute    *
 *  it and/or modify it under the terms of the GNU General Public License  *
 *  as published by the Free Software Foundation, version 3 of the License.*
 *                                                                         *
 *                                                                         *
 *  IRIL Advanced Data Generator is distributed in the hope that it will   *
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty *
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the        *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with IRIL Advanced Data Generator.                               *
 *  If not, see <http://www.gnu.org/licenses/>.                            *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef OBJDEVICE_H
#define OBJDEVICE_H
#include <qstring.h>
#include <qlist.h>
//#include<objpublisher.h>
#include<objdevicesubscribedata.h>
#include<objdevicepublishdata.h>
#include<objdevicecoapdata.h>
#include<objdevicehttpdata.h>

class objDevice
{
public:
    objDevice();
    int useCaseID;
    int templateID;
    QString useCaseName;
    QString deviceName;
    QString protocol;

    QString sHostName;  //Device IP
    int IPCount;

    QString hostName;
    QString portType;
    int port;

    bool isAuthenticationRequire;
    QString userName;
    QString password;

    bool isAttackingEntity;
    QString attackType;
    QString sourceIP;
    QString targetIP;
    int targetPort;
    int interval;
    QString message;

    //   MQTT Detail
    bool isSubscriber;
    QList<objDeviceSubscribeData> lstSubTopic;

    bool isPublisher;
    QList<objDevicePublishData> lstPubTopic;

    QList<objDeviceCoapData> lstDeviceCoapData;
    QList<objDeviceHttpData> lstDeviceHttpData;

    QString lastActivity;

};

#endif // OBJDEVICE_H
