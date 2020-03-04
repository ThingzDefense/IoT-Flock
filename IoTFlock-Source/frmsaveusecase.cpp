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
#include "frmsaveusecase.h"
#include "ui_frmsaveusecase.h"
#include <QDebug>
#include <QMessageBox>
#include<dlusecase.h>

frmSaveUseCase::frmSaveUseCase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmSaveUseCase)
{
 try{
    ui->setupUi(this);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }

frmSaveUseCase::~frmSaveUseCase()
{
    delete ui;
}

void frmSaveUseCase::on_btnSave_clicked()
{
try{
    QString useCaseName = ui->txtName->text();

    if(useCaseName.isEmpty()){
        QMessageBox::critical(this, tr("Save"), tr("Please Type Use Case Name"));
        return;
    }
    else
    {
        dlUseCase _dlUseCase;
        objUseCase _objUseCase;
        _objUseCase.name = useCaseName;
        if(!_dlUseCase.isUseCaseExists(_objUseCase))
        {
            QString _useCaseName = ui->txtName->text();

            dlUseCase _dlUseCase;
            objUseCase _objUseCase;
            _objUseCase.name = _useCaseName;
          useCaseID = _dlUseCase.Insert(_objUseCase);
           this->close();
           this->setResult(1);
        }
        else
        {
            QMessageBox::critical(this, tr("Save"), tr("Name already exists."));
            return;
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

void frmSaveUseCase::on_btnCancel_clicked()
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
