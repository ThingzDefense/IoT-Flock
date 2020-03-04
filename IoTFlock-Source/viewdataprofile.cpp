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
#include "viewdataprofile.h"
#include "ui_viewdataprofile.h"
#include "dataprofile.h"
#include "dldataprofile.h"
#include "dal.h"
#include <QDebug>
#include <QList>
#include <QMessageBox>

ViewDataProfile::ViewDataProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewDataProfile)
{
try{
    QStringList titles;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    titles<<"ID"<<"Existing Data Profiles"<<"Edit"<<"Delete";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->setColumnWidth(0, 25);
    ui->tableWidget->setColumnWidth(1, 455);
    ui->tableWidget->setColumnWidth(2, 50);
    ui->tableWidget->setColumnWidth(3, 50);
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setColumnHidden(0,true);
    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

ViewDataProfile::~ViewDataProfile()
{
    delete ui;
}

void ViewDataProfile::on_btnNewDataProfile_clicked()
{
 try{
    DataProfile dataprofile;
    dataprofile.setModal(true);
    int result = dataprofile.exec();
    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
  }

void ViewDataProfile::deleteRow(){
try{
    int row = ui->tableWidget->currentRow();
    int dataProfileID = ui->tableWidget->item(row,0)->text().toInt();

    //qDebug() << "dataProfileID" <<dataProfileID;

    dlDataProfile *_dlDataProfile = new dlDataProfile() ;

    if(_dlDataProfile->DelDataProfile(dataProfileID))
    {
        //QMessageBox::information(this, tr(""), tr("Successfully deleted."));
        ui->tableWidget->removeRow(row);
    }
    else
    {
        QMessageBox::critical(this, tr(""), tr("Delete error."));
    }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void ViewDataProfile::editRow(){
try{
    int row = ui->tableWidget->currentRow();
    DataProfile _DataProfile(this, "EDIT", ui->tableWidget->item(row,0)->text().toInt());
    _DataProfile.setModal(true);
    int result = _DataProfile.exec();
    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void ViewDataProfile::bindData(){

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    dlDataProfile *_dlDataProfile = new dlDataProfile();
    QList<objDataProfile> lstDataProfiles = _dlDataProfile->GetDataProfileList();
    foreach(objDataProfile _objDataProfile, lstDataProfiles)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int f1=ui->tableWidget->rowCount()-1;

        qDebug() << _objDataProfile._id;
        ui->tableWidget->setItem(f1, ID, new QTableWidgetItem(QString::number(_objDataProfile._id)));

        ui->tableWidget->setItem(f1, DATA_PROFILE_LIST, new QTableWidgetItem(_objDataProfile.name));

        QPushButton *edit = new QPushButton("",this);
        edit->setFixedWidth(50);
        edit->setFixedHeight(30);
        QPixmap pixmapEdit(_constants.PATH_EDITICON);
        QIcon EditButtonIcon(pixmapEdit);
        edit->setIcon(EditButtonIcon);
        edit->setIconSize(QSize(30, 20));
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,2,edit);
        connect(edit, &QPushButton::clicked, this, &ViewDataProfile::editRow);

        QPushButton *del = new QPushButton("",this);
        del->setFixedWidth(50);
        del->setFixedHeight(30);
        QPixmap pixmapDel(_constants.PATH_DELETEICON);
        QIcon DelButtonIcon(pixmapDel);
        del->setIcon(DelButtonIcon);
        del->setIconSize(QSize(30, 20));
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,3,del);
        connect(del, &QPushButton::clicked, this, &ViewDataProfile::deleteRow);

    }

}
