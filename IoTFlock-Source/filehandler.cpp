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
#include "filehandler.h"
#include<QFile>
#include<QDir>
#include<QDebug>
#include<QDateTime>
FileHandler::FileHandler()
{

}
QString FileHandler::writeFile(QString nameofFile, QString text, bool isAppend)
{
    QFile file(nameofFile+ ".txt");
   bool result = false;
    if(isAppend)
         result = file.open(QIODevice::WriteOnly | QIODevice::Append );
     else
        result = file.open(QIODevice::WriteOnly);
    if(result)
    {
        QTextStream txtStream(&file);
        txtStream<<QDateTime::currentDateTime().toString()<<":"<<text<<"\n";  //writing to file
        file.close();
        return  "File Written";
    }
    else
    {
        return "Could not open the file";
    }
}
QString FileHandler::readFile(QString nameofFile)
{
    QFile file(nameofFile+ ".txt");
    if(!file.exists())
    {
        qDebug()<<file.fileName()<<"doesn't exist";
        return "File does not exists";
    }

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream txtStream(&file);
        return txtStream.readAll();
        file.close();
    }

    else
    {
        qDebug()<<"Could not open the file";
        return "Could not open the file";
    }
}
