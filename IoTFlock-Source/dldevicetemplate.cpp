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
#include "dldevicetemplate.h"
#include <dal.h>
#include <QtSql>
#include<objdevice.h>
#include<dldevicesubscribedata.h>
#include<dltimeprofile.h>
#include<dldataprofile.h>
#include<dldevicepublishdata.h>
#include<dldevicecoapdata.h>
#include<dldevicehttpdata.h>

dlDeviceTemplate::dlDeviceTemplate::dlDeviceTemplate()
{

}

int dlDeviceTemplate::Insert(objDeviceTemplate _objDeviceTemplate)
{
     DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO deviceTemplate(deviceName,deviceProtocol,"
                  "IPAddress,NumofDevices,brokerIP,isRegularPort,portNO,"
                  "isAuthenticationRequire,brokerUserName,brokerPassword,coapURL,httpURL, "
                  "isAttackingEntity,attackType,sourceIP,targetIP,targetPort,interval,message) "
                  "VALUES(:deviceName,:deviceProtocol,"
                  ":IPAddress,:NumofDevices,:brokerIP,:isRegularPort,:portNO,"
                  ":isAuthenticationRequire,:brokerUserName,:brokerPassword,:coapURL,:httpURL, "
                  ":isAttackingEntity,:attackType,:sourceIP,:targetIP,:targetPort,:interval,:message) ");



    query.bindValue(":deviceName",_objDeviceTemplate.deviceName);
     query.bindValue(":deviceProtocol",_objDeviceTemplate.deviceProtocol);
   // query.bindValue(":deviceType",_objDeviceTemplate.deviceType);
    query.bindValue(":IPAddress",_objDeviceTemplate.IPAddress);
    query.bindValue(":NumofDevices",_objDeviceTemplate.NumofDevices);
   query.bindValue(":brokerIP",_objDeviceTemplate.brokerIP);
   query.bindValue(":isRegularPort",_objDeviceTemplate.isRegularPort);
   query.bindValue(":portNO",_objDeviceTemplate.portNO);
   query.bindValue(":isAuthenticationRequire",_objDeviceTemplate.isAuthenticationRequire);
   query.bindValue(":brokerUserName",_objDeviceTemplate.brokerUserName);
   query.bindValue(":brokerPassword",_objDeviceTemplate.brokerPassword);
   query.bindValue(":coapURL",_objDeviceTemplate.coapURL);
   query.bindValue(":httpURL",_objDeviceTemplate.httpURL);
   query.bindValue(":isAttackingEntity",_objDeviceTemplate.isAttackingEntity);
   query.bindValue(":attackType",_objDeviceTemplate.attackType);
   query.bindValue(":sourceIP",_objDeviceTemplate.sourceIP);
   query.bindValue(":targetIP",_objDeviceTemplate.targetIP);
   query.bindValue(":targetPort",_objDeviceTemplate.targetPort);
   query.bindValue(":interval",_objDeviceTemplate.interval);
   query.bindValue(":message",_objDeviceTemplate.message);
     return dal.Insert(query);
}
int dlDeviceTemplate::InsertForUseCase(objDeviceTemplate _objDeviceTemplate)
{
    DAL dal;
   QSqlQuery query(dal.m_db);
    query.prepare("INSERT INTO useCaseDeviceTemplate(useCaseID,deviceName,deviceProtocol,"
                  "IPAddress,NumofDevices,brokerIP,isRegularPort,portNO,"
                  "isAuthenticationRequire,brokerUserName,brokerPassword,coapURL,httpURL, "
                  "isAttackingEntity,attackType,sourceIP,targetIP,targetPort,interval,message) "
                  "VALUES(:useCaseID,:deviceName,:deviceProtocol,"
                  ":IPAddress,:NumofDevices,:brokerIP,:isRegularPort,:portNO,"
                  ":isAuthenticationRequire,:brokerUserName,:brokerPassword,:coapURL,:httpURL, "
                  ":isAttackingEntity,:attackType,:sourceIP,:targetIP,:targetPort,:interval,:message) ");


 query.bindValue(":useCaseID",_objDeviceTemplate.useCaseID);
    query.bindValue(":deviceName",_objDeviceTemplate.deviceName);
     query.bindValue(":deviceProtocol",_objDeviceTemplate.deviceProtocol);
   // query.bindValue(":deviceType",_objDeviceTemplate.deviceType);
    query.bindValue(":IPAddress",_objDeviceTemplate.IPAddress);
    query.bindValue(":NumofDevices",_objDeviceTemplate.NumofDevices);
   query.bindValue(":brokerIP",_objDeviceTemplate.brokerIP);
   query.bindValue(":isRegularPort",_objDeviceTemplate.isRegularPort);
   query.bindValue(":portNO",_objDeviceTemplate.portNO);
   query.bindValue(":isAuthenticationRequire",_objDeviceTemplate.isAuthenticationRequire);
   query.bindValue(":brokerUserName",_objDeviceTemplate.brokerUserName);
   query.bindValue(":brokerPassword",_objDeviceTemplate.brokerPassword);
   query.bindValue(":coapURL",_objDeviceTemplate.coapURL);
   query.bindValue(":httpURL",_objDeviceTemplate.httpURL);
   query.bindValue(":isAttackingEntity",_objDeviceTemplate.isAttackingEntity);
   query.bindValue(":attackType",_objDeviceTemplate.attackType);
   query.bindValue(":sourceIP",_objDeviceTemplate.sourceIP);
   query.bindValue(":targetIP",_objDeviceTemplate.targetIP);
   query.bindValue(":targetPort",_objDeviceTemplate.targetPort);
   query.bindValue(":interval",_objDeviceTemplate.interval);
   query.bindValue(":message",_objDeviceTemplate.message);

     return dal.Insert(query);
}
bool dlDeviceTemplate::UpdateDeviceTemplate( objDeviceTemplate _objDeviceTemplate)
{
    DAL dal;
   QSqlQuery query(dal.m_db);

    query.prepare("UPDATE deviceTemplate SET deviceName=:deviceName, deviceProtocol=:deviceProtocol, IPAddress=:IPAddress, "
                  "NumofDevices=:NumofDevices, brokerIP=:brokerIP, isRegularPort=:isRegularPort, portNO=:portNO,  "
                  "isAuthenticationRequire=:isAuthenticationRequire, brokerUserName=:brokerUserName,brokerPassword=:brokerPassword, coapURL=:coapURL, httpURL=:httpURL, "
                  "isAttackingEntity=:isAttackingEntity, attackType=:attackType, sourceIP=:sourceIP,targetIP=:targetIP, targetPort=:targetPort, interval=:interval, message=:message"
                  " WHERE _id =:deviceTemplateID");

    query.bindValue(":deviceTemplateID", _objDeviceTemplate._id);

    query.bindValue(":deviceName",_objDeviceTemplate.deviceName);
     query.bindValue(":deviceProtocol",_objDeviceTemplate.deviceProtocol);
    query.bindValue(":IPAddress",_objDeviceTemplate.IPAddress);
    query.bindValue(":NumofDevices",_objDeviceTemplate.NumofDevices);
   query.bindValue(":brokerIP",_objDeviceTemplate.brokerIP);
   query.bindValue(":isRegularPort",_objDeviceTemplate.isRegularPort);
   query.bindValue(":portNO",_objDeviceTemplate.portNO);
   query.bindValue(":isAuthenticationRequire",_objDeviceTemplate.isAuthenticationRequire);
   query.bindValue(":brokerUserName",_objDeviceTemplate.brokerUserName);
   query.bindValue(":brokerPassword",_objDeviceTemplate.brokerPassword);
   query.bindValue(":coapURL",_objDeviceTemplate.coapURL);
   query.bindValue(":httpURL",_objDeviceTemplate.httpURL);
   query.bindValue(":isAttackingEntity",_objDeviceTemplate.isAttackingEntity);
   query.bindValue(":attackType",_objDeviceTemplate.attackType);
   query.bindValue(":sourceIP",_objDeviceTemplate.sourceIP);
   query.bindValue(":targetIP",_objDeviceTemplate.targetIP);
   query.bindValue(":targetPort",_objDeviceTemplate.targetPort);
   query.bindValue(":interval",_objDeviceTemplate.interval);
   query.bindValue(":message",_objDeviceTemplate.message);

    return dal.Update(query);

}

