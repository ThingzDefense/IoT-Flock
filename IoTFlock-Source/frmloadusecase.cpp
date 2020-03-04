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
#include "frmloadusecase.h"
#include "ui_frmloadusecase.h"
#include<dlusecase.h>
#include<threadmain.h>
#include <QPushButton>
#include <QDebug>
#include<frmsaveusecase.h>

#include<qmessagebox.h>
#include <QtGui>

frmLoadUseCase::frmLoadUseCase(QWidget *parent, QString useCases) :
    QDialog(parent),
    ui(new Ui::frmLoadUseCase)
{
try{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList titles;
    titles<<"ID"<<"Existing Use Case"<<"Load"<<"Delete"<<"Save XML";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setColumnWidth(1, 300);
    ui->tableWidget->setColumnWidth(2, 50);
    ui->tableWidget->setColumnWidth(3, 50);
    ui->tableWidget->setColumnWidth(4,100);

    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //ui->tableWidget->setColumnHidden(0,true);
    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}



frmLoadUseCase::~frmLoadUseCase()
{

    delete ui;
}

void frmLoadUseCase::bindData()
{
    dlUseCase _dlUseCase;
    QList<objUseCase> lstObjUseCase = _dlUseCase.GetUseCaseList();

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    foreach(objUseCase _objFrmNewDeviceTemplateView, lstObjUseCase)
        {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            int f1=ui->tableWidget->rowCount()-1;

            //qDebug() << _objFrmNewDeviceTemplateView._id;
            ui->tableWidget->setItem(f1, 0, new QTableWidgetItem(QString::number(_objFrmNewDeviceTemplateView._id)));

            ui->tableWidget->setItem(f1, 1, new QTableWidgetItem(_objFrmNewDeviceTemplateView.name));

            QPushButton *load = new QPushButton(" ",this);
            load->setFixedWidth(50);
            load->setFixedHeight(30);
            QPixmap pixmapView(_constants.PATH_LOADICON);
            QIcon LoadButtonIcon(pixmapView);
            load->setIcon(LoadButtonIcon);
            load->setIconSize(QSize(30, 20));
            ui->tableWidget->setCellWidget(f1,2,load);
            connect(load, &QPushButton::clicked, this, &frmLoadUseCase::selectUseCase); //====================

            QPushButton * del = new QPushButton(" ",this);
            del->setFixedWidth(50);
            del->setFixedHeight(30);
            QPixmap pixmapDelete(_constants.PATH_DELETEICON);
            QIcon DeleteButtonIcon(pixmapDelete);
            del->setIcon(DeleteButtonIcon);
            del->setIconSize(QSize(30, 20));
            ui->tableWidget->setCellWidget(f1,3,del);
            connect(del, &QPushButton::clicked, this, &frmLoadUseCase::deleteUseCase);

            QPushButton *btnXML = new QPushButton("Save XML",this);
            btnXML->setFixedWidth(90);
            btnXML->setFixedHeight(30);
            ui->tableWidget->setCellWidget(f1,4,btnXML);
            connect(btnXML, &QPushButton::clicked, this, &frmLoadUseCase::saveUseCaseXML);

    }

}

void frmLoadUseCase::selectUseCase()
{

try{
    formReply = "LOAD";
    int row = ui->tableWidget->currentRow();
    _useCaseId = ui->tableWidget->item(row, 0)->text().toInt();
    this->close();
    this->setResult(1);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmLoadUseCase::deleteUseCase(){

}

void frmLoadUseCase::saveUseCaseXML()
{

try{
    formReply = "XML";
    int row = ui->tableWidget->currentRow();
    _useCaseId = ui->tableWidget->item(row, 0)->text().toInt();
    ThreadMain _ThreadMain;
    _ThreadMain.SaveUseCaseXML(_useCaseId,false);
    this->close();
    this->setResult(1);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}
void frmLoadUseCase::on_btnAdNewUseCase_clicked()
{

    try {
    //int g = QString("test").toInt();
    //    int g =1/0;
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
