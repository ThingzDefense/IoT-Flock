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
#include "frmkeyvalue.h"
#include "ui_frmkeyvalue.h"
#include<dldataprofile.h>

#include<QPushButton>

FrmKeyValue::FrmKeyValue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmKeyValue)
{
    ui->setupUi(this);
    // QString key,id,parameter,value;

    BindDataProfileValue();
    SetLayout();

}

FrmKeyValue::~FrmKeyValue()
{
    delete ui;
}
void FrmKeyValue::SetLayout()
{
    QStringList titles;
    ui->tbWidgetFrmKey->setColumnCount(4);
    titles<<"id"<<"Parameter"<<"Value"<<" ";
    ui->tbWidgetFrmKey->setHorizontalHeaderLabels(titles);
    ui->tbWidgetFrmKey->setColumnHidden(0,true);  //id
    ui->tbWidgetFrmKey->setColumnWidth(1,200);    //parameter
    ui->tbWidgetFrmKey->setColumnWidth(2,100);    //value
    ui->tbWidgetFrmKey->setColumnWidth(3,50);   //btn

}

void FrmKeyValue::on_btnAddFrmKey_clicked()
{
    ui->tbWidgetFrmKey->insertRow(ui->tbWidgetFrmKey->rowCount());
    int rowNum = ui->tbWidgetFrmKey->rowCount()-1;

    ui->tbWidgetFrmKey->setItem(rowNum,0, new QTableWidgetItem(ui->cmbFrmKeyValue->currentData().toString()));
    ui->tbWidgetFrmKey->setItem(rowNum,1,new QTableWidgetItem(ui->txtFrmKeyParameter->text()));
    ui->tbWidgetFrmKey->setItem(rowNum,2,new QTableWidgetItem(ui->cmbFrmKeyValue->currentText()));

    QPushButton *bt = new QPushButton("X");
    bt->setFixedHeight(30);
    bt->setFixedWidth(50);
    ui->tbWidgetFrmKey->setCellWidget(rowNum,3,bt);
    connect(bt,&QPushButton::clicked,this,&FrmKeyValue::removeRow);


}

void FrmKeyValue::removeRow()
{
    int rowNum=ui->tbWidgetFrmKey->currentRow();
    ui->tbWidgetFrmKey->removeRow(rowNum);
}
void FrmKeyValue::BindDataProfileValue()
{

        dlDataProfile _dlDataProfile;
        QList<objDataProfile> lstObjDataProfile = _dlDataProfile.GetDataProfileList();
        foreach(objDataProfile obj, lstObjDataProfile)
        {
            ui->cmbFrmKeyValue->addItem(obj.name, QVariant(obj._id));
        }

}

void FrmKeyValue::on_OK_clicked()
{

    keyValue ="";
    keyValueWithID ="";
    for(int i=0;i<ui->tbWidgetFrmKey->rowCount();i++)
    {

       keyValueWithID += ui->tbWidgetFrmKey->item(i,0)->text()+",";
       keyValueWithID += ui->tbWidgetFrmKey->item(i,1)->text()+",";
       keyValueWithID +=  ui->tbWidgetFrmKey->item(i,2)->text()+",";

       keyValue += ui->tbWidgetFrmKey->item(i,1)->text()+",";
       keyValue +=  ui->tbWidgetFrmKey->item(i,2)->text()+",";
    }
    this->close();

}

void FrmKeyValue::on_Cancel_clicked()
{
    this->close();
}
