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
#include "dlusecase.h"
#include <dal.h>
#include <QtSql>

dlUseCase::dlUseCase()
{

}
int dlUseCase::Insert(objUseCase _objUseCase)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("INSERT INTO useCase(name) "
                  "VALUES(:name) ");

    query.bindValue(":name",_objUseCase.name);


    return dal.Insert(query);

}
bool dlUseCase::isUseCaseExists(objUseCase _objUseCase)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT COUNT(*) FROM useCase WHERE name =:name");
    query.bindValue(":name",_objUseCase.name);

    return dal.isExists(query);
}

QList<objUseCase> dlUseCase::GetUseCaseList()
{
    DAL dal;
    QSqlQuery query(dal.m_db);

    query.prepare("SELECT _id, name FROM useCase order by lower(name)");

    query =   dal.GetData(query);

    QList<objUseCase> lstObjUseCase;
    while (query.next()) {
         objUseCase _objUseCase;
                   _objUseCase._id = query.value("_id").toInt();
                   _objUseCase.name = query.value("name").toString();

                   lstObjUseCase.append(_objUseCase);
               }

    return lstObjUseCase;
}
objUseCase dlUseCase::GetUseCaseByID(int useCaseID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id, name FROM useCase where _id = :_id");
    query.bindValue(":_id",useCaseID);
    query =   dal.GetData(query);

    objUseCase _objUseCase;
    while (query.next()) {
                   _objUseCase._id = query.value("_id").toInt();
                   _objUseCase.name = query.value("name").toString();
                   return _objUseCase;
               }
    return _objUseCase;
}

bool dlUseCase::DelUseCase(int useCaseID)
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("DELETE FROM useCase WHERE _id = :useCaseID");
    query.bindValue(":useCaseID", useCaseID);

    return dal.Delete(query);

}