bool dlDeviceTemplate::UpdateUseCaseDeviceTemplate( objDeviceTemplate _objDeviceTemplate)
{
    DAL dal;
   QSqlQuery query(dal.m_db);

    query.prepare("UPDATE useCaseDeviceTemplate SET deviceName=:deviceName, deviceProtocol=:deviceProtocol, IPAddress=:IPAddress, "
                  "NumofDevices=:NumofDevices, brokerIP=:brokerIP, isRegularPort=:isRegularPort, portNO=:portNO,  "
                  "isAuthenticationRequire=:isAuthenticationRequire, brokerUserName=:brokerUserName,brokerPassword=:brokerPassword, coapURL=:coapURL, httpURL=:httpURL, "
                  "isAttackingEntity=:isAttackingEntity, attackType=:attackType, sourceIP=:sourceIP,targetIP=:targetIP, targetPort=:targetPort, interval=:interval, message=:message"
                  " WHERE _id =:deviceTemplateID");

    query.bindValue(":deviceTemplateID", _objDeviceTemplate._id);

    query.bindValue(":deviceName",_objDeviceTemplate.deviceName);
     query.bindValue(":deviceProtocol",_objDeviceTemplate.deviceProtocol);
    query.bindValue(":IPAddress",_objDeviceTemplate.IPAddress);
    query.bindValue(":NumofDevices",_objDeviceTemplate.NumofDevices);
   query.bindValue(":brokerIP",_objDeviceTemplate.brokerIP);
   query.bindValue(":isRegularPort",_objDeviceTemplate.isRegularPort);
   query.bindValue(":portNO",_objDeviceTemplate.portNO);
   query.bindValue(":isAuthenticationRequire",_objDeviceTemplate.isAuthenticationRequire);
   query.bindValue(":brokerUserName",_objDeviceTemplate.brokerUserName);
   query.bindValue(":brokerPassword",_objDeviceTemplate.brokerPassword);
   query.bindValue(":coapURL",_objDeviceTemplate.coapURL);
   query.bindValue(":httpURL",_objDeviceTemplate.httpURL);
   query.bindValue(":isAttackingEntity",_objDeviceTemplate.isAttackingEntity);
   query.bindValue(":attackType",_objDeviceTemplate.attackType);
   query.bindValue(":sourceIP",_objDeviceTemplate.sourceIP);
   query.bindValue(":targetIP",_objDeviceTemplate.targetIP);
   query.bindValue(":targetPort",_objDeviceTemplate.targetPort);
   query.bindValue(":interval",_objDeviceTemplate.interval);
   query.bindValue(":message",_objDeviceTemplate.message);

    return dal.Update(query);

}
objDeviceTemplate dlDeviceTemplate::GetDeviceList(int id)
//QList<objDeviceTemplate> dlDeviceTemplate::GetDeviceList(int id)
{
    DAL dal;
   QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id,deviceName,deviceProtocol,IPAddress,NumofDevices,brokerIP,"
                  "isRegularPort,portNO,isAuthenticationRequire,brokerUserName,brokerPassword,coapURL,httpURL,isAttackingEntity, "
                  "attackType,sourceIP,targetIP,targetPort,interval,message"
                  " FROM deviceTemplate WHERE _id=:_id");
    query.bindValue(":_id", id);

    query =   dal.GetData(query);

  //  QList<objDeviceTemplate> lstObjDeviceTemplate;
    objDeviceTemplate _objDeviceTemplate;
    while (query.next()) {
        // objDeviceTemplate _objDeviceTemplate;
                   _objDeviceTemplate._id = query.value("_id").toInt();
                   _objDeviceTemplate.deviceName = query.value("deviceName").toString();
                   //_objDeviceTemplate.deviceDescription = query.value("deviceDescription").toString();
                   _objDeviceTemplate.IPAddress = query.value("IPAddress").toString();
                   _objDeviceTemplate.deviceProtocol = query.value("deviceProtocol").toString();
                   _objDeviceTemplate.NumofDevices = query.value("NumofDevices").toInt();
                   _objDeviceTemplate.brokerIP = query.value("brokerIP").toString();
                   _objDeviceTemplate.isRegularPort = query.value("isRegularPort").toBool();
                   _objDeviceTemplate.portNO = query.value("portNO").toInt();
                   _objDeviceTemplate.isAuthenticationRequire = query.value("isAuthenticationRequire").toBool();
                   _objDeviceTemplate.brokerUserName = query.value("brokerUserName").toString();
                   _objDeviceTemplate.brokerPassword = query.value("brokerPassword").toString();
                   _objDeviceTemplate.coapURL = query.value("coapURL").toString();
                   _objDeviceTemplate.httpURL = query.value("httpURL").toString();
                   _objDeviceTemplate.isAttackingEntity = query.value("isAttackingEntity").toBool();
                   _objDeviceTemplate.attackType = query.value("attackType").toString();
                   _objDeviceTemplate.sourceIP = query.value("sourceIP").toString();
                   _objDeviceTemplate.targetIP = query.value("targetIP").toString();
                   _objDeviceTemplate.targetPort = query.value("targetPort").toInt();
                   _objDeviceTemplate.interval = query.value("interval").toInt();
                   _objDeviceTemplate.message = query.value("message").toString();
//                   lstObjDeviceTemplate.append(_objDeviceTemplate);
               }

    return  _objDeviceTemplate;

}
objDeviceTemplate dlDeviceTemplate::GetDeviceListNew(int id)
//QList<objDeviceTemplate> dlDeviceTemplate::GetDeviceList(int id)
{
    DAL dal;
   QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id,deviceName,deviceProtocol,IPAddress,NumofDevices,brokerIP,"
                  "isRegularPort,portNO,isAuthenticationRequire,brokerUserName,brokerPassword,coapURL,httpURL,isAttackingEntity, "
                  "attackType,sourceIP,targetIP,targetPort,interval,message"
                  " FROM useCaseDeviceTemplate WHERE _id=:_id");
    query.bindValue(":_id", id);

    query =   dal.GetData(query);

  //  QList<objDeviceTemplate> lstObjDeviceTemplate;
    objDeviceTemplate _objDeviceTemplate;
    while (query.next()) {
        // objDeviceTemplate _objDeviceTemplate;
                   _objDeviceTemplate._id = query.value("_id").toInt();
                   _objDeviceTemplate.deviceName = query.value("deviceName").toString();
                   //_objDeviceTemplate.deviceDescription = query.value("deviceDescription").toString();
                   _objDeviceTemplate.IPAddress = query.value("IPAddress").toString();
                   _objDeviceTemplate.deviceProtocol = query.value("deviceProtocol").toString();
                   _objDeviceTemplate.NumofDevices = query.value("NumofDevices").toInt();
                   _objDeviceTemplate.brokerIP = query.value("brokerIP").toString();
                   _objDeviceTemplate.isRegularPort = query.value("isRegularPort").toBool();
                   _objDeviceTemplate.portNO = query.value("portNO").toInt();
                   _objDeviceTemplate.isAuthenticationRequire = query.value("isAuthenticationRequire").toBool();
                   _objDeviceTemplate.brokerUserName = query.value("brokerUserName").toString();
                   _objDeviceTemplate.brokerPassword = query.value("brokerPassword").toString();
                   _objDeviceTemplate.coapURL = query.value("coapURL").toString();
                   _objDeviceTemplate.httpURL = query.value("httpURL").toString();
                   _objDeviceTemplate.isAttackingEntity = query.value("isAttackingEntity").toBool();
                   _objDeviceTemplate.attackType = query.value("attackType").toString();
                   _objDeviceTemplate.sourceIP = query.value("sourceIP").toString();
                   _objDeviceTemplate.targetIP = query.value("targetIP").toString();
                   _objDeviceTemplate.targetPort = query.value("targetPort").toInt();
                   _objDeviceTemplate.interval = query.value("interval").toInt();
                   _objDeviceTemplate.message = query.value("message").toString();
//                   lstObjDeviceTemplate.append(_objDeviceTemplate);
               }

    return  _objDeviceTemplate;

}
QList<objDevice> dlDeviceTemplate::GetDeviceListForUseCase(int useCaseID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id,useCaseID,deviceName,deviceProtocol,IPAddress,NumofDevices,brokerIP,"
                  " isRegularPort,portNO,isAuthenticationRequire,brokerUserName,brokerPassword,coapURL,httpURL,isAttackingEntity, "
                  " attackType,sourceIP,targetIP,targetPort,interval,message"
                  " FROM useCaseDeviceTemplate WHERE useCaseID=:useCaseID");
    query.bindValue(":useCaseID", useCaseID);
    query =   dal.GetData(query);

   QList<objDevice> lstObjDevice;

    while (query.next()) {


                    objDevice _objDevice;
                    int templateID = query.value("_id").toInt();

                   _objDevice.templateID = templateID;
                    _objDevice.deviceName  = query.value("deviceName").toString();
                   _objDevice.sHostName = query.value("IPAddress").toString();
                   _objDevice.protocol  = query.value("deviceProtocol").toString();
                   _objDevice.IPCount = 1;

                  _objDevice.isAttackingEntity = query.value("isAttackingEntity").toBool();
                  _objDevice.attackType = query.value("attackType").toString();
                  _objDevice.sourceIP = query.value("sourceIP").toString();
                  _objDevice.targetIP = query.value("targetIP").toString();
                  _objDevice.targetPort = query.value("targetPort").toInt();
                  _objDevice.interval = query.value("interval").toInt();
                  _objDevice.message = query.value("message").toString();

                    _objDevice.hostName = query.value("brokerIP").toString();
qDebug()<<query.value("isRegularPort");
                    if(query.value("isRegularPort").toBool())
                        _objDevice.portType ="REGULAR";
                    else
                        _objDevice.portType ="TTLS";

                    _objDevice.port = query.value("portNO").toInt();
                    _objDevice.isAuthenticationRequire = query.value("isAuthenticationRequire").toBool();
                    _objDevice.userName = query.value("brokerUserName").toString();
                    _objDevice.password = query.value("brokerPassword").toString();

                   lstObjDevice.append(_objDevice);
               }

    for(int i=0;i<lstObjDevice.length();i++)
    {
        int templateID = lstObjDevice[i].templateID;

        dlDeviceSubscribeData _dlDeviceSubscribeData;
        QList<objDeviceSubscribeData> _lstObjDeviceSubscribeData = _dlDeviceSubscribeData.fillTbWidgetMQTTSubscribeForUseCase(templateID);
        lstObjDevice[i].lstSubTopic = _lstObjDeviceSubscribeData;

        dlDevicePublishData _dlDevicePublishData;
        QList<objDevicePublishData> _lstObjDevicePublishData = _dlDevicePublishData.GetDevicePublishDataForUseCase(templateID);
        lstObjDevice[i].lstPubTopic = _lstObjDevicePublishData;

        dlDeviceCoapData _dlDeviceCoapData;
        QList<objDeviceCoapData> _lstObjDeviceCoapData = _dlDeviceCoapData.GetDeviceCoapDataForUseCase(templateID);
        lstObjDevice[i].lstDeviceCoapData = _lstObjDeviceCoapData;

        dlDeviceHttpData _dlDeviceHttpData;
        QList<objDeviceHttpData> _lstObjDeviceHttpData = _dlDeviceHttpData.GetDeviceHttpDataForUseCase(templateID);
        lstObjDevice[i].lstDeviceHttpData = _lstObjDeviceHttpData;
    }
    return  lstObjDevice;
}


QList<objDeviceTemplate> dlDeviceTemplate::GetDeviceList()
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id,deviceName FROM deviceTemplate");
    query =   dal.GetData(query);

    QList<objDeviceTemplate> lstObjDeviceTemplate;
    while (query.next()) {
         objDeviceTemplate _objDeviceTemplate;
                   _objDeviceTemplate._id = query.value("_id").toInt();
                   _objDeviceTemplate.deviceName = query.value("deviceName").toString();
                   //_objDeviceTemplate.deviceDescription = query.value("deviceDescription").toString();
                   lstObjDeviceTemplate.append(_objDeviceTemplate);
               }

    return lstObjDeviceTemplate;

}

bool dlDeviceTemplate::DelDeviceTemplateData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM deviceTemplate WHERE _id = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);


}
bool dlDeviceTemplate::DelDeviceTemplateDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM useCaseDeviceTemplate WHERE _id=:deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);


}
