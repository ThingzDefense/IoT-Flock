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
#include "timeprofile.h"
#include "ui_timeprofile.h"
#include <QMessageBox>
#include <QDebug>
#include "timeprofile.h"
#include "dltimeprofile.h"

TimeProfile::TimeProfile(QWidget *parent, QString FormType, int id) :
    QDialog(parent),
    ui(new Ui::TimeProfile)
{
    try{
    ui->setupUi(this);
    _FormType = FormType;
    _id = id;

    ui->sbEventValue->setVisible(false);
    ui->lblLamda->setVisible(false);

    ui->rbPeriodic->setChecked(true);
    ui->gbPeriodic->setEnabled(true);
    ui->gbEventDriven->setDisabled(true);

    QVBoxLayout* vLayout = new QVBoxLayout();
    setLayout(vLayout);
    setMinimumSize(200,200);


    if(FormType == "EDIT"){
        fillTimeProfile();
    }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

TimeProfile::~TimeProfile()
{
    delete ui;
}

void TimeProfile::on_btnCancel_clicked()
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

void TimeProfile::on_btnSave_clicked()
{
    try{
    if(_FormType == "SAVE"){
        saveTimeProfile();
    }
    else if (_FormType == "EDIT"){
        editTimeProfile(_id);
    }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void TimeProfile::saveTimeProfile(){

    objTimeProfile _objTimeProfile;
    if(ui->txtProfileName->text().isEmpty()){
        QMessageBox::critical(this, tr("Time Profile"), tr("Please Type Profile Name"));
        return;
    }
    else{
       _objTimeProfile.name = ui->txtProfileName->text();
    }

    if(ui->rbPeriodic->isChecked()){
        if(ui->sbPeriodicInterval->value() == 0){
            QMessageBox::critical(this, tr("Time Profile"), tr("Interval value must be greater than zero"));
            return;
        }
        else{
           _objTimeProfile.type = "Periodic";
           _objTimeProfile.interval = ui->sbPeriodicInterval->value();
           _objTimeProfile.randomFrom = 0;
           _objTimeProfile.randomTo   = 0;
           _objTimeProfile.eventCondition = "";
           _objTimeProfile.eventValue = 0;
        }

    }
    else{
        if(ui->sbEventRandomTo->value() == 0){
            QMessageBox::critical(this, tr("Time Profile"), tr("In Random Value 'To' can't be zero."));
            return;
        }
        else if(ui->sbEventRandomFrom->value() > ui->sbEventRandomTo->value()){
            QMessageBox::critical(this, tr("Time Profile"), tr("In Random Value 'From' must be less than 'To'."));
            return;
        }
        // else if(ui->sbEventValue->value() <= ui->sbEventRandomFrom->value()){
        //    QMessageBox::critical(this, tr("Time Profile"), tr("Event value must be between 'From' and 'To'."));
        //    return;
        //}
        else{
            _objTimeProfile.type = "Event Driven";
            _objTimeProfile.randomFrom = ui->sbEventRandomFrom->value();
            _objTimeProfile.randomTo   = ui->sbEventRandomTo->value();
            //_objTimeProfile.eventCondition = ui->cbEventCondition->currentText();
            _objTimeProfile.eventValue = ui->sbEventValue->value();
            _objTimeProfile.interval = 0;
        }
    }


    dlTimeProfile _dlTimeProfile;
    int result = _dlTimeProfile.Insert(_objTimeProfile);
    if(result > 0)
    {
        ui->txtProfileName->setText("");
        ui->sbPeriodicInterval->setValue(0);
        ui->sbEventRandomFrom->setValue(0);
        ui->sbEventRandomTo->setValue(0);
       // ui->cbEventCondition->setCurrentText("Greater");
        ui->sbEventValue->setValue(0);
    }
    else
    {
        QMessageBox::critical(this, tr(""), tr("Insertion error."));
    }
}

void TimeProfile::fillTimeProfile(){

    dlTimeProfile *_dlTimeProfile = new dlTimeProfile();
    objTimeProfile _objTimeProfile = _dlTimeProfile->GetTimeProfile(_id);

    ui->txtProfileName->setText(_objTimeProfile.name);

    qDebug() << _objTimeProfile.name;

    if(_objTimeProfile.type == "Periodic"){
        ui->rbPeriodic->setChecked(true);
        ui->sbPeriodicInterval->setValue(_objTimeProfile.interval);
        on_rbPeriodic_clicked();

    }
    else if(_objTimeProfile.type == "Event Driven"){
        ui->rbEventDriven->setChecked(true);
        ui->sbEventRandomFrom->setValue(_objTimeProfile.randomFrom);
        ui->sbEventRandomTo->setValue(_objTimeProfile.randomTo);
        //ui->cbEventCondition->setCurrentText(_objTimeProfile.eventCondition);
        ui->sbEventValue->setValue(_objTimeProfile.eventValue);
        on_rbEventDriven_clicked();

    }

}

void TimeProfile::editTimeProfile(int id){

    objTimeProfile _objTimeProfile;

    _objTimeProfile._id = id;

    if(ui->txtProfileName->text().isEmpty()){
        QMessageBox::critical(this, tr("Time Profile"), tr("Please Type Profile Name"));
        return;
    }
    else{
       _objTimeProfile.name = ui->txtProfileName->text();
    }

    if(ui->rbPeriodic->isChecked()){
        if(ui->sbPeriodicInterval->value() == 0){
            QMessageBox::critical(this, tr("Time Profile"), tr("Interval value must be greater than zero"));
            return;
        }
        else{
           _objTimeProfile.type = "Periodic";
           _objTimeProfile.interval = ui->sbPeriodicInterval->value();
           _objTimeProfile.randomFrom = 0;
           _objTimeProfile.randomTo   = 0;
           _objTimeProfile.eventCondition = "";
           _objTimeProfile.eventValue = 0;


        }

    }
    else{
        if(ui->sbEventRandomTo->value() == 0){
            QMessageBox::critical(this, tr("Time Profile"), tr("In Random Value 'To' can't be zero."));
            return;
        }
        else if(ui->sbEventRandomFrom->value() > ui->sbEventRandomTo->value()){
            QMessageBox::critical(this, tr("Time Profile"), tr("In Random Value 'From' must be less than 'To'."));
            return;
        }
       // else if(ui->sbEventValue->value() <= ui->sbEventRandomFrom->value()){
       //     QMessageBox::critical(this, tr("Time Profile"), tr("Event value must be between 'From' and 'To'."));
       //     return;
       //}
        else{
            _objTimeProfile.type = "Event Driven";
            _objTimeProfile.randomFrom = ui->sbEventRandomFrom->value();
            _objTimeProfile.randomTo   = ui->sbEventRandomTo->value();
            //_objTimeProfile.eventCondition = ui->cbEventCondition->currentText();
            _objTimeProfile.eventValue = ui->sbEventValue->value();
            _objTimeProfile.interval = 0;

        }

    }


    dlTimeProfile *_dlTimeProfile = new dlTimeProfile ();
    int result = _dlTimeProfile->UpdateTimeProfile(_objTimeProfile);
    qDebug() << result;
    if(result > 0)
    {
        QMessageBox::information(this, tr(""), tr("Successfully updated."));
        this->close();
    }
    else
    {
        QMessageBox::critical(this, tr(""), tr("Update error."));
    }

}


void TimeProfile::on_rbEventDriven_clicked()
{
    try{
    //qDebug() << "on_rbEventDriven_clicked()";
    ui->gbPeriodic->setDisabled(true);
    ui->gbEventDriven->setEnabled(true);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void TimeProfile::on_rbPeriodic_clicked()
{
    try{
    //qDebug() << "on_rbRecursive_clicked()";
    ui->gbPeriodic->setEnabled(true);
    ui->gbEventDriven->setDisabled(true);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}
