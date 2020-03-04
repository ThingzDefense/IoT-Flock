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
#include "dltimeprofile.h"
#include <dal.h>
#include <QtSql>

dlTimeProfile::dlTimeProfile()
{

}
int dlTimeProfile::Insert(objTimeProfile _objTimeProfile)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("INSERT INTO timeProfile(name,type,interval,randFrom,"
                  "randTo,eventCondition,eventValue) "
                  "VALUES(:name,:type,:interval,:randFrom,"
                  ":randTo,:eventCondition,:eventValue) ");



    query.bindValue(":name",_objTimeProfile.name);
     query.bindValue(":type",_objTimeProfile.type);
     query.bindValue(":interval",_objTimeProfile.interval);
    query.bindValue(":randFrom",_objTimeProfile.randomFrom);

    query.bindValue(":randTo",_objTimeProfile.randomTo);
    query.bindValue(":eventCondition",_objTimeProfile.eventCondition);
   query.bindValue(":eventValue",_objTimeProfile.eventValue);


     return dal.Insert(query);

}

QList<objTimeProfile> dlTimeProfile::GetTimeProfileList()
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name, type, interval, randFrom, randTo, eventCondition, eventValue FROM timeProfile order by lower(name)");
    query =   dal.GetData(query);

    QList<objTimeProfile> lstObjTimeProfile;
    while (query.next()) {
         objTimeProfile _objTimeProfile;
                   _objTimeProfile._id = query.value("_id").toInt();
                   _objTimeProfile.name = query.value("name").toString();
                   _objTimeProfile.type = query.value("type").toString();
                   _objTimeProfile.interval = query.value("interval").toInt();
                   _objTimeProfile.randomFrom = query.value("randFrom").toInt();
                   _objTimeProfile.randomTo = query.value("randTo").toInt();
                   _objTimeProfile.eventCondition = query.value("eventCondition").toString();
                   _objTimeProfile.eventValue = query.value("eventValue").toInt();
                   lstObjTimeProfile.append(_objTimeProfile);
               }

    return lstObjTimeProfile;
}

objTimeProfile dlTimeProfile::GetTimeProfile(int id)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name, type, interval, randFrom, randTo, eventCondition, eventValue FROM timeProfile where _id=:_id");
    query.bindValue(":_id", id);
    query =   dal.GetData(query);

    objTimeProfile _objTimeProfile;
    while (query.next()) {

                   _objTimeProfile._id = query.value("_id").toInt();
                   _objTimeProfile.name = query.value("name").toString();
                   //qDebug() << query.value("name").toString();
                   _objTimeProfile.type = query.value("type").toString();
                   _objTimeProfile.interval = query.value("interval").toInt();
                   _objTimeProfile.randomFrom = query.value("randFrom").toInt();
                   _objTimeProfile.randomTo = query.value("randTo").toInt();
                   _objTimeProfile.eventCondition = query.value("eventCondition").toString();
                   _objTimeProfile.eventValue = query.value("eventValue").toInt();
               }

    return _objTimeProfile;


}

bool dlTimeProfile::DelTimeProfile(int id){

    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM timeProfile where _id=:_id");

    query.bindValue(":_id", id);
    return dal.Delete(query);

}


bool dlTimeProfile::UpdateTimeProfile(objTimeProfile _objTimeProfile){

    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("UPDATE timeProfile SET name=:name, type=:type, interval=:interval, randFrom=:randFrom, "
                  "randTo=:randTo, eventCondition=:eventCondition, eventValue=:eventValue WHERE _id =:_id");

    query.bindValue(":name",_objTimeProfile.name);
     query.bindValue(":type",_objTimeProfile.type);
     query.bindValue(":interval",_objTimeProfile.interval);
    query.bindValue(":randFrom",_objTimeProfile.randomFrom);
    query.bindValue(":randTo",_objTimeProfile.randomTo);
    query.bindValue(":eventCondition",_objTimeProfile.eventCondition);
   query.bindValue(":eventValue",_objTimeProfile.eventValue);
   query.bindValue(":_id",_objTimeProfile._id);

    return dal.Update(query);

}
