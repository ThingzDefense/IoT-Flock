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
#ifndef DLDEVICETEMPLATE_H
#define DLDEVICETEMPLATE_H
#include<objdevicetemplate.h>
#include<objdevice.h>


#include<dal.h>
class dlDeviceTemplate
{
public:
    dlDeviceTemplate();
    int Insert(objDeviceTemplate _objDeviceTemplate);
    int InsertForUseCase(objDeviceTemplate _objDeviceTemplate);
    bool UpdateDeviceTemplate(objDeviceTemplate _objDeviceTemplate);
     bool UpdateUseCaseDeviceTemplate(objDeviceTemplate _objDeviceTemplate);
    bool DelDeviceTemplateData(int deviceTemplateID);
    bool DelDeviceTemplateDataForUseCase(int deviceTemplateID);
    QList<objDeviceTemplate> GetDeviceList();
    QList<objDevice> GetDeviceListForUseCase(int useCaseID);
    objDeviceTemplate GetDeviceList(int id);
    objDeviceTemplate GetDeviceListNew(int id);

   // QList<objDeviceTemplate> GetDeviceList(int id);

private:

};

#endif // DLDEVICETEMPLATE_H
