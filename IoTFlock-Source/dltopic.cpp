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
#include "dltopic.h"
#include <dal.h>
#include <QtSql>

dlTopic::dlTopic()
{


}
int dlTopic::Insert(objTopic _objTopic)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("INSERT INTO topic(name) "
                  "VALUES(:name) ");

    query.bindValue(":name",_objTopic.name);


    return dal.Insert(query);

}

QList<objTopic> dlTopic::GetTopicList()
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name FROM topic order by lower(name)");
    query =   dal.GetData(query);

    QList<objTopic> lstObjTopic;
    while (query.next()) {
         objTopic _objTopic;
                   _objTopic._id = query.value("_id").toInt();
                   _objTopic.name = query.value("name").toString();

                   lstObjTopic.append(_objTopic);
               }

    return lstObjTopic;


}

objTopic dlTopic::GetTopic(int id){

    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name FROM topic where _id=:_id");
    query.bindValue(":_id", id);
    query =  dal.GetData(query);

    objTopic _objTopic;
    while (query.next()) {
        _objTopic._id = query.value("_id").toInt();
        _objTopic.name = query.value("name").toString();
    }
    return _objTopic;

}

bool dlTopic::UpdateTopic(objTopic _objTopic){

    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("UPDATE topic SET name=:name WHERE _id =:_id");
    query.bindValue(":name", _objTopic.name);
    query.bindValue(":_id", _objTopic._id);

    return dal.Update(query);

}

bool dlTopic::DelTopic(int id){

    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM topic where _id=:_id");

    query.bindValue(":_id", id);
    return dal.Delete(query);

}

