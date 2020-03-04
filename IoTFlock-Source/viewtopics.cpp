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
#include "viewtopics.h"
#include "ui_viewtopics.h"
#include "topics.h"
#include <dltopic.h>
#include <QDebug>
#include <QList>
#include <QMessageBox>
ViewTopics::ViewTopics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTopics)
{
    try {
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    QStringList titles;
    titles<<"ID"<<"Existing Topics"<<"Edit"<<"Delete";
    ui->tableWidget->setHorizontalHeaderLabels(titles);
    ui->tableWidget->setColumnWidth(0, 25);
    ui->tableWidget->setColumnWidth(1, 455);
    ui->tableWidget->setColumnWidth(2, 50);
    ui->tableWidget->setColumnWidth(3, 50);
    ui->tableWidget->setColumnHidden(0,true);
    ui->tableWidget->setAlternatingRowColors(true);

    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

ViewTopics::~ViewTopics()
{
    delete ui;
}

void ViewTopics::on_btnNewTopic_clicked()
{
    try{
    Topics topics;
    topics.setModal(true);
    topics.exec();
    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}


void ViewTopics::editRow()
{
    try{
    int row = ui->tableWidget->currentRow();
    Topics topics(this, "EDIT", ui->tableWidget->item(row,0)->text().toInt());
    topics.setModal(true);
    topics.exec();
    bindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}


void ViewTopics::deleteRow()
{
try{
    int row = ui->tableWidget->currentRow();
    int topicID = ui->tableWidget->item(row,0)->text().toInt();
    dlTopic _dlTopic;
    _dlTopic.DelTopic(topicID);
     ui->tableWidget->removeRow(row);

    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void ViewTopics::bindData(){

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    dlTopic _dlTopic;
    QList<objTopic> lstTopics = _dlTopic.GetTopicList();

    foreach(objTopic _objTopic, lstTopics)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int f1=ui->tableWidget->rowCount()-1;

        qDebug() << _objTopic._id;
        ui->tableWidget->setItem(f1, ID, new QTableWidgetItem(QString::number(_objTopic._id)));

        ui->tableWidget->setItem(f1, TOPIC_LIST, new QTableWidgetItem(_objTopic.name));

        QPushButton *edit = new QPushButton("",this);
        edit->setFixedWidth(50);
        edit->setFixedHeight(30);
        QPixmap pixmapEdit(_constants.PATH_EDITICON);
        QIcon EditButtonIcon(pixmapEdit);
        edit->setIcon(EditButtonIcon);
        edit->setIconSize(QSize(30, 20));
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,2,edit);
        connect(edit, &QPushButton::clicked, this, &ViewTopics::editRow);

        QPushButton *del = new QPushButton("",this);
        del->setFixedWidth(50);
        del->setFixedHeight(30);
        QPixmap pixmapDel(_constants.PATH_DELETEICON);
        QIcon DelButtonIcon(pixmapDel);
        del->setIcon(DelButtonIcon);
        del->setIconSize(QSize(30, 20));
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,3,del);
        connect(del, &QPushButton::clicked, this, &ViewTopics::deleteRow);
    }
}
