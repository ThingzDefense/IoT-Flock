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
#include "dataprofile.h"
#include "ui_dataprofile.h"
#include <QMessageBox>
#include <dldataprofile.h>
#include <QDebug>

DataProfile::DataProfile(QWidget *parent, QString FormType, int id) :
    QDialog(parent),
    ui(new Ui::DataProfile)
{
 try{
    ui->setupUi(this);
    _FormType = FormType;
    _id = id;

    if(FormType == "EDIT"){
        fillDataProfile();
    }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

DataProfile::~DataProfile()
{
    delete ui;
}

void DataProfile::on_btnCancel_clicked()
{
  try{
    this->close();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void DataProfile::on_btnSave_clicked()
{
try{
    if(_FormType == "SAVE"){
        saveDataProfile();
    }
    else if (_FormType == "EDIT"){
        editDataProfile(_id);
    }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }

}


void DataProfile::saveDataProfile(){

    objDataProfile _objDataProfile;

    if(ui->txtProfileName->text().isEmpty()){
        QMessageBox::critical(this, tr("Data Profile"), tr("Please Type Data Profile Name"));
        return;
    }
    else{
        _objDataProfile.name =  ui->txtProfileName->text();
    }

    if(ui->gbStartText->isChecked()){
        if(ui->txtStartText->text().isEmpty()){
            QMessageBox::critical(this, tr("Data Profile"), tr("Please Type Start Text"));
            return;
        }
        else{
            _objDataProfile.isStartText = ui->gbStartText->isChecked();
            _objDataProfile.startText = ui->txtStartText->text();
        }
    }
    else{
        _objDataProfile.isStartText = 0;
        _objDataProfile.startText = "";
    }

    if(ui->gbRandomValue->isChecked()){
        if(ui->sbRandomTo->value() == 0){
            QMessageBox::critical(this, tr("Data Profile"), tr("In Random Value 'To' can't be zero."));
            return;
        }
        else if(ui->sbRandomFrom->value() > ui->sbRandomTo->value()){
            QMessageBox::critical(this, tr("Data Profile"), tr("In Random Value 'From' must be less than 'To'."));
            return;
        }
        else{
            _objDataProfile.isRandom = ui->gbRandomValue->isChecked();
            _objDataProfile.randomFrom = ui->sbRandomFrom->value();
            _objDataProfile.randomTo = ui->sbRandomTo->value();
        }
    }
    else{
        _objDataProfile.isRandom = 0;
        _objDataProfile.randomFrom = 0;
        _objDataProfile.randomTo = 0;
    }

//couldn't

    if(ui->gbEndText->isChecked()){
        if(ui->txtEndText->text().isEmpty()){
            QMessageBox::critical(this, tr("Data Profile"), tr("Please Type End Text"));
            return;
        }
        else{
            _objDataProfile.isEndText = ui->gbEndText->isChecked();
            _objDataProfile.endText = ui->txtEndText->text();
        }
    }
    else{
        _objDataProfile.isEndText = 0;
        _objDataProfile.endText = "";
    }


    dlDataProfile *_dlDataProfile = new dlDataProfile () ;
    int result = _dlDataProfile->Insert(_objDataProfile);
    qDebug()<<result;
    if(result > 0)
    {
        //ui->txtTopic->setText("");
        QMessageBox::information(this, tr(""), tr("Successfully inserted."));
        ui->txtProfileName->setText("");
        ui->gbStartText->setChecked(false);
        ui->txtStartText->setText("");
        ui->gbRandomValue->setChecked(false);
        ui->sbRandomFrom->setValue(0);
        ui->sbRandomTo->setValue(0);
        ui->gbEndText->setChecked(false);
        ui->txtEndText->setText("");
    }
    else
    {
        QMessageBox::critical(this, tr(""), tr("Insertion error."));
    }

}

void DataProfile::fillDataProfile(){

    dlDataProfile *_dlDataProfile = new dlDataProfile();
    objDataProfile _objDataProfile = _dlDataProfile->GetDataProfile(_id);

    ui->txtProfileName->setText(_objDataProfile.name);
    if(_objDataProfile.isStartText){
        ui->gbStartText->setChecked(true);
        ui->txtStartText->setText(_objDataProfile.startText);
    }
    if(_objDataProfile.isRandom){
        ui->gbRandomValue->setChecked(true);
        ui->sbRandomFrom->setValue(_objDataProfile.randomFrom);
        ui->sbRandomTo->setValue(_objDataProfile.randomTo);
    }
    if(_objDataProfile.isEndText){
        ui->gbEndText->setChecked(true);
        ui->txtEndText->setText(_objDataProfile.endText);
    }
    //qDebug() << "fillTopic name" <<_objTopic.name;
    //ui->txtTopic->setText(_objTopic.name);

}

void DataProfile::editDataProfile(int id){

    objDataProfile _objDataProfile;

    _objDataProfile._id = id;

    if(ui->txtProfileName->text().isEmpty()){
        QMessageBox::critical(this, tr("Data Profile"), tr("Please Type Data Profile Name"));
        return;
    }
    else{
        _objDataProfile.name =  ui->txtProfileName->text();
    }

    if(ui->gbStartText->isChecked()){
        if(ui->txtStartText->text().isEmpty()){
            QMessageBox::critical(this, tr("Data Profile"), tr("Please Type Start Text"));
            return;
        }
        else{
            _objDataProfile.isStartText = ui->gbStartText->isChecked();
            _objDataProfile.startText = ui->txtStartText->text();
        }
    }
    else{
        _objDataProfile.isStartText = 0;
        _objDataProfile.startText = "";
    }

    if(ui->gbRandomValue->isChecked()){
        if(ui->sbRandomTo->value() == 0){
            QMessageBox::critical(this, tr("Data Profile"), tr("In Random Value 'To' can't be zero."));
            return;
        }
        else if(ui->sbRandomFrom->value() > ui->sbRandomTo->value()){
            QMessageBox::critical(this, tr("Data Profile"), tr("In Random Value 'From' must be less than 'To'."));
            return;
        }
        else{
            _objDataProfile.isRandom = ui->gbRandomValue->isChecked();
            _objDataProfile.randomFrom = ui->sbRandomFrom->value();
            _objDataProfile.randomTo = ui->sbRandomTo->value();
        }
    }
    else{
        _objDataProfile.isRandom = 0;
        _objDataProfile.randomFrom = 0;
        _objDataProfile.randomTo = 0;
    }


    if(ui->gbEndText->isChecked()){
        if(ui->txtEndText->text().isEmpty()){
            QMessageBox::critical(this, tr("Data Profile"), tr("Please Type End Text"));
            return;
        }
        else{
            _objDataProfile.isEndText = ui->gbEndText->isChecked();
            _objDataProfile.endText = ui->txtEndText->text();
        }
    }
    else{
        _objDataProfile.isEndText = 0;
        _objDataProfile.endText = "";
    }


    dlDataProfile *_dlDataProfile = new dlDataProfile () ;

    if(_dlDataProfile->UpdateDataProfile(_objDataProfile))
    {
        //ui->txtTopic->setText("");
        QMessageBox::information(this, tr(""), tr("Successfully updated."));
        this->close();
    }
    else
    {
        QMessageBox::critical(this, tr(""), tr("Update error."));
    }

}
