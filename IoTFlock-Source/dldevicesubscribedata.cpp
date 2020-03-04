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
#include "dldevicesubscribedata.h"
#include<dal.h>
#include<QtSql>

dlDeviceSubscribeData::dlDeviceSubscribeData()
{
   // dal = new DAL();

}

int dlDeviceSubscribeData::Insert(objDeviceSubscribeData _objDeviceSubscribeData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO deviceSubscribeData(topicID,deviceTemplateID)"
                  "VALUES(:topicID,:deviceTemplateID)");

    query.bindValue(":topicID",_objDeviceSubscribeData.topicID);
     query.bindValue(":deviceTemplateID",_objDeviceSubscribeData.deviceTemplateID);

     qDebug()<<dal.Insert(query);

}
int dlDeviceSubscribeData::InsertForUseCase(objDeviceSubscribeData _objDeviceSubscribeData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO useCaseDeviceSubscribeData(useCaseID,topicID,deviceTemplateID)"
                  "VALUES(:useCaseID,:topicID,:deviceTemplateID)");

    query.bindValue(":useCaseID",_objDeviceSubscribeData.useCaseID);
    query.bindValue(":topicID",_objDeviceSubscribeData.topicID);
     query.bindValue(":deviceTemplateID",_objDeviceSubscribeData.deviceTemplateID);

     qDebug()<<dal.Insert(query);

}
QList<objDeviceSubscribeData> dlDeviceSubscribeData::fillTbWidgetMQTTSubscribe(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT topicID,topic.name  FROM deviceSubscribeData  "
                  "inner join topic on (topic._id = topicID) WHERE deviceTemplateID==:deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);

    QList<objDeviceSubscribeData> _lstObjDeviceSubscribeData;
    while (query.next()) {
        objDeviceSubscribeData _objDeviceSubscribeData;
        _objDeviceSubscribeData.topicID =  query.value("topicID").toInt();
        _objDeviceSubscribeData.topicName = query.value("name").toString();
        _lstObjDeviceSubscribeData.append(_objDeviceSubscribeData);

                  }
    return  _lstObjDeviceSubscribeData;

}
QList<objDeviceSubscribeData> dlDeviceSubscribeData::fillTbWidgetMQTTSubscribeForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT topicID,topic.name  FROM useCaseDeviceSubscribeData  "
                  "inner join topic on (topic._id = topicID) WHERE deviceTemplateID==:deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);

    QList<objDeviceSubscribeData> _lstObjDeviceSubscribeData;
    while (query.next()) {
        objDeviceSubscribeData _objDeviceSubscribeData;
        _objDeviceSubscribeData.topicID = query.value("topicID").toInt();
        _objDeviceSubscribeData.topicName = query.value("name").toString();
        _lstObjDeviceSubscribeData.append(_objDeviceSubscribeData);

                  }
    return  _lstObjDeviceSubscribeData;

}

QList<objDeviceSubscribeData> dlDeviceSubscribeData::GetDeviceSubscribeData()
{

}

bool dlDeviceSubscribeData::DelSubscribeData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM deviceSubscribeData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);

}
bool dlDeviceSubscribeData::DelSubscribeDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM useCaseDeviceSubscribeData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);

}
