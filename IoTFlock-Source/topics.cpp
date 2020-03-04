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
#include "topics.h"
#include "ui_topics.h"
#include <QDebug>
#include <dltopic.h>
#include <qmessagebox.h>

Topics::Topics(QWidget *parent, QString FormType, int id) :
    QDialog(parent),
    ui(new Ui::Topics)
{
    try {

    QStringList titles;
    ui->setupUi(this);
    _FormType = FormType;
    _id = id;

    if(FormType == "EDIT"){
        fillTopics();
    }

    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

Topics::~Topics()
{
    delete ui;
}

void Topics::on_btnAdd_clicked()
{
/*
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    int f1=ui->tableWidget->rowCount()-1;
    QString list_item = ui->txtTopic->text();
    ui->tableWidget->setItem(f1,TOPIC_LIST,new QTableWidgetItem(list_item));
    QPushButton *b = new QPushButton("del",this);
    b->setFixedWidth(40);
    b->setFixedHeight(23);

    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,1,b);
    //ui->tableWidget->set
    connect(b, &QPushButton::clicked, this, &Topics::deleteRow);

    topicList.append(list_item);
    qDebug() << topicList;
    //qDebug() << topicList.count();
    */

}


void Topics::deleteRow()
{
/*
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
    topicList.removeAt(row);
    qDebug() << topicList;
    //qDebug() << topicList.count();
    */

}

void Topics::on_btnSave_clicked()
{
    try{
    if(_FormType == "SAVE"){
        saveTopic();
    }
    else if (_FormType == "EDIT"){
        editTopic(_id);
    }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }

}

void Topics::on_btnCancel_clicked()
{try{
    this->close();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void Topics::saveTopic(){

    if(ui->txtTopic->text().isEmpty()){
        QMessageBox::critical(this, tr("Topic"), tr("Please Type Topic Name"));
        return;
    }

    objTopic _objTopic;
    _objTopic.name =  ui->txtTopic->text();
    dlTopic _dlTopic ;
    int result = _dlTopic.Insert(_objTopic);
    qDebug()<<result;
    if(result > 0)
    {
        ui->txtTopic->setText("");
        QMessageBox::information(this, tr(""), tr("Successfully inserted."));
    }
    else
    {
        QMessageBox::critical(this, tr(""), tr("Insertion error."));
    }

}


void Topics::editTopic(int id){

    if(ui->txtTopic->text().isEmpty()){
        QMessageBox::critical(this, tr("Topic"), tr("Please Type Topic Name"));
        return;
    }

    dlTopic _dlTopic;
    objTopic _objTopic;
    _objTopic._id = id;
    _objTopic.name = ui->txtTopic->text();

    if(_dlTopic.UpdateTopic(_objTopic)){
        QMessageBox::information(this, tr(""), tr("Successfully updated."));
        this->close();
    }
    else{
        QMessageBox::critical(this, tr(""), tr("Update error."));
    }

}


void Topics::fillTopics(){

    dlTopic _dlTopic;
    objTopic _objTopic = _dlTopic.GetTopic(_id);

    //qDebug() << "fillTopic name" <<_objTopic.name;
    ui->txtTopic->setText(_objTopic.name);

}
