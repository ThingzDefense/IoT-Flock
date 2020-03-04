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
#include "dlfrmnewdevicetemplateview.h"
#include <dal.h>
#include <QtSql>


dlFrmNewDeviceTemplateView::dlFrmNewDeviceTemplateView()
{

}
dlFrmNewDeviceTemplateView::~dlFrmNewDeviceTemplateView()
{

}

QList<objFrmNewDeviceTemplateView> dlFrmNewDeviceTemplateView::GetDeviceList()
{
    DAL dal;
    QSqlQuery query(dal.m_db);
    query.prepare("SELECT _id,deviceName,deviceDescription FROM deviceTemplate order by lower(deviceName)");
    query =   dal.GetData(query);


    QList<objFrmNewDeviceTemplateView> lstobjFrmNewDeviceTemplateView;
    while (query.next()) {
         objFrmNewDeviceTemplateView _objFrmNewDeviceTemplateView;

         _objFrmNewDeviceTemplateView._id = query.value("_id").toInt();
         _objFrmNewDeviceTemplateView.deviceName = query.value("deviceName").toString();
         _objFrmNewDeviceTemplateView.deviceDescription = query.value("deviceDescription").toString();

         lstobjFrmNewDeviceTemplateView.append(_objFrmNewDeviceTemplateView);


                        }
    return lstobjFrmNewDeviceTemplateView; //fix1
}
int dlFrmNewDeviceTemplateView::Edit(objFrmNewDeviceTemplateView _objFrmNewDeviceTemplateView)
{

}
int dlFrmNewDeviceTemplateView::Delete(int deviceTemplateID)
{



}
