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
#include "dldevicecoapdata.h"
#include <dal.h>
#include <QtSql>
#include<dltimeprofile.h>
#include<dldataprofile.h>

dlDeviceCoapData::dlDeviceCoapData()
{

}
int dlDeviceCoapData::Insert(objDeviceCoapData _objDeviceCoapData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO deviceCoapData(deviceTemplateID,url,coapCommand,parameters,parametersWithID,coapDataProfileID,coapTimeProfileID)"
                  "VALUES(:deviceTemplateID,:url,:coapCommand,:parameters,:parametersWithID,:coapDataProfileID,:coapTimeProfileID)");

    query.bindValue(":deviceTemplateID",_objDeviceCoapData.deviceTemplateID);
    query.bindValue(":url",_objDeviceCoapData.url);
    query.bindValue(":coapCommand",_objDeviceCoapData.coapCommand);
    query.bindValue(":parameters",_objDeviceCoapData.parameters);
    query.bindValue(":parametersWithID",_objDeviceCoapData.parametersWithID);
    query.bindValue(":coapDataProfileID",_objDeviceCoapData.coapDataProfileID);
    query.bindValue(":coapTimeProfileID",_objDeviceCoapData.coapTimeProfileID);

     qDebug()<<dal.Insert(query);
}
int dlDeviceCoapData::InsertForUseCase(objDeviceCoapData _objDeviceCoapData)
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("INSERT INTO useCaseDeviceCoapData(useCaseID,deviceTemplateID,url,coapCommand,parameters,parametersWithID,coapDataProfileID,coapTimeProfileID)"
                  "VALUES(:useCaseID,:deviceTemplateID,:url,:coapCommand,:parameters,:parametersWithID,:coapDataProfileID,:coapTimeProfileID)");

    query.bindValue(":useCaseID",_objDeviceCoapData.useCaseID);
    query.bindValue(":deviceTemplateID",_objDeviceCoapData.deviceTemplateID);
    query.bindValue(":url",_objDeviceCoapData.url);
    query.bindValue(":coapCommand",_objDeviceCoapData.coapCommand);
    query.bindValue(":parameters",_objDeviceCoapData.parameters);
    query.bindValue(":parametersWithID",_objDeviceCoapData.parametersWithID);
    query.bindValue(":coapDataProfileID",_objDeviceCoapData.coapDataProfileID);
    query.bindValue(":coapTimeProfileID",_objDeviceCoapData.coapTimeProfileID);

     qDebug()<<dal.Insert(query);


}
QList<objDeviceCoapData> dlDeviceCoapData::GetDeviceCoapData()
{

}
QList<objDeviceCoapData> dlDeviceCoapData::GetDeviceCoapData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);


    query.prepare("SELECT deviceTemplateID,coapCommand,parameters,parametersWithID,coapDataProfileID,coapTimeProfileID,"
                  "dataProfile.name as 'dataprofile',timeProfile.name as 'timeprofile',url  "
                  "FROM deviceCoapData "
                  "left outer join dataProfile on (dataProfile._id = deviceCoapData.coapDataProfileID) "
                  "inner join timeProfile on (timeProfile._id = deviceCoapData.coapTimeProfileID) "
                  "WHERE deviceTemplateID=:deviceTemplateID");

    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);
    QList<objDeviceCoapData> lstObjDeviceCoapData;


    while (query.next()) {
                            objDeviceCoapData _objDeviceCoapData;
                   _objDeviceCoapData.deviceTemplateID = query.value("deviceTemplateID").toInt();
                 //  _objDeviceCoapData.coapUrl = query.value("coapUrl").toString();
                   _objDeviceCoapData.coapCommand = query.value("coapCommand").toString();
                   _objDeviceCoapData.parameters = query.value("parameters").toString();
                   _objDeviceCoapData.parametersWithID = query.value("parametersWithID").toString();
                   _objDeviceCoapData.coapDataProfileID = query.value("coapDataProfileID").toInt();
                   _objDeviceCoapData.coapTimeProfileID = query.value("coapTimeProfileID").toInt();
                   _objDeviceCoapData.dataprofile = query.value("dataprofile").toString();
                   _objDeviceCoapData.timeprofile = query.value("timeprofile").toString();
                   _objDeviceCoapData.url = query.value("url").toString();

                   dlTimeProfile _dlTimeProfile;
                   _objDeviceCoapData._objTimeProfile = _dlTimeProfile.GetTimeProfile(_objDeviceCoapData.coapTimeProfileID);

                    dlDataProfile _dlDataProfile;
                  _objDeviceCoapData._objDataProfile = _dlDataProfile.GetDataProfile(_objDeviceCoapData.coapDataProfileID);


                   lstObjDeviceCoapData.append(_objDeviceCoapData);
                  }
    return  lstObjDeviceCoapData;


}
QList<objDeviceCoapData> dlDeviceCoapData::GetDeviceCoapDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);


    query.prepare("SELECT deviceTemplateID,coapCommand,parameters,parametersWithID,coapDataProfileID,coapTimeProfileID,"
                  "dataProfile.name as 'dataprofile',timeProfile.name as 'timeprofile',url  "
                  "FROM useCaseDeviceCoapData "
                  "left outer join dataProfile on (dataProfile._id = useCaseDeviceCoapData.coapDataProfileID) "
                  "inner join timeProfile on (timeProfile._id = useCaseDeviceCoapData.coapTimeProfileID) "
                  "WHERE deviceTemplateID=:deviceTemplateID");

    query.bindValue(":deviceTemplateID", deviceTemplateID);

    query =   dal.GetData(query);
    QList<objDeviceCoapData> lstObjDeviceCoapData;


    while (query.next()) {
                            objDeviceCoapData _objDeviceCoapData;
                   _objDeviceCoapData.deviceTemplateID = query.value("deviceTemplateID").toInt();
                 //  _objDeviceCoapData.coapUrl = query.value("coapUrl").toString();
                   _objDeviceCoapData.coapCommand = query.value("coapCommand").toString();
                   _objDeviceCoapData.parameters = query.value("parameters").toString();
                   _objDeviceCoapData.parametersWithID = query.value("parametersWithID").toString();
                   _objDeviceCoapData.coapDataProfileID = query.value("coapDataProfileID").toInt();
                   _objDeviceCoapData.coapTimeProfileID = query.value("coapTimeProfileID").toInt();
                   _objDeviceCoapData.dataprofile = query.value("dataprofile").toString();
                   _objDeviceCoapData.timeprofile = query.value("timeprofile").toString();
                   _objDeviceCoapData.url = query.value("url").toString();
                    lstObjDeviceCoapData.append(_objDeviceCoapData);

    }
    for(int i=0;i<lstObjDeviceCoapData.length();i++)
    {
              dlTimeProfile _dlTimeProfile;
              lstObjDeviceCoapData[i]._objTimeProfile = _dlTimeProfile.GetTimeProfile(lstObjDeviceCoapData[i].coapTimeProfileID);
     }
     for(int i=0;i<lstObjDeviceCoapData.length();i++)
     {
               dlDataProfile _dlDataProfile;
               lstObjDeviceCoapData[i]._objDataProfile = _dlDataProfile.GetDataProfile(lstObjDeviceCoapData[i].coapDataProfileID);
      }
    return  lstObjDeviceCoapData;


}

bool dlDeviceCoapData::DelCoapData(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM deviceCoapData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    dal.Delete(query);

}
bool dlDeviceCoapData::DelCoapDataForUseCase(int deviceTemplateID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM useCaseDeviceCoapData WHERE deviceTemplateID = :deviceTemplateID");
    query.bindValue(":deviceTemplateID", deviceTemplateID);

    dal.Delete(query);

}
