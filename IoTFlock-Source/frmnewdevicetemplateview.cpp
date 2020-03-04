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
#include "frmnewdevicetemplateview.h"
#include "ui_frmnewdevicetemplateview.h"
#include<dlfrmnewdevicetemplateview.h>
#include<frmnewdevicetemplate.h>

#include<dldevicecoapdata.h>
#include<dldevicehttpdata.h>
#include<dldevicepublishdata.h>
#include<dldevicesubscribedata.h>
#include<dldevicetemplate.h>

#include<QMessageBox>
#include<QPushButton>

#include<qdebug.h>

frmNewDeviceTemplateView::frmNewDeviceTemplateView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmNewDeviceTemplateView)
{
 try{
    ui->setupUi(this);
    layoutTbWidgetViewDB();
    fillTbWidgetViewDB();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

frmNewDeviceTemplateView::~frmNewDeviceTemplateView()
{
    delete ui;
}
void frmNewDeviceTemplateView::fillTbWidgetViewDB()
{
    dlFrmNewDeviceTemplateView *_dlFrmNewDeviceTemplateView = new dlFrmNewDeviceTemplateView();
    QList<objFrmNewDeviceTemplateView> lstObjFrmNewDeviceTemplateView = _dlFrmNewDeviceTemplateView->GetDeviceList();

    ui->tbWidegtViewDB->setRowCount(0);
    ui->tbWidegtViewDB->setColumnCount(4);
    foreach(objFrmNewDeviceTemplateView _objFrmNewDeviceTemplateView, lstObjFrmNewDeviceTemplateView)
        {
            ui->tbWidegtViewDB->insertRow(ui->tbWidegtViewDB->rowCount());
            int f1=ui->tbWidegtViewDB->rowCount()-1;

            //qDebug() << _objFrmNewDeviceTemplateView._id;
            ui->tbWidegtViewDB->setItem(f1, ID, new QTableWidgetItem(QString::number(_objFrmNewDeviceTemplateView._id)));

            ui->tbWidegtViewDB->setItem(f1, DEVICENAME, new QTableWidgetItem(_objFrmNewDeviceTemplateView.deviceName));
           // ui->tbWidegtViewDB->setItem(f1, DESCRIPTION, new QTableWidgetItem(_objFrmNewDeviceTemplateView.deviceDescription));

            QPushButton *edit = new QPushButton(" ",this);
            edit->setFixedWidth(50);
            edit->setFixedHeight(30);
            QPixmap pixmapEdit(_constants.PATH_EDITICON);
            QIcon EditButtonIcon(pixmapEdit);
            edit->setIcon(EditButtonIcon);
            edit->setIconSize(QSize(30, 20));
            ui->tbWidegtViewDB->setCellWidget(f1,2,edit);
            connect(edit, &QPushButton::clicked, this, &frmNewDeviceTemplateView::editRecord); //====================

            QPushButton * del = new QPushButton(" ",this);
            del->setFixedWidth(50);
            del->setFixedHeight(30);
            QPixmap pixmapDelete(_constants.PATH_DELETEICON);
            QIcon DeleteButtonIcon(pixmapDelete);
            del->setIcon(DeleteButtonIcon);
            del->setIconSize(QSize(30, 20));
            ui->tbWidegtViewDB->setCellWidget(f1,3,del);
            connect(del, &QPushButton::clicked, this, &frmNewDeviceTemplateView::deleteRecord);
       }

}
void frmNewDeviceTemplateView::layoutTbWidgetViewDB()
{
    QStringList titles;

    //ui->btnAddSubscribeTopic->setFixedWidth(40);
    ui->tbWidegtViewDB->setColumnCount(4);
    titles<<"ID"<<"DeviceName"<<" "<<" ";
    ui->tbWidegtViewDB->setHorizontalHeaderLabels(titles);
    ui->tbWidegtViewDB->setColumnWidth(1,470);
    ui->tbWidegtViewDB->setColumnWidth(2,50);
    ui->tbWidegtViewDB->setColumnWidth(3,50);
    ui->tbWidegtViewDB->setColumnHidden(0,true);
    ui->tbWidegtViewDB->horizontalHeader()->setStretchLastSection(true);

}

void frmNewDeviceTemplateView::on_pushButton_clicked()
{
try{
    frmNewDeviceTemplate _frmNewDeviceTemplate(this, "ADD", -1);
    _frmNewDeviceTemplate.setModal(true);
    _frmNewDeviceTemplate.exec();
    fillTbWidgetViewDB();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }

void frmNewDeviceTemplateView::editRecord()
{
  try{
    int row = ui->tbWidegtViewDB->currentRow();
   frmNewDeviceTemplate * _frmNewDeviceTemplate = new frmNewDeviceTemplate(this, "EDIT", ui->tbWidegtViewDB->item(row,0)->text().toInt());
   qDebug()<<ui->tbWidegtViewDB->item(row,0)->text().toInt();


    _frmNewDeviceTemplate->setModal(true);
    int result = _frmNewDeviceTemplate->exec();
    fillTbWidgetViewDB();

    //layoutTbWidgetViewDB();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }


}
void frmNewDeviceTemplateView::deleteRecord()
{
  try{
    int rowNum = ui->tbWidegtViewDB->currentRow();
    int templateID = ui->tbWidegtViewDB->item(rowNum,0)->text().toInt();

    dlDeviceHttpData _dlDeviceHttpData;
    bool _lstObjDeviceHttpData = _dlDeviceHttpData.DelHttpData(templateID);



    dlDeviceCoapData _dlDeviceCoapData;
    bool _lstObjDeviceCoapData = _dlDeviceCoapData.DelCoapData(templateID);

    dlDevicePublishData _dlDevicePublishData;
    bool _lstObjDevicePublishData = _dlDevicePublishData.DelPublishData(templateID);

    dlDeviceSubscribeData _dlDeviceSubscribeData;
    bool _lstObjDeviceSubscribeData = _dlDeviceSubscribeData.DelSubscribeData(templateID);

  //  if(_lstObjDeviceHttpData && _lstObjDeviceCoapData && _lstObjDeviceSubscribeData && _lstObjDevicePublishData)
   // {

        dlDeviceTemplate _dlDeviceTemplate;
        bool _lstDeviceTemplate = _dlDeviceTemplate.DelDeviceTemplateData(templateID);

        if(_lstDeviceTemplate)
        {
             QMessageBox::information(this,tr("Query Info"),tr("Deleted Successfully"));
             fillTbWidgetViewDB();
        }
        else
             QMessageBox::information(this,tr("Query Info"),tr("Operation Failed"));

  //  }
   // else
    //    QMessageBox::information(this,tr("Query Info"),tr("Operation Failed"));

    fillTbWidgetViewDB();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }

}

