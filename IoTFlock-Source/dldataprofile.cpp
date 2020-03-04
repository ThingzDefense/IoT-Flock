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
#include "dldataprofile.h"
#include <dal.h>
#include <QtSql>

dlDataProfile::dlDataProfile()
{

}
int dlDataProfile::Insert(objDataProfile _objDataProfile)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("INSERT INTO dataProfile(name,isStartText,startText,isRandom,"
                  "randomFrom,randomTo,isEndText,endText) "
                  "VALUES(:name,:isStartText,:startText,:isRandom,"
                  ":randomFrom,:randomTo,:isEndText,:endText) ");


    query.bindValue(":name",_objDataProfile.name);
     query.bindValue(":isStartText",_objDataProfile.isStartText);
     query.bindValue(":startText",_objDataProfile.startText);
    query.bindValue(":isRandom",_objDataProfile.isRandom);
    query.bindValue(":randomFrom",_objDataProfile.randomFrom);
    query.bindValue(":randomTo",_objDataProfile.randomTo);
    query.bindValue(":isEndText",_objDataProfile.isEndText);
   query.bindValue(":endText",_objDataProfile.endText);



     return dal.Insert(query);

}

QList<objDataProfile> dlDataProfile::GetDataProfileList()
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name, isStartText, startText, isRandom, randomFrom, randomTo, isEndText, endText FROM dataProfile order by lower(name)");
    query =   dal.GetData(query);

    QList<objDataProfile> lstObjDataProfile;
    while (query.next()) {
         objDataProfile _objDataProfile;
                   _objDataProfile._id = query.value("_id").toInt();
                   _objDataProfile.name = query.value("name").toString();
                   _objDataProfile.isStartText = query.value("isStartText").toInt();
                   _objDataProfile.startText = query.value("startText").toString();
                   _objDataProfile.isRandom = query.value("isRandom").toInt();
                   _objDataProfile.randomFrom = query.value("randomFrom").toInt();
                   _objDataProfile.randomTo = query.value("randomTo").toInt();
                   _objDataProfile.isEndText = query.value("isEndText").toInt();
                   _objDataProfile.endText = query.value("endText").toString();

                   lstObjDataProfile.append(_objDataProfile);
               }

    return lstObjDataProfile;

}

objDataProfile dlDataProfile::GetDataProfile(int id){

    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name, isStartText, startText, isRandom, randomFrom, randomTo, isEndText, endText FROM dataProfile where _id=:_id");
    query.bindValue(":_id", id);
    query =  dal.GetData(query);

    objDataProfile _objDataProfile;
    while (query.next()) {
        _objDataProfile._id = query.value("_id").toInt();
        _objDataProfile.name = query.value("name").toString();
        _objDataProfile.isStartText = query.value("isStartText").toInt();
        _objDataProfile.startText = query.value("startText").toString();
        _objDataProfile.isRandom = query.value("isRandom").toInt();
        _objDataProfile.randomFrom = query.value("randomFrom").toInt();
        _objDataProfile.randomTo = query.value("randomTo").toInt();
        _objDataProfile.isEndText = query.value("isEndText").toInt();
        _objDataProfile.endText = query.value("endText").toString();
    }
    return _objDataProfile;

}

bool dlDataProfile::DelDataProfile(int id){

    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM dataProfile where _id=:_id");

    query.bindValue(":_id", id);
    return dal.Delete(query);

}


bool dlDataProfile::UpdateDataProfile(objDataProfile _objDataProfile){

    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("UPDATE dataProfile SET name=:name, isStartText=:isStartText, startText=:startText, isRandom=:isRandom, "
                  "randomFrom=:randomFrom, randomTo=:randomTo, isEndText=:isEndText, endText=:endText WHERE _id =:_id");


    query.bindValue(":name",_objDataProfile.name);
     query.bindValue(":isStartText",_objDataProfile.isStartText);
     query.bindValue(":startText",_objDataProfile.startText);
    query.bindValue(":isRandom",_objDataProfile.isRandom);
    query.bindValue(":randomFrom",_objDataProfile.randomFrom);
    query.bindValue(":randomTo",_objDataProfile.randomTo);
    query.bindValue(":isEndText",_objDataProfile.isEndText);
   query.bindValue(":endText",_objDataProfile.endText);
   query.bindValue(":_id",_objDataProfile._id);

    return dal.Update(query);

}
