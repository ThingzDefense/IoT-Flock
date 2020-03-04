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
#include "dldevicepublishdata.h"
#include <dal.h>
#include <QtSql>
#include<dltimeprofile.h>
#include<dldataprofile.h>

dlDevicePublishData::dlDevicePublishData()
{
  // dal = new DAL();
}
int dlDevicePublishData::Insert(objDevicePublishData _objDevicePublishData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO devicePublishData(deviceTemplateID,topicID,QoS,dataProfileID,timeProfileID)"
                  "VALUES(:deviceTemplateID,:topicID,:QoS,:dataProfileID,:timeProfileID)");

    query.bindValue(":deviceTemplateID",_objDevicePublishData.deviceTemplateID);
    query.bindValue(":topicID",_objDevicePublishData.topicID);
     query.bindValue(":QoS",_objDevicePublishData.QoS);
     query.bindValue(":dataProfileID",_objDevicePublishData.dataProfileID);
     query.bindValue(":timeProfileID",_objDevicePublishData.timeProfileID);

     qDebug()<<dal.Insert(query);


}
int dlDevicePublishData::InsertForUseCase(objDevicePublishData _objDevicePublishData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO useCaseDevicePublishData(useCaseID,deviceTemplateID,topicID,QoS,dataProfileID,timeProfileID)"
                  "VALUES(:useCaseID,:deviceTemplateID,:topicID,:QoS,:dataProfileID,:timeProfileID)");

    query.bindValue(":useCaseID",_objDevicePublishData.useCaseID);
    query.bindValue(":deviceTemplateID",_objDevicePublishData.deviceTemplateID);
    query.bindValue(":topicID",_objDevicePublishData.topicID);
     query.bindValue(":QoS",_objDevicePublishData.QoS);
     query.bindValue(":dataProfileID",_objDevicePublishData.dataProfileID);
     query.bindValue(":timeProfileID",_objDevicePublishData.timeProfileID);

     qDebug()<<dal.Insert(query);


}
//objDevicePublishData dlDevicePublishData::fillTbWidgetMQTTPublish(int deviceTemplateID)
QList<objDevicePublishData> dlDevicePublishData::GetDevicePublishData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT topicID,QoS,dataProfileID,timeProfileID,topic.name as 'topic',"
                  "dataProfile.name as 'dataprofile',timeProfile.name as 'timeprofile' "
                  "FROM devicePublishData  inner join topic on (topic._id = devicePublishData.topicID) "
                  "inner join dataProfile on (dataProfile._id = devicePublishData.dataProfileID) "
                  "inner join timeProfile on (timeProfile._id = devicePublishData.timeProfileID) "
                  "WHERE deviceTemplateID=:deviceTemplateID");

    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);
    QList<objDevicePublishData> lstObjDevicePublishData;


    while (query.next()) {
                            objDevicePublishData _objDevicePublishData;
                   _objDevicePublishData.topicID = query.value("topicID").toInt();
                   _objDevicePublishData.QoS = query.value("QoS").toInt();
                   _objDevicePublishData.dataProfileID = query.value("dataProfileID").toInt();
                   _objDevicePublishData.timeProfileID = query.value("timeProfileID").toInt();

                   _objDevicePublishData.topic = query.value("topic").toString();
                   _objDevicePublishData.dataprofile = query.value("dataprofile").toString();
                   _objDevicePublishData.timeprofile = query.value("timeprofile").toString();
                   lstObjDevicePublishData.append(_objDevicePublishData);
}


    for(int i=0;i<lstObjDevicePublishData.length();i++)
    {
                   dlTimeProfile _dlTimeProfile;
                   lstObjDevicePublishData[i]._objTimeProfile = _dlTimeProfile.GetTimeProfile( lstObjDevicePublishData[i].timeProfileID);

    }

    for(int i=0;i<lstObjDevicePublishData.length();i++)
    {
                   dlDataProfile _dlDataProfile;
                   lstObjDevicePublishData[i]._objDataProfile = _dlDataProfile.GetDataProfile( lstObjDevicePublishData[i].dataProfileID);

    }
   return  lstObjDevicePublishData;

}
QList<objDevicePublishData> dlDevicePublishData::GetDevicePublishDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT topicID,QoS,dataProfileID,timeProfileID,topic.name as 'topic',"
                  "dataProfile.name as 'dataprofile',timeProfile.name as 'timeprofile' "
                  "FROM useCaseDevicePublishData  inner join topic on (topic._id = useCaseDevicePublishData.topicID) "
                  "inner join dataProfile on (dataProfile._id = useCaseDevicePublishData.dataProfileID) "
                  "inner join timeProfile on (timeProfile._id = useCaseDevicePublishData.timeProfileID) "
                  "WHERE deviceTemplateID=:deviceTemplateID");

    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);
    QList<objDevicePublishData> lstObjDevicePublishData;


    while (query.next()) {
                            objDevicePublishData _objDevicePublishData;
                   _objDevicePublishData.topicID = query.value("topicID").toInt();
                   _objDevicePublishData.QoS = query.value("QoS").toInt();
                   _objDevicePublishData.dataProfileID = query.value("dataProfileID").toInt();
                   _objDevicePublishData.timeProfileID = query.value("timeProfileID").toInt();

                   _objDevicePublishData.topic = query.value("topic").toString();
                   _objDevicePublishData.dataprofile = query.value("dataprofile").toString();
                   _objDevicePublishData.timeprofile = query.value("timeprofile").toString();

                   lstObjDevicePublishData.append(_objDevicePublishData);
    }
    for(int i=0;i<lstObjDevicePublishData.length();i++)
    {
                   dlTimeProfile _dlTimeProfile;
                   lstObjDevicePublishData[i]._objTimeProfile = _dlTimeProfile.GetTimeProfile( lstObjDevicePublishData[i].timeProfileID);

    }

    for(int i=0;i<lstObjDevicePublishData.length();i++)
    {
                   dlDataProfile _dlDataProfile;
                   lstObjDevicePublishData[i]._objDataProfile = _dlDataProfile.GetDataProfile( lstObjDevicePublishData[i].dataProfileID);

    }
    return  lstObjDevicePublishData;

}
QList<objDevicePublishData> dlDevicePublishData::GetDevicePublishData()
{



}

bool dlDevicePublishData::DelPublishData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM devicePublishData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);

}
bool dlDevicePublishData::DelPublishDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM useCaseDevicePublishData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);

}
