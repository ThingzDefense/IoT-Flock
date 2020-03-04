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
#include "frmusecasedevices.h"
#include "ui_frmusecasedevices.h"
#include<frmnewdevicetemplate.h>
#include<frmloadusecase.h>
#include<frmviewlog.h>
#include "ui_frmviewlog.h"
#include<dlusecase.h>
#include<threadmain.h>
#include<dldevicetemplate.h>

//frmUsecaseDevices::frmUsecaseDevices(QWidget *parent) :
frmUsecaseDevices::frmUsecaseDevices(QWidget *parent, int _useCaseId) :
    QDialog(parent),
    ui(new Ui::frmUsecaseDevices)
{
    ui->setupUi(this);
    try {
        id=_useCaseId;
        this->setWindowTitle("Devices in UseCase");
         QStringList titles;
        this->ui->tableWidget->setColumnCount(9);
        titles<<"UseCaseID"<<"DeviceTemplateID"<<"Device Name"<<"Protocol"<<"IP Address"<<"Attack Type"<<"Last Activity" <<""<<"";
        ui->tableWidget->setHorizontalHeaderLabels(titles);
        ui->tableWidget->setColumnWidth(0, 25);
        ui->tableWidget->setColumnWidth(1, 25);
        ui->tableWidget->setColumnHidden(0,true);
        ui->tableWidget->setColumnHidden(1,true);
        ui->tableWidget->setColumnWidth(2, 200);
        ui->tableWidget->setColumnWidth(3, 70);
        ui->tableWidget->setColumnWidth(4, 100);
        ui->tableWidget->setColumnWidth(5, 80);
        ui->tableWidget->setColumnWidth(6, 90);
        ui->tableWidget->setColumnHidden(6,true);
        ui->tableWidget->setColumnWidth(7, 60);
        ui->tableWidget->setColumnWidth(7, 50);
        ui->tableWidget->setColumnWidth(8, 50);



        bindData(id);
        } catch (std::exception &e) {
                msgBox.setText(e.what());
                msgBox.exec();
            } catch (...) {
                msgBox.setText("Problem occured");
                msgBox.exec();

            }
}

void frmUsecaseDevices::bindData(int _useCaseId)
{
    dlDeviceTemplate _dlDeviceTemplate;
    QList<objDevice> lstObjDevice =_dlDeviceTemplate.GetDeviceListForUseCase(_useCaseId);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(9);


    foreach(objDevice _objDevice, lstObjDevice)
        {
            //"UseCaseID"<<"DeviceTemplateID"<<"Device Name"<<"Protocol"<<"IP Address"<<"Attack Type"<<"Last Activity"<<""<<"";
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            int f1=ui->tableWidget->rowCount()-1;
            ui->tableWidget->setItem(f1, 0, new QTableWidgetItem(QString::number(_objDevice.useCaseID)));
            ui->tableWidget->setItem(f1, 1, new QTableWidgetItem(QString::number(_objDevice.templateID)));
            ui->tableWidget->setItem(f1, 2, new QTableWidgetItem(_objDevice.deviceName));
            ui->tableWidget->setItem(f1, 3, new QTableWidgetItem(_objDevice.protocol));
            ui->tableWidget->setItem(f1, 4, new QTableWidgetItem(_objDevice.sHostName));
            ui->tableWidget->setItem(f1, 5, new QTableWidgetItem(_objDevice.attackType));
            ui->tableWidget->setItem(f1, 6, new QTableWidgetItem("lastActivity"));

          /*  QPushButton *view = new QPushButton("View Log",this);
            view->setFixedWidth(60);
            view->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,7,view);
           connect(view, &QPushButton::clicked, this, &frmUsecaseDevices::viewlog);
          */
            QPushButton *edit = new QPushButton("Edit",this);
            edit->setFixedWidth(50);
            edit->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,7,edit);
            connect(edit, &QPushButton::clicked, this, &frmUsecaseDevices::editDevice);

            QPushButton * del = new QPushButton("Delete",this);
            del->setFixedWidth(50);
            del->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,8,del);
            connect(del, &QPushButton::clicked, this, &frmUsecaseDevices::deleteDevice);

    }
}

