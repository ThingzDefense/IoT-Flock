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
#include "dal.h"
#include <qvariant.h>
#include <QDebug>

class DALData : public QSharedData
{
public:
};

DAL::DAL() : data(new DALData)
{
  OpenDB();
}

//DAL::DAL(const DAL &rhs) : data(rhs.data)
//{
//}

//DAL &DAL::operator=(const DAL &rhs)
//{
 //   if (this != &rhs)
  //      data.operator=(rhs.data);
  //  return *this;
//}

bool DAL::ExecuteQuery(QString _query)
{
       bool success = false;
       //OpenDB();
       QSqlQuery query(m_db);
       success = query.exec(_query);
       //CloseDB();
       if(!success)
        {
           return false;
        }

      // return query.lastInsertId().toInt();
       return true;
}

int DAL::Insert(QSqlQuery query)
{
        bool success = false;
        //OpenDB();
        success = query.exec();
        if(!success)
         {
            qDebug()<<"LastError:"<<query.lastError();
            CloseDB();
            return false;
         }
         //CloseDB();
        return query.lastInsertId().toInt();
}

bool DAL::Delete(QSqlQuery query)
{
        bool success = false;
        //OpenDB();
        success = query.exec();
        if(!success)
         {
            qDebug()<<query.lastError();
          //CloseDB();
            return false;
         }
        //CloseDB();
        return true;
}

bool DAL::Update(QSqlQuery query)
{
        bool success = false;
        //OpenDB();
        success = query.exec();
        if(!success)
         {
            qDebug()<<query.lastError();
           CloseDB();
            return false;
         }
         //CloseDB();
        return true;
}

QSqlQuery DAL::GetData(QSqlQuery query)
{
    bool success = false;
    //OpenDB();
    success = query.exec();
    if(!success)
     {
       qDebug()<<query.lastError();
        //CloseDB();
        return query;
     }
    // CloseDB();
    return query;

}
bool DAL::isExists(QSqlQuery query)
{
    bool success = false;
    //OpenDB();
    success = query.exec();
    if(!success)
     {
        qDebug()<<query.lastError();
        //CloseDB();
        return true;
     }
    int result = 0;
      while (query.next()) {
        result = query.value(0).toInt();
      }
    if(result > 0)
        return true;
    else
        return false;
    // CloseDB();
}
void DAL::SetLastError(QString _error)
{
    lastError = _error;
}
QString DAL::GetLastError()
{
    return "lastError";
}
bool DAL::OpenDB()
{

    if(m_db.isOpen())
        return true;
   m_db = QSqlDatabase::addDatabase("QSQLITE");
   m_db.setDatabaseName(dbName);
   m_db.open();
   if (m_db.isOpen() == false)
   {
        qDebug()<<m_db.lastError();
        return false;
   }
   else
   {
      // query = new QSqlQuery(m_db);
       return true;
   }
}
bool DAL::CloseDB()
{
    if(m_db.isOpen())
       m_db.close();
    return true;
}
DAL::~DAL()
{
  CloseDB();

}
