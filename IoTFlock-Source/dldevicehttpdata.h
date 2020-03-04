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
#ifndef DLDEVICEHTTPDATA_H
#define DLDEVICEHTTPDATA_H
#include<dal.h>
#include<objdevicehttpdata.h>

class dlDeviceHttpData
{
public:
    dlDeviceHttpData();
   ~dlDeviceHttpData();



    int Insert(objDeviceHttpData _objDeviceHttpData);
    int InsertForUseCase(objDeviceHttpData _objDeviceHttpData);
    bool DelHttpData(int deviceTemplateID);
    bool DelHttpDataForUseCase(int deviceTemplateID);
    QList<objDeviceHttpData> GetDeviceHttpData();
    QList<objDeviceHttpData> GetDeviceHttpData(int deviceTemplateID);
    QList<objDeviceHttpData> GetDeviceHttpDataForUseCase(int deviceTemplateID);

};

#endif // DLDEVICEHTTPDATA_H
