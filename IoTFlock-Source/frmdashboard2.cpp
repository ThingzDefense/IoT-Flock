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
#include "frmdashboard2.h"
#include "ui_frmdashboard2.h"
#include<dlusecase.h>
#include<threadmain.h>
#include <QPushButton>
#include <QDebug>
#include<frmsaveusecase.h>
//#include<mainwindow.h>
#include<qmessagebox.h>
#include<frmusecasedevices.h>
#include <QtGui>
#include<viewtopics.h>
#include<viewdataprofile.h>
#include<viewtimeprofile.h>
#include<frmnewdevicetemplateview.h>



frmDashboard2::frmDashboard2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmDashboard2)
{
    ui->setupUi(this);

    try {
  //  ui->setupUi(this);
    QMainWindow::showMaximized();
    this->setWindowTitle("IoT-Flock");
     QStringList titles;
    this->ui->tableWidget->setColumnCount(9);
    titles<<"ID"<<"UseCase Name"<<"No. of MQTT Devices"<<"No. of COAP Devices"<<"No. of Attacking Entities"<<" "<<" "<<" "<<" ";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->setColumnWidth(0, 25);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(2, 180);
    ui->tableWidget->setColumnWidth(3, 180);
    ui->tableWidget->setColumnWidth(4, 180);
    ui->tableWidget->setColumnWidth(5, 50);
    ui->tableWidget->setColumnWidth(6, 50);
    ui->tableWidget->setColumnWidth(7, 50);
    ui->tableWidget->setColumnWidth(8, 90);
    ui->tableWidget->setColumnHidden(0,true);
    ui->tableWidget->setColumnHidden(2,true);
    ui->tableWidget->setColumnHidden(3,true);
    ui->tableWidget->setColumnHidden(4,true);
    ui->tableWidget->setColumnHidden(5,true);


    bindData();


       // connect(btnAddNewUseCase, SIGNAL(clicked()), this, SLOT(on_btnAddNewUseCase_clicked()));
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();

        }
}

void frmDashboard2::on_btnAddNewUseCase_clicked()
{
    try {
    frmSaveUseCase _frmSaveUseCase(this);
    _frmSaveUseCase.setModal(true);
    _frmSaveUseCase.exec();
    bindData();
    }
    catch(std::exception &e)
    {
        QMessageBox::information(this,tr("Error"),tr(e.what()));
    }
     catch (...) {

       qDebug() << "Exception thrown:";
    }

}
void frmDashboard2::bindData()
{
    DAL dal;
    dlUseCase _dlUseCase;
    QList<objUseCase> lstObjUseCase = _dlUseCase.GetUseCaseList();

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(9);
    foreach(objUseCase _objFrmNewDeviceTemplateView, lstObjUseCase)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            int f1=ui->tableWidget->rowCount()-1;
            ui->tableWidget->setItem(f1, 0, new QTableWidgetItem(QString::number(_objFrmNewDeviceTemplateView._id)));
            ui->tableWidget->setItem(f1, 1, new QTableWidgetItem(_objFrmNewDeviceTemplateView.name));
            QSqlQuery query(dal.m_db);

            ui->tableWidget->setItem(f1, 2, new QTableWidgetItem(QString::number(0)));
            ui->tableWidget->setItem(f1, 3, new QTableWidgetItem(QString::number(0)));
            ui->tableWidget->setItem(f1, 4, new QTableWidgetItem(QString::number(0)));

           // QPushButton *run = new QPushButton("Run",this);
           // run->setFixedWidth(50);
           // run->setFixedHeight(30);
          //  ui->tableWidget->setCellWidget(f1,5,run);
           // connect(run, &QPushButton::clicked, this, &frmDashboard2::runUseCase);

            QPushButton *edit = new QPushButton("Edit",this);
            edit->setFixedWidth(50);
            edit->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,6,edit);
            connect(edit, &QPushButton::clicked, this, &frmDashboard2::editUseCase); //====================

            QPushButton * del = new QPushButton("Delete",this);
            del->setFixedWidth(50);
            del->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,7,del);
            connect(del, &QPushButton::clicked, this, &frmDashboard2::deleteUseCase);

            QPushButton *btnXML = new QPushButton("Save XML",this);
            btnXML->setFixedWidth(90);
            btnXML->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,8,btnXML);
            connect(btnXML, &QPushButton::clicked, this, &frmDashboard2::saveUseCaseXML);

    }
}

void frmDashboard2::editUseCase()
{
   try{

    int row = ui->tableWidget->currentRow();
    _useCaseId = ui->tableWidget->item(row,0)->text().toInt();
    frmUsecaseDevices _frmUsecaseDevices(this,_useCaseId);
    _frmUsecaseDevices.setModal(true);
    _frmUsecaseDevices.exec();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }


}

void frmDashboard2::deleteUseCase(){
try{
    int row = ui->tableWidget->currentRow();
    _useCaseId = ui->tableWidget->item(row, 0)->text().toInt();
    //((MainWindow*)parentWidget())->threadMain.DeleteUseCase(_useCaseId);
    ThreadMain _ThreadMain;
    _ThreadMain.DeleteUseCase(_useCaseId);
     bindData();

    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmDashboard2::saveUseCaseXML()
{

try{
    formReply = "XML";
    int row = ui->tableWidget->currentRow();
    _useCaseId = ui->tableWidget->item(row, 0)->text().toInt();
    ThreadMain _ThreadMain;
    _ThreadMain.SaveUseCaseXML(_useCaseId,false);
    //this->close();
   // this->setResult(1);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
    }
}

void frmDashboard2::runUseCase()
{
    int row = ui->tableWidget->currentRow();
    _useCaseId = ui->tableWidget->item(row, 0)->text().toInt();
    QString useCaseName = ui->tableWidget->item(row, 1)->text();
    ThreadMain _ThreadMain;
    _ThreadMain.SaveUseCaseXML(_useCaseId, true);


}
frmDashboard2::~frmDashboard2()
{
    delete ui;
}


void frmDashboard2::on_actionTopic_triggered()
{
    try {
       ViewTopics _ViewTopics;
       _ViewTopics.setModal(true);
       _ViewTopics.exec();
       } catch (std::exception &e) {
               msgBox.setText(e.what());
               msgBox.exec();
           } catch (...) {
               msgBox.setText("Problem occured");
               msgBox.exec();
           }
}

void frmDashboard2::on_actionData_Profile_triggered()
{
    try {
       ViewDataProfile _ViewDataProfile;
       _ViewDataProfile.setModal(true);
       _ViewDataProfile.exec();
       } catch (std::exception &e) {
               msgBox.setText(e.what());
               msgBox.exec();
           } catch (...) {
               msgBox.setText("Problem occured");
               msgBox.exec();
           }
}

void frmDashboard2::on_actionTime_Profile_triggered()
{
    try{
        ViewTimeProfile _ViewTimeProfile;
        _ViewTimeProfile.setModal(true);
        _ViewTimeProfile.exec();
        } catch (std::exception &e) {
                msgBox.setText(e.what());
                msgBox.exec();
            } catch (...) {
                msgBox.setText("Problem occured");
                msgBox.exec();
            }
}

void frmDashboard2::on_actionDevice_Template_triggered()
{
    try{
       frmNewDeviceTemplateView _frmNewDeviceTemplateView;
       _frmNewDeviceTemplateView.setModal(true);
       _frmNewDeviceTemplateView.exec();
       } catch (std::exception &e) {
               msgBox.setText(e.what());
               msgBox.exec();
           } catch (...) {
               msgBox.setText("Problem occured");
               msgBox.exec();
           }
}
