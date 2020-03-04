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
#ifndef DAL_H
#define DAL_H

#include <QObject>
#include <QSharedDataPointer>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>


class DALData;

class DAL
{
public:
    DAL();
   // DAL(const DAL &);
   // DAL &operator=(const DAL &);
    bool OpenDB();
    bool CloseDB();
    bool ExecuteQuery(QString _query);
    int  Insert(QSqlQuery query);
    bool Update(QSqlQuery query);
    bool Delete(QSqlQuery query);
    QSqlQuery GetData(QSqlQuery sql);
    bool isExists(QSqlQuery query);
    QString GetLastError();
    ~DAL();
    QSqlDatabase m_db;

private:
    QSharedDataPointer<DALData> data;
    QString dbName = "db2.db";
    //QString dbName = "C:\\Users\\Engr. Malik\\Documents\\WorkingFolder\\Code_06122018\\Code\\db2.db";

    QSqlError lastError;

    void SetLastError(QString error);
};

#endif // DAL_H
