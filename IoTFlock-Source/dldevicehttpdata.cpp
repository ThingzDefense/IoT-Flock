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
#include "dldevicehttpdata.h"
#include <dal.h>
#include <QtSql>
#include<dltimeprofile.h>
#include<dldataprofile.h>

dlDeviceHttpData::dlDeviceHttpData()
{

}
dlDeviceHttpData::~dlDeviceHttpData()
{

}
int dlDeviceHttpData::Insert(objDeviceHttpData _objDeviceHttpData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO deviceHttpData(deviceTemplateID,url,httpCommand,parameters,parametersWithID,httpDataProfileID,httpTimeProfileID)"
                  "VALUES(:deviceTemplateID,:url,:httpCommand,:parameters,:parametersWithID,:httpDataProfileID,:httpTimeProfileID)");

    query.bindValue(":deviceTemplateID",_objDeviceHttpData.deviceTemplateID);
    query.bindValue(":url",_objDeviceHttpData.url);
     query.bindValue(":httpCommand",_objDeviceHttpData.httpCommand);
     query.bindValue(":parameters",_objDeviceHttpData.parameters);
     query.bindValue(":parametersWithID",_objDeviceHttpData.parametersWithID);
     query.bindValue(":httpDataProfileID",_objDeviceHttpData.httpDataProfileID);
     query.bindValue(":httpTimeProfileID",_objDeviceHttpData.httpTimeProfileID);

     qDebug()<<dal.Insert(query);

}
int dlDeviceHttpData::InsertForUseCase(objDeviceHttpData _objDeviceHttpData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO useCaseDeviceHttpData(useCaseID,deviceTemplateID,url,httpCommand,parameters,parametersWithID,httpDataProfileID,httpTimeProfileID)"
                  "VALUES(:useCaseID,:deviceTemplateID,:url,:httpCommand,:parameters,:parametersWithID,:httpDataProfileID,:httpTimeProfileID)");

    query.bindValue(":useCaseID",_objDeviceHttpData.useCaseID);
    query.bindValue(":deviceTemplateID",_objDeviceHttpData.deviceTemplateID);
    query.bindValue(":url",_objDeviceHttpData.url);
     query.bindValue(":httpCommand",_objDeviceHttpData.httpCommand);
     query.bindValue(":parameters",_objDeviceHttpData.parameters);
     query.bindValue(":parametersWithID",_objDeviceHttpData.parametersWithID);
     query.bindValue(":httpDataProfileID",_objDeviceHttpData.httpDataProfileID);
     query.bindValue(":httpTimeProfileID",_objDeviceHttpData.httpTimeProfileID);

     qDebug()<<dal.Insert(query);

}

QList<objDeviceHttpData> dlDeviceHttpData::GetDeviceHttpData()
{

}
QList<objDeviceHttpData> dlDeviceHttpData::GetDeviceHttpData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT deviceTemplateID,httpCommand,parameters,parametersWithID,httpDataProfileID,httpTimeProfileID, "
                  "dataProfile.name as 'dataprofile', timeProfile.name as 'timeprofile',url FROM deviceHttpData "
                  "left outer join dataProfile on (dataProfile._id = deviceHttpData.httpDataProfileID) "
                  "inner join timeProfile on (timeProfile._id = deviceHttpData.httpTimeProfileID) "
                      "WHERE deviceTemplateID=:deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);
    QList<objDeviceHttpData> lstObjDeviceHttpData;


    while (query.next()) {
                            objDeviceHttpData _objDeviceHttpData;
                   _objDeviceHttpData.deviceTemplateID = query.value("deviceTemplateID").toInt();
                  // _objDeviceHttpData.httpUrl = query.value("httpUrl").toString();
                   _objDeviceHttpData.httpCommand = query.value("httpCommand").toString();
                   _objDeviceHttpData.parameters = query.value("parameters").toString();
                   _objDeviceHttpData.parametersWithID = query.value("parametersWithID").toString();
                   _objDeviceHttpData.httpDataProfileID = query.value("httpDataProfileID").toInt();
                   _objDeviceHttpData.httpTimeProfileID = query.value("httpTimeProfileID").toInt();
                   _objDeviceHttpData.dataprofile = query.value("dataprofile").toString();
                   _objDeviceHttpData.timeprofile = query.value("timeprofile").toString();
                   _objDeviceHttpData.url = query.value("url").toString();
                   dlTimeProfile _dlTimeProfile;
                   _objDeviceHttpData._objTimeProfile = _dlTimeProfile.GetTimeProfile(_objDeviceHttpData.httpTimeProfileID);
                   dlDataProfile _dlDataProfile;
                   _objDeviceHttpData._objDataProfile = _dlDataProfile.GetDataProfile(_objDeviceHttpData.httpDataProfileID);

                   lstObjDeviceHttpData.append(_objDeviceHttpData);
                  }
    return  lstObjDeviceHttpData;

}
QList<objDeviceHttpData> dlDeviceHttpData::GetDeviceHttpDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT deviceTemplateID,httpCommand,parameters,parametersWithID,httpDataProfileID,httpTimeProfileID, "
                  "dataProfile.name as 'dataprofile', timeProfile.name as 'timeprofile',url FROM useCaseDeviceHttpData "
                  "left outer join dataProfile on (dataProfile._id = useCaseDeviceHttpData.httpDataProfileID) "
                  "inner join timeProfile on (timeProfile._id = useCaseDeviceHttpData.httpTimeProfileID) "
                      "WHERE deviceTemplateID=:deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);
    QList<objDeviceHttpData> lstObjDeviceHttpData;


    while (query.next()) {
                            objDeviceHttpData _objDeviceHttpData;
                   _objDeviceHttpData.deviceTemplateID = query.value("deviceTemplateID").toInt();
                  // _objDeviceHttpData.httpUrl = query.value("httpUrl").toString();
                   _objDeviceHttpData.httpCommand = query.value("httpCommand").toString();
                   _objDeviceHttpData.parameters = query.value("parameters").toString();
                   _objDeviceHttpData.parametersWithID = query.value("parametersWithID").toString();
                   _objDeviceHttpData.httpDataProfileID = query.value("httpDataProfileID").toInt();
                   _objDeviceHttpData.httpTimeProfileID = query.value("httpTimeProfileID").toInt();
                   _objDeviceHttpData.dataprofile = query.value("dataprofile").toString();
                   _objDeviceHttpData.timeprofile = query.value("timeprofile").toString();
                   _objDeviceHttpData.url = query.value("url").toString();
                   dlTimeProfile _dlTimeProfile;
                   _objDeviceHttpData._objTimeProfile = _dlTimeProfile.GetTimeProfile(_objDeviceHttpData.httpTimeProfileID);
                   dlDataProfile _dlDataProfile;
                   _objDeviceHttpData._objDataProfile = _dlDataProfile.GetDataProfile(_objDeviceHttpData.httpDataProfileID);

                   lstObjDeviceHttpData.append(_objDeviceHttpData);
                  }
    return  lstObjDeviceHttpData;

}


bool dlDeviceHttpData::DelHttpData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM deviceHttpData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);


}
bool dlDeviceHttpData::DelHttpDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM useCaseDeviceHttpData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    return dal.Delete(query);


}