void frmUsecaseDevices::viewlog()
{
    int row = ui->tableWidget->currentRow();
    QString deviceIP = ui->tableWidget->item(row,colIP)->text();
    QString deviceLog = threadMain.ViewDeviceData(deviceIP);

     frmViewLog _frmViewLog;
    _frmViewLog.setModal(true);
    _frmViewLog.ui->txtLog->setText(deviceLog);
    _frmViewLog.exec();
}
void frmUsecaseDevices::on_btnAddNewdevice_clicked()
{
    try{
        frmNewDeviceTemplate myNewDevice(this,"NEWDEVICE");
        myNewDevice.setModal(true);
        if(myNewDevice.exec() == QDialog::Accepted)
        {
            qDebug()<<"_useCaseId: "<<id;
            myNewDevice._objDevice.useCaseID = id;
            threadMain.CreateDevicesNew(myNewDevice._objDevice);
            bindData(id);


        }

        } catch (std::exception &e) {
                msgBox.setText(e.what());
                msgBox.exec();
            } catch (...) {
                msgBox.setText("Problem occured");
                msgBox.exec();
            }

}



void frmUsecaseDevices::editDevice()
{
    int row = ui->tableWidget->currentRow();

    int devcieTemplateID = ui->tableWidget->item(row,1)->text().toInt(); //devcieTemplateID
    try{

        frmNewDeviceTemplate myNewDevice(this,"USECASEEDIT",devcieTemplateID);
        myNewDevice.setModal(true);
        myNewDevice.exec();
       // if(myNewDevice.exec() == QDialog::Accepted)
        //{
            qDebug()<<"_useCaseId: "<<id;
            myNewDevice._objDevice.useCaseID = id;
            //threadMain.CreateDevicesNew(myNewDevice._objDevice);

       // }
        bindData(id);
         qDebug()<<"_useCaseId: "<<id;
        } catch (std::exception &e) {
                msgBox.setText(e.what());
                msgBox.exec();
            } catch (...) {
                msgBox.setText("Problem occured");
                msgBox.exec();
            }


}

void frmUsecaseDevices::deleteDevice()
{
    try{
   int row = ui->tableWidget->currentRow();
   //qDebug()<<"Test: "<<ui->tableWidget->item(row,1)->text();
   threadMain.DeleteDeviceNew(ui->tableWidget->item(row,1)->text().toInt());
    bindData(id);
   } catch (std::exception &e) {
           msgBox.setText(e.what());
           msgBox.exec();
       } catch (...) {
           msgBox.setText("Problem occured");
           msgBox.exec();
       }

}
void frmUsecaseDevices::showData()
{
    try{
        frmLoadUseCase _frmLoadUseCase(this, "useCases");
        _frmLoadUseCase.setModal(true);
        if(_frmLoadUseCase.exec() == QDialog::Accepted)
        {
           // on_btnClear_clicked();

            if(threadMain.LoadUseCase(_frmLoadUseCase._useCaseId))
            {
                dlUseCase _dlUseCase;
                objUseCase _objUseCase= _dlUseCase.GetUseCaseByID(_frmLoadUseCase._useCaseId);
                //useCaseID = _objUseCase._id;
                useCaseName = _objUseCase.name;
                //on_btnRefresh_clicked();
                QMessageBox::information(this, tr(""), tr("Successfully loaded."));

            }
            else
            {
                QMessageBox::information(this, tr(""), tr("Problem occured while loading."));

            }
        }
        } catch (std::exception &e) {
                msgBox.setText(e.what());
                msgBox.exec();
            } catch (...) {
                msgBox.setText("Problem occured");
                msgBox.exec();
            }
    }
frmUsecaseDevices::~frmUsecaseDevices()
{
    delete ui;
}


