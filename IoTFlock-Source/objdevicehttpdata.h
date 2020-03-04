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
#ifndef OBJDEVICEHTTPDATA_H
#define OBJDEVICEHTTPDATA_H
#include<QString>
#include<objdataprofile.h>
#include<objtimeprofile.h>
class objDeviceHttpData
{
public:
    objDeviceHttpData();

    int _id;
    int deviceTemplateID;
    int useCaseID;
    QString url;
    QString httpCommand;
    QString parameters;
    QString parametersWithID;
    int httpDataProfileID;
    int httpTimeProfileID;
    QString dataprofile;
    QString timeprofile;

    objDataProfile _objDataProfile;
    objTimeProfile _objTimeProfile;

      QString _lastSentTime;
};

#endif // OBJDEVICEHTTPDATA_H
