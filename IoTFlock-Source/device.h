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

#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QMutex>
#include "objdevice.h"
#include <mqtt/qmqttclient.h>
#include<objglobal.h>
#include<qthread.h>
#include<coap/coapnetworkaccessmanager.h>
#include<qmessagebox.h>
class Device : public QObject
{
    Q_OBJECT
public:
    //Worker(QObject *parent,objDevice _objDevice);
    Device(objDevice __objDevice);
    Device();
    void RunTimer();
    void RunAttackTimer(int interval);
    QString CVE10523 ="CVE-2016-10523 MQTT", CVE9877 ="CVE-2016-9877 MQTT";
    QString CVE1684 ="CVE-2018-1684 MQTT", CVE17614 ="CVE-201-17614 MQTT";

    QString MQTT_Publish_Message_Flood = "MQTT Publish Flood";
    QString MQTT_Authentication_ByPass      = "MQTT Authentication Bypass";
    QString MQTT_Crafted_Packet = "MQTT Crafted Packet";
    QString COAP_PUT_Flood = "MQTT PUT Flood";
    QString COAP_Crated_Payload = "MQTT Crafted Packet";
    QString COAP_Replay_Attack = "MQTT PUT Flood";

QMessageBox msgBox;
    void MessageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void brokerDisconnected();
    QString WriteInHomeLogs(QString msg);
    void Connected();
    void Disconnected();
    void SetDevice(objDevice objDevice);
    void SetInitialData();
    objDevice GetDevice();
    //QMqttClient  *m_client =  new QMqttClient(this);
    QMqttClient *m_client;
    QTimer *timer;
    QTimer *attackTimer;
    objDevice _objDevice;
    bool isTimerActive = false;
    bool isAttackTimerActive = false;
    void run();

    int GenerateRandomNumber(int from ,int to);
    bool isSendTime(QString lastSentTime,QString timeProfileType,int interval);
    QString GetData(bool isStartText,QString startText,bool isRandom, int from, int to, bool isEndText, QString endText);

private:
    int workerID = 0;
    objGlobal _objGlobal;
    bool isConnected =false;
    bool _abort;
    bool _working;
    QMutex mutex;
signals:
    //This signal is emitted when the Worker request to Work
    void workRequested();
    //This signal is emitted when counted value is changed (every sec)
    void valueChanged(const QString &value);
    //This signal is emitted when process is finished (either by counting 60 sec or being aborted)
    void finished();
public slots:
    void doWork();
    void TimerTick();
     void TimerTickAttack();
    void updateStateChange();
    void onCoapReplyFinished(CoapReply *reply);
    void onCoapNotificationSignalReceived(CoapObserveResource,int,QByteArray);
};
#endif // DEVICE_H
