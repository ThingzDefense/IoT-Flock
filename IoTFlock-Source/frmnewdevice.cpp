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
#include "frmnewdevice.h"
#include "ui_frmnewdevice.h"
#include "dldevicetemplate.h"
#include<QMessageBox>
#include "topics.h"
#include "timeprofile.h"
#include "dataprofile.h"
#include<dltopic.h>
#include<dltimeprofile.h>
#include<dldataprofile.h>
#include<dldevicepublishdata.h>
#include<dldevicesubscribedata.h>
#include<dldevicehttpdata.h>
#include<dldevicecoapdata.h>
//#include<dlfrmnewdevicetemplateview.h>
#include<dldevicetemplate.h>

#include<QPushButton>
#include<qdebug.h>

frmnewDevice::frmnewDevice(QWidget *parent, QString _FormType, int _id) :
    QDialog(parent),
    ui(new Ui::frmnewDevice)
{
    ui->setupUi(this);

       FormType = _FormType;
       id = -1;
       // FormType = "EDIT";

     // isLoadingDone = false;
      // FillFormData();
      // SetFormLayout();
       fillSelectTemplateDropdown();
      //isLoadingDone = true;


}


void frmnewDevice::FillFormData()
{
   // fillSelectTemplateDropdown();
    fillProfileDropdown();
    fillDataProfileDropdown();
    fillTimeProfileDropdown();
    if(FormType == "EDIT")
    {
        fillForm();
        fillTbWidgetMQTTSubscribe();
        fillTbWidgetMQTTPublish();
        fillTbWidgetCoap();
        fillTbWidgetHttp();
    }

}


void frmnewDevice::SetFormLayout()
{
    layoutTbWidgetMQTTSubscribe();
    layoutTbWidgetMQTTPublish();
    layoutTbWidgetCoap();
    layoutTbWidgetHttp();
}


//Fire when form is saving
void frmnewDevice::on_btnCreate_clicked()
{
    if(!validateForm())
        return;

 //   if(FormType == "EDIT")
 //       Update();
 //   else
        Save();
}

void frmnewDevice::Save()
{

   //general tab information
   _objDevice.protocol = ui->cmbProtocol->currentText();
   _objDevice.sHostName = ui->txtIPAddress->text();
   _objDevice.IPCount = ui->sbNumofDevices->value();

   //mqtt basic setting
   _objDevice.hostName = ui->txtBrokerIP->text();
   if(ui->rbMQTTRegular->isChecked())
    {
       _objDevice.portType = "REGULAR";
       _objDevice.port = (ui->sbBrokerPortRegular->value());
    }
   if(ui->rbMQTTTLS->isChecked())
    {
       _objDevice.portType = "TTTLS";
       _objDevice.port = ui->sbBrokerportTLS->value();
    }

   _objDevice.isAuthenticationRequire = ui->isBrookerAuthentication->isChecked();
   if(_objDevice.isAuthenticationRequire)
   {
    _objDevice.userName = ui->txtBrokerUserName->text();
    _objDevice.password = ui->txtBrokerPassword->text();
   }
    //coap basic setting
   _objDevice.hostName = ui->txtCoapUrl->text();

   //http basic setting
   _objDevice.hostName = ui->txtHttpUrl->text();


   if(_objDevice.protocol == "MQTT")
   {
       _objDevice.lstSubTopic.clear();
       for(int i=0;i<ui->tbWidgetSubscribeTopic->rowCount();i++)
       {
           objDeviceSubscribeData _objDeviceSubscribeData;
           _objDeviceSubscribeData.topicName = ui->tbWidgetSubscribeTopic->item(i,0)->text().toInt();
           _objDevice.lstSubTopic.append(_objDeviceSubscribeData);
       }

       _objDevice.lstPubTopic.clear();
        for(int j=0; j<ui->tbWidgetMQTTPublish->rowCount();j++)
        {
             objDevicePublishData _objDevicePublishData;
             dlTimeProfile _dlTimeProfile;
           _objDevicePublishData._objTimeProfile = _dlTimeProfile.GetTimeProfile(ui->tbWidgetMQTTPublish->item(j,2)->text().toInt());
            dlDataProfile _dlDataProfile;
            _objDevicePublishData._objDataProfile = _dlDataProfile.GetDataProfile(ui->tbWidgetMQTTPublish->item(j,1)->text().toInt());
            _objDevice.lstPubTopic.append(_objDevicePublishData);
        }
   }
   else if(_objDevice.protocol == "COAP")
   {

   }
   else if(_objDevice.protocol == "HTTP")
   {

   }

   this->close();
   this->setResult(1);
}

void frmnewDevice::ClearForm()
{

    //this->ui->txtDeviceName->clear();
    this->ui->cmbProtocol->setCurrentIndex(0);
    this->ui->txtIPAddress->clear();
    this->ui->sbNumofDevices->setValue(1);

    this->ui->txtBrokerIP->clear();
    this->ui->sbBrokerPortRegular->setValue(1883);
    this->ui->sbBrokerportTLS->setValue(1883);
    this->ui->txtBrokerUserName->clear();
    this->ui->txtBrokerPassword->clear();
    this->ui->isBrookerAuthentication->setChecked(0);
    this->ui->rbMQTTRegular->setChecked(1);
    this->ui->rbMQTTTLS->setChecked(0);

    this->ui->cmbSubscribeTopic->setCurrentIndex(0);
    //this->ui->tbWidgetSubscribeTopic->setRowCount(0);


    this->ui->cmbMQTTPublishTopic->setCurrentIndex(0);
    this->ui->cmbMQTTQoS->setCurrentIndex(0);
    this->ui->cmbMQTTPublishDataProfile->setCurrentIndex(0);
    this->ui->cmbMQTTPublishTimeProfile->setCurrentIndex(0);
    this->ui->tbWidgetMQTTPublish->setRowCount(0);

    this->ui->txtCoapUrl->clear();
   this->ui->cmbCoapCommand->setCurrentIndex(0);
   this->ui->cmbCoapDataProfile->setCurrentIndex(0);
   this->ui->cmbCoapTimeProfile->setCurrentIndex(0);
   this->ui->tbWidgetCoap->setRowCount(0);
    //this->ui->txtCoapTimeInterval->clear();

   this->ui->txtHttpUrl->clear();
  this->ui->cmbHttpCommand->setCurrentIndex(0);
  this->ui->cmbHttpDataProfile->setCurrentIndex(0);
  this->ui->cmbHttpTimeProfile->setCurrentIndex(0);
  this->ui->tbWidgetHttp->setRowCount(0);

}

void frmnewDevice::on_btnClose_clicked()
{
    this->close();

}

void frmnewDevice::fillProfileDropdown()
{
    dlTopic *_dlTopic = new dlTopic();
    QList<objTopic> lstObjTopic= _dlTopic->GetTopicList();
    foreach(objTopic obj,lstObjTopic)
    {
       ui->cmbSubscribeTopic->addItem(obj.name,QVariant(obj._id));
        ui->cmbMQTTPublishTopic->addItem(obj.name,QVariant(obj._id));
    }
}

void frmnewDevice::fillSelectTemplateDropdown()
{
    dlDeviceTemplate *_dlDeviceTemplate = new dlDeviceTemplate();
    QList<objDeviceTemplate> lstObjDeviceTemplate = _dlDeviceTemplate->GetDeviceList();

    foreach(objDeviceTemplate _objDeviceTemplate, lstObjDeviceTemplate)
    {
        ui->cmbSelectTemplate->addItem(_objDeviceTemplate.deviceName,QVariant(_objDeviceTemplate._id));

    }

}


void frmnewDevice::fillTimeProfileDropdown()
{
    dlTimeProfile *_dlTimeProfile = new dlTimeProfile();
    QList<objTimeProfile> lstObjTimeProfile = _dlTimeProfile->GetTimeProfileList();
    foreach(objTimeProfile obj, lstObjTimeProfile)
    {
        ui->cmbMQTTPublishTimeProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbCoapTimeProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbHttpTimeProfile->addItem(obj.name, QVariant(obj._id));

    }
}
void frmnewDevice::fillDataProfileDropdown()
{
    dlDataProfile *_dlDataProfile = new dlDataProfile();
    QList<objDataProfile> lstObjDataProfile = _dlDataProfile->GetDataProfileList();
    foreach(objDataProfile obj, lstObjDataProfile)
    {
        ui->cmbMQTTPublishDataProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbCoapDataProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbHttpDataProfile->addItem(obj.name, QVariant(obj._id));

    }
}

void frmnewDevice::fillForm()
{
    dlDeviceTemplate *_dlDeviceTemplate = new dlDeviceTemplate();
    objDeviceTemplate _objDeviceTemplate = _dlDeviceTemplate->GetDeviceList(id);
   // QList<objDeviceTemplate> lstObjDataProfile = _dlDeviceTemplate->GetDeviceList(_id);
    //objDeviceTemplate _objDeviceTemplate = lstObjDataProfile; //===================================


    //this->ui->txtDeviceName->setText(_objDeviceTemplate.deviceName);
    //this->ui->txtDeviceDescription->setText(_objDeviceTemplate.deviceDescription);
    this->ui->txtIPAddress->setText(_objDeviceTemplate.IPAddress);
    this->ui->sbNumofDevices->setValue(_objDeviceTemplate.NumofDevices);

    this->ui->txtBrokerIP->setText(_objDeviceTemplate.brokerIP);

    if (_objDeviceTemplate.isRegularPort == true)
    {
      this->ui->sbBrokerPortRegular->setValue(_objDeviceTemplate.portNO);
        this->ui->rbMQTTRegular->setChecked(1);
        this->ui->rbMQTTTLS->setChecked(0);
    }
    else
    {
        this->ui->sbBrokerportTLS->setValue(_objDeviceTemplate.portNO);
        this->ui->rbMQTTRegular->setChecked(0);
        this->ui->rbMQTTTLS->setChecked(1);
    }

    this->ui->txtBrokerUserName->setText(_objDeviceTemplate.brokerUserName);
    this->ui->txtBrokerPassword->setText(_objDeviceTemplate.brokerPassword);
    this->ui->isBrookerAuthentication->setChecked(1);

    this->ui->tbWidgetSubscribeTopic->setRowCount(0);
    this->ui->tbWidgetMQTTPublish->setRowCount(0);

    this->ui->txtCoapUrl->setText(_objDeviceTemplate.coapURL);
    this->ui->txtHttpUrl->setText(_objDeviceTemplate.httpURL);


}

void frmnewDevice::fillTbWidgetMQTTSubscribe()
{


    dlDeviceSubscribeData _dlDeviceSubscribeData;
    QList<objDeviceSubscribeData> _lstObjDeviceSubscribeData = _dlDeviceSubscribeData.fillTbWidgetMQTTSubscribe(id);
    ui->tbWidgetSubscribeTopic->setColumnCount(3);
//    ui->tbWidgetSubscribeTopic->setRowCount(0);
    foreach(objDeviceSubscribeData _objDeviceSubscribeData,_lstObjDeviceSubscribeData)
    {
        ui->tbWidgetSubscribeTopic->insertRow(ui->tbWidgetSubscribeTopic->rowCount());
        int rowNum=ui->tbWidgetSubscribeTopic->rowCount()-1;

        ui->tbWidgetSubscribeTopic->setItem(rowNum,0,new QTableWidgetItem(_objDeviceSubscribeData.topicID));
        ui->tbWidgetSubscribeTopic->setItem(rowNum,1,new QTableWidgetItem(_objDeviceSubscribeData.topicName));

        QPushButton *bt=new QPushButton("X");
        bt->setFixedHeight(30);
        bt->setFixedWidth(50);
        ui->tbWidgetSubscribeTopic->setCellWidget(rowNum,2,bt);
        connect(bt,&QPushButton::clicked,this,&frmnewDevice::removeSubscribeRow);


    }
 }

void frmnewDevice::fillTbWidgetMQTTPublish()
{
    dlDevicePublishData _dlDevicePublishData;
    QList<objDevicePublishData> _lstObjDevicePublishData = _dlDevicePublishData.GetDevicePublishData(id);
    ui->tbWidgetMQTTPublish->setColumnCount(8);
    // titles<<"TopicID"<<"DataProfileID"<<"TimeProfileID"<<"Topic"<<"QoS"<<"Data Profile"<<"Time Profile"<<" ";
    foreach(objDevicePublishData _objDevicePublishData, _lstObjDevicePublishData)
    {
    this->ui->tbWidgetMQTTPublish->insertRow(ui->tbWidgetMQTTPublish->rowCount());
    int rowNum=this->ui->tbWidgetMQTTPublish->rowCount()-1;

    //ui->tbWidegtViewDB->setItem(f1, ID, new QTableWidgetItem(QString::number(_objFrmNewDeviceTemplateView._id)));
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,0,new QTableWidgetItem(_objDevicePublishData.topicID) ); //_id
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,1,new QTableWidgetItem(_objDevicePublishData.dataProfileID) );
     //ui->tbWidgetMQTTPublish->setItem(rowNum,2,new QTableWidgetItem(timeProfileID) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,2,new QTableWidgetItem(_objDevicePublishData.timeProfileID) );

     this->ui->tbWidgetMQTTPublish->setItem(rowNum,3,new QTableWidgetItem(_objDevicePublishData.topic) ); //_id
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,4,new QTableWidgetItem(QString::number(_objDevicePublishData.QoS)) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,5,new QTableWidgetItem(_objDevicePublishData.dataprofile) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,6,new QTableWidgetItem(_objDevicePublishData.timeprofile) );

     QPushButton *bt=new QPushButton("X",this);
     bt->setFixedHeight(30);
     bt->setFixedWidth(50);

     this->ui->tbWidgetMQTTPublish->setCellWidget(rowNum,7,bt);
     connect(bt,&QPushButton::clicked,this,&frmnewDevice::removePublishRow);
    }

}

void frmnewDevice::fillTbWidgetCoap()
{
    dlDeviceCoapData _dlDeviceCoapData;
    QList<objDeviceCoapData> _lstObjDeviceCoapData = _dlDeviceCoapData.GetDeviceCoapData(id);

    ui->tbWidgetCoap->setColumnCount(4);

    //titles<<"Command"<<"Time Profile"<<"Data Profile";
    foreach(objDeviceCoapData _objDeviceCoapData, _lstObjDeviceCoapData)
    {
        this->ui->tbWidgetCoap->insertRow(ui->tbWidgetCoap->rowCount());
        int rowNum = ui->tbWidgetCoap->rowCount()-1;

        //this->ui->tbWidgetCoap->setItem(rowNum,0,new QTableWidgetItem(_objDeviceCoapData.coapUrl) );
        this->ui->tbWidgetCoap->setItem(rowNum,0,new QTableWidgetItem(_objDeviceCoapData.coapCommand) );
        this->ui->tbWidgetCoap->setItem(rowNum,1,new QTableWidgetItem(_objDeviceCoapData.timeprofile) );
        this->ui->tbWidgetCoap->setItem(rowNum,2,new QTableWidgetItem(_objDeviceCoapData.dataprofile) );

        QPushButton *bt=new QPushButton("X",this);
        bt->setFixedHeight(30);
        bt->setFixedWidth(50);

        this->ui->tbWidgetCoap->setCellWidget(rowNum,3,bt);
        connect(bt,&QPushButton::clicked,this,&frmnewDevice::removeCoapRow);
    }

}

void frmnewDevice::fillTbWidgetHttp()
{
    dlDeviceHttpData _dlDeviceHttpData;
    QList<objDeviceHttpData> _lstObjDeviceHttpData = _dlDeviceHttpData.GetDeviceHttpData(id);

    ui->tbWidgetHttp->setColumnCount(4);

    //titles<<"Command"<<"Time Profile"<<"Data Profile";
    foreach(objDeviceHttpData _objDeviceHttpData, _lstObjDeviceHttpData)
    {
        this->ui->tbWidgetHttp->insertRow(ui->tbWidgetHttp->rowCount());
        int rowNum = ui->tbWidgetHttp->rowCount()-1;

        this->ui->tbWidgetHttp->setItem(rowNum,0,new QTableWidgetItem(_objDeviceHttpData.httpCommand) );
        this->ui->tbWidgetHttp->setItem(rowNum,1,new QTableWidgetItem(_objDeviceHttpData.timeprofile) );
        this->ui->tbWidgetHttp->setItem(rowNum,2,new QTableWidgetItem(_objDeviceHttpData.dataprofile) );

        QPushButton *bt=new QPushButton("X",this);
        bt->setFixedHeight(30);
        bt->setFixedWidth(50);

        this->ui->tbWidgetHttp->setCellWidget(rowNum,3,bt);
        connect(bt,&QPushButton::clicked,this,&frmnewDevice::removeHttpRow);
    }

}


void frmnewDevice::Update()
{

    objDeviceTemplate _objDeviceTemplate;
   //_objDeviceTemplate.deviceName = ui->txtDeviceName->text();
   //_objDeviceTemplate.deviceDescription = ui->txtDeviceDescription->text(); //uncomment if require

   //general tab information
   _objDeviceTemplate.deviceProtocol = ui->cmbProtocol->currentText();
   _objDeviceTemplate.IPAddress = ui->txtIPAddress->text();
   _objDeviceTemplate.NumofDevices = ui->sbNumofDevices->value();

   //mqtt basic setting
   _objDeviceTemplate.brokerIP = ui->txtBrokerIP->text();
   if(ui->rbMQTTRegular->isChecked())
    {
       _objDeviceTemplate.isRegularPort = true;
       _objDeviceTemplate.portNO = (ui->sbBrokerPortRegular->value());
   }
       if(ui->rbMQTTTLS->isChecked())
       {
      _objDeviceTemplate.isRegularPort = false;
       _objDeviceTemplate.portNO = ui->sbBrokerportTLS->value();
       }


   _objDeviceTemplate.brokerUserName = ui->txtBrokerUserName->text();
   _objDeviceTemplate.brokerPassword = ui->txtBrokerPassword->text();

    //coap basic setting
   _objDeviceTemplate.coapURL = ui->txtCoapUrl->text();

   //http basic setting
   _objDeviceTemplate.httpURL = ui->txtHttpUrl->text();

   //saving parent table "device template"
   dlDeviceTemplate *_dlDeviceTemplate = new dlDeviceTemplate();
   bool templateID = _dlDeviceTemplate->UpdateDeviceTemplate(_objDeviceTemplate);

   if(templateID)
   {
       //delete subscriber data
       dlDeviceSubscribeData _dlDeviceSubscribeData;
       bool _lstObjDeviceSubscribeData = _dlDeviceSubscribeData.DelSubscribeData(id);

       //saving mqtt subscribe details
       for(int i=0;i<ui->tbWidgetSubscribeTopic->rowCount();i++)
       {
           objDeviceSubscribeData _objDeviceSubscribeData;
           _objDeviceSubscribeData.topicID = ui->tbWidgetSubscribeTopic->item(i,0)->text().toInt();
           _objDeviceSubscribeData.deviceTemplateID = id;
            dlDeviceSubscribeData *_dlDeviceSubscribeData = new dlDeviceSubscribeData();
            _dlDeviceSubscribeData->Insert(_objDeviceSubscribeData);
       }

       //delete publish data
       dlDevicePublishData _dlDevicePublishData;
       bool _lstObjDevicePublishData = _dlDevicePublishData.DelPublishData(id);

       //save mqtt publish details
       for(int j=0; j<ui->tbWidgetMQTTPublish->rowCount();j++)
       {
            objDevicePublishData _objDevicePublishData;
           _objDevicePublishData.deviceTemplateID = id;
           _objDevicePublishData.topicID = ui->tbWidgetSubscribeTopic->item(j,0)->text().toInt();
           _objDevicePublishData.QoS = ui->cmbMQTTQoS->currentText().toInt();
          _objDevicePublishData.dataProfileID = ui->cmbMQTTPublishDataProfile->currentData().toInt();
          _objDevicePublishData.timeProfileID = ui->cmbMQTTPublishTimeProfile->currentData().toInt();
          dlDevicePublishData * _dlDevicePublishData = new dlDevicePublishData();
          _dlDevicePublishData->Insert(_objDevicePublishData);
       }

       //delete coap data
       dlDeviceCoapData _dlDeviceCoapData;
       bool _lstObjDeviceCoapData = _dlDeviceCoapData.DelCoapData(id);

       //save coap detials
       for(int j=0; j<ui->tbWidgetCoap->rowCount();j++)
       {
        objDeviceCoapData _objDeviceCoapData;
       _objDeviceCoapData.deviceTemplateID = id;
       _objDeviceCoapData.coapCommand = ui->cmbCoapCommand->currentText();
      _objDeviceCoapData.coapDataProfileID = ui->cmbCoapDataProfile->currentData().toInt();
      _objDeviceCoapData.coapTimeProfileID = ui->cmbCoapTimeProfile->currentData().toInt();
      dlDeviceCoapData * _dlDeviceCoapData = new dlDeviceCoapData();
      _dlDeviceCoapData->Insert(_objDeviceCoapData);
       }

       //delete http data
       dlDeviceHttpData _dlDeviceHttpData;
       bool _lstObjDeviceHttpData = _dlDeviceHttpData.DelHttpData(id);

       //save http details
       for(int j=0; j<ui->tbWidgetHttp->rowCount();j++)
       {
           objDeviceHttpData _objDeviceHttpData;
           _objDeviceHttpData.deviceTemplateID = id;
           _objDeviceHttpData.httpCommand = ui->cmbHttpCommand->currentText();
          _objDeviceHttpData.httpDataProfileID = ui->cmbHttpDataProfile->currentData().toInt();
          _objDeviceHttpData.httpTimeProfileID = ui->cmbHttpTimeProfile->currentData().toInt();
          dlDeviceHttpData * _dlDeviceHttpData = new dlDeviceHttpData();
          _dlDeviceHttpData->Insert(_objDeviceHttpData);
       }
      QMessageBox::information(this,tr("Query Info"),tr("Updated Successfully"));
      this->close();
    }
   else {
       QMessageBox::information(this,tr("Query Info"),tr("Error Occured"));
   }




}
//===========================================================================================
void frmnewDevice::on_btnAddSubscribeTopic_clicked()
{
    ui->tbWidgetSubscribeTopic->insertRow(ui->tbWidgetSubscribeTopic->rowCount());
    int rowNum=ui->tbWidgetSubscribeTopic->rowCount()-1;
    QString topicID = ui->cmbSubscribeTopic->currentData().toString();  ////////////////////////
    QString list_item = ui->cmbSubscribeTopic->currentText(); //topiclist

    ui->tbWidgetSubscribeTopic->setItem(rowNum,0,new QTableWidgetItem(topicID) );
    ui->tbWidgetSubscribeTopic->setItem(rowNum,1,new QTableWidgetItem(list_item) );



    QPushButton *bt=new QPushButton("X",this);
    bt->setFixedHeight(30);
    bt->setFixedWidth(50);

    ui->tbWidgetSubscribeTopic->setCellWidget(rowNum,2,bt);
    connect(bt,&QPushButton::clicked,this,&frmnewDevice::removeSubscribeRow);
  // topicList.append(list_item);

}


void frmnewDevice::on_btnMQTTPublish_clicked()  //(+ btn) MQTT Publish
{

    ui->tbWidgetMQTTPublish->insertRow(ui->tbWidgetMQTTPublish->rowCount());
    int rowNum=ui->tbWidgetMQTTPublish->rowCount()-1;
    QString list_item = ui->cmbMQTTPublishTopic->currentText(); //topiclist
    QString list_item2 = ui->cmbMQTTQoS->currentText();
    QString list_item3 = ui->cmbMQTTPublishDataProfile->currentText();
    QString list_item4 = ui->cmbMQTTPublishTimeProfile->currentText();

    QString topicID = ui->cmbMQTTPublishTopic->currentData().toString();

    QString dataProfileID = ui->cmbMQTTPublishDataProfile->currentData().toString();
    QString timeProfileID = ui->cmbMQTTPublishTimeProfile->currentData().toString();

     ui->tbWidgetMQTTPublish->setItem(rowNum,0,new QTableWidgetItem(topicID) ); //_id
     ui->tbWidgetMQTTPublish->setItem(rowNum,1,new QTableWidgetItem(dataProfileID) );
   ui->tbWidgetMQTTPublish->setItem(rowNum,2,new QTableWidgetItem(timeProfileID) );

   ui->tbWidgetMQTTPublish->setItem(rowNum,3,new QTableWidgetItem(list_item) );
   ui->tbWidgetMQTTPublish->setItem(rowNum,4,new QTableWidgetItem(list_item2) );
   ui->tbWidgetMQTTPublish->setItem(rowNum,5,new QTableWidgetItem(list_item3) );
   ui->tbWidgetMQTTPublish->setItem(rowNum,6,new QTableWidgetItem(list_item4) );


    QPushButton *bt=new QPushButton("X",this);
    bt->setFixedHeight(30);
    bt->setFixedWidth(50);

    ui->tbWidgetMQTTPublish->setCellWidget(rowNum,7,bt);
    connect(bt,&QPushButton::clicked,this,&frmnewDevice::removePublishRow);
  // topicList.append(list_item);
}

void frmnewDevice::on_btnCoapAdd_clicked()
{
    ui->tbWidgetCoap->insertRow(ui->tbWidgetCoap->rowCount());
    int rowNum=ui->tbWidgetCoap->rowCount()-1;

     QString coapUrl = ui->txtCoapUrl->text();
    QString coapCommand = ui->cmbCoapCommand->currentText(); //topiclist
    QString coapDataProfile= ui->cmbCoapDataProfile->currentText();
    QString coapTimeProfile = ui->cmbCoapTimeProfile->currentText();



     //ui->tbWidgetCoap->setItem(rowNum,0,new QTableWidgetItem(coapUrl) ); //_id
     ui->tbWidgetCoap->setItem(rowNum,0,new QTableWidgetItem(coapCommand) );
     ui->tbWidgetCoap->setItem(rowNum,1,new QTableWidgetItem(coapDataProfile) );
     ui->tbWidgetCoap->setItem(rowNum,2,new QTableWidgetItem(coapDataProfile) );


   QPushButton *bt=new QPushButton("X",this);
   bt->setFixedHeight(30);
   bt->setFixedWidth(50);

   this->ui->tbWidgetCoap->setCellWidget(rowNum,3,bt);
   connect(bt,&QPushButton::clicked,this,&frmnewDevice::removeCoapRow);


}

void frmnewDevice::on_btnHttpAdd_clicked()
{
    ui->tbWidgetHttp->insertRow(ui->tbWidgetHttp->rowCount());
    int rowNum=ui->tbWidgetHttp->rowCount()-1;

     QString httpUrl = ui->txtHttpUrl->text();
    QString httpCommand = ui->cmbHttpCommand->currentText(); //topiclist
    QString httpDataProfile= ui->cmbHttpDataProfile->currentText();
    QString httpTimeProfile = ui->cmbHttpTimeProfile->currentText();



  //   ui->tbWidgetHttp->setItem(rowNum,0,new QTableWidgetItem(httpUrl) ); //_id
     ui->tbWidgetHttp->setItem(rowNum,0,new QTableWidgetItem(httpCommand) );
   ui->tbWidgetHttp->setItem(rowNum,1,new QTableWidgetItem(httpDataProfile) );
   ui->tbWidgetHttp->setItem(rowNum,2,new QTableWidgetItem(httpDataProfile) );

   QPushButton *bt=new QPushButton("X",this);
   bt->setFixedHeight(30);
   bt->setFixedWidth(50);

   this->ui->tbWidgetHttp->setCellWidget(rowNum,3,bt);
   connect(bt,&QPushButton::clicked,this,&frmnewDevice::removeHttpRow);

}

void frmnewDevice::removeSubscribeRow()  //Subs Action Btn
{
    int rowNum=ui->tbWidgetSubscribeTopic->currentRow();
    ui->tbWidgetSubscribeTopic->removeRow(rowNum);

}

void frmnewDevice::removePublishRow()
{
    int rowNum=ui->tbWidgetMQTTPublish->currentRow();
    ui->tbWidgetMQTTPublish->removeRow(rowNum);

}
void frmnewDevice::removeCoapRow()
{
    int rowNum=ui->tbWidgetCoap->currentRow();
    ui->tbWidgetCoap->removeRow(rowNum);

}
void frmnewDevice::removeHttpRow()
{
    int rowNum=ui->tbWidgetHttp->currentRow();
    ui->tbWidgetHttp->removeRow(rowNum);

}


void frmnewDevice::layoutTbWidgetMQTTPublish()
{
    QStringList titles;
   // ui->btnMQTTPublish->setFixedWidth(40);
    ui->tbWidgetMQTTPublish->setColumnCount(8);
    titles<<"TopicID"<<"DataProfileID"<<"TimeProfileID"<<"Topic"<<"QoS"<<"Data Profile"<<"Time Profile"<<" ";
    ui->tbWidgetMQTTPublish->setHorizontalHeaderLabels(titles);

    ui->tbWidgetMQTTPublish->setColumnWidth(3,170);
    ui->tbWidgetMQTTPublish->setColumnWidth(4,50);
    ui->tbWidgetMQTTPublish->setColumnWidth(5,100);
    ui->tbWidgetMQTTPublish->setColumnWidth(6,100);
    ui->tbWidgetMQTTPublish->setColumnWidth(7,50);

    ui->tbWidgetMQTTPublish->setColumnHidden(0,true);
    ui->tbWidgetMQTTPublish->setColumnHidden(1,true);
    ui->tbWidgetMQTTPublish->setColumnHidden(2,true);


    //ui->tbWidgetMQTTPublish->horizontalHeader()->setVisible(0);
   // ui->tbWidgetMQTTPublish->horizontalHeader()->setStretchLastSection(true);
    //ui->tbWidgetMQTTPublish->hideColumn(0);

}
void frmnewDevice::layoutTbWidgetMQTTSubscribe()
{
    QStringList titles;

    //ui->btnAddSubscribeTopic->setFixedWidth(40);
    ui->tbWidgetSubscribeTopic->setColumnCount(3);
    titles<<"TopicID"<<"Topic"<<" ";
    ui->tbWidgetSubscribeTopic->setHorizontalHeaderLabels(titles);
    //ui->tbWidgetSubscribeTopic->setColumnWidth(0,25);
    ui->tbWidgetSubscribeTopic->setColumnWidth(1,350);
    ui->tbWidgetSubscribeTopic->setColumnWidth(2,50);
    ui->tbWidgetSubscribeTopic->setColumnHidden(0,true);
    ui->tbWidgetSubscribeTopic->horizontalHeader()->setStretchLastSection(true);

}

void frmnewDevice::layoutTbWidgetCoap()
{
    QStringList titles;

    //ui->btnAddSubscribeTopic->setFixedWidth(40);
    ui->tbWidgetCoap->setColumnCount(4);
    titles<<"Command"<<"Time Profile"<<"Data Profile"<<"";
    ui->tbWidgetCoap->setHorizontalHeaderLabels(titles);
    ui->tbWidgetCoap->setColumnWidth(0,150);
    ui->tbWidgetCoap->setColumnWidth(1,100);
    ui->tbWidgetCoap->setColumnWidth(2,100);
    ui->tbWidgetCoap->setColumnWidth(3,50);
    ui->tbWidgetCoap->horizontalHeader()->setStretchLastSection(true);

}
void frmnewDevice::layoutTbWidgetHttp()
{
    QStringList titles;

    //ui->btnAddSubscribeTopic->setFixedWidth(40);
    ui->tbWidgetHttp->setColumnCount(4);
    titles<<"Command"<<"Time Profile"<<"Data Profile"<<"";
    ui->tbWidgetHttp->setHorizontalHeaderLabels(titles);
    ui->tbWidgetHttp->setColumnWidth(0,150);
    ui->tbWidgetHttp->setColumnWidth(1,100);
    ui->tbWidgetHttp->setColumnWidth(2,100);
    ui->tbWidgetHttp->setColumnWidth(3,50);
    ui->tbWidgetHttp->horizontalHeader()->setStretchLastSection(true);

}

void frmnewDevice::addNewTopic()
{
    Topics *topics = new Topics();
    topics->setModal(true);
    int result = topics->exec();
}
void frmnewDevice::addNewDataProfile()
{
    DataProfile *dataprofile = new DataProfile();
    dataprofile->setModal(true);
    int result = dataprofile->exec();
}
void frmnewDevice::addNewTimeProfile()
{
    TimeProfile *timeprofile = new TimeProfile();
    timeprofile->setModal(true);
    int result = timeprofile->exec();
}


void frmnewDevice::on_btnAdMQTTSubscribeTopic_clicked()
{
    addNewTopic();
    fillProfileDropdown();
}
void frmnewDevice::on_btnAdMQTTPublishTopic_clicked()
{
    addNewTopic();
    fillProfileDropdown();
}

void frmnewDevice::on_btnMQTTPublishDataProfile_clicked()
{
    addNewDataProfile();
    fillDataProfileDropdown();
}


void frmnewDevice::on_btnMQTTPublishTimeProfile_clicked()
{
    addNewTimeProfile();
    fillTimeProfileDropdown();
}




void frmnewDevice::on_btnAddCoapTimeProfile_clicked()
{
    addNewTimeProfile();
    fillTimeProfileDropdown();
}


void frmnewDevice::on_btnAddCoapDataProfile_clicked()
{
    addNewDataProfile();
    fillDataProfileDropdown();
}

void frmnewDevice::on_btnAddHttpTimeProfile_clicked()
{
    addNewTimeProfile();
    fillTimeProfileDropdown();
}

void frmnewDevice::on_btnAddHttpDataProfile_clicked()
{
    addNewDataProfile();
    fillDataProfileDropdown();
}

bool frmnewDevice::validateForm()
{

    if(ui->txtIPAddress->text().isEmpty())
    {
        QMessageBox::information(this,tr("Missing Info"),tr("Please enter IP address"));
        return false;
    }

    if(ui->sbNumofDevices->value()<=0)
    {
        QMessageBox::information(this,tr("Missing Info"),tr("Please enter number of devices > 0"));
        return false;
    }

    if(ui->cmbProtocol->currentText()=="MQTT" || ui->cmbProtocol->currentText()=="MQTTs")
    {
        if(ui->txtBrokerIP->text().isEmpty())
        {
            QMessageBox::information(this,tr("Missing Info"),tr("Please enter MQTT broker address"));
            return false;
        }
        if(ui->isBrookerAuthentication->isChecked())
        {
            if(ui->txtBrokerUserName->text().isEmpty())
            {
                QMessageBox::information(this,tr("Missing Info"),tr("Please enter MQTT broker user name"));
                return false;
            }
            if(ui->txtBrokerPassword->text().isEmpty())
            {
                QMessageBox::information(this,tr("Missing Info"),tr("Please enter MQTT broker password"));
                return false;
            }

        }

    }
    if(ui->cmbProtocol->currentText()=="COAP")
    {
        if(ui->txtCoapUrl->text().isEmpty())
        {
            QMessageBox::information(this,tr("Missing Info"),tr("Please enter COAP url"));
            return false;
        }

    }
    if(ui->cmbProtocol->currentText()=="HTTP" || ui->cmbProtocol->currentText()=="HTTPs")
    {
        if(ui->txtHttpUrl->text().isEmpty())
        {
            QMessageBox::information(this,tr("Missing Info"),tr("Please enter HTTP url"));
            return false;
        }
    }


    return true;

}




frmnewDevice::~frmnewDevice()
{
    delete ui;
}

void frmnewDevice::on_cmbSelectTemplate_currentIndexChanged(int index)
{

    //if(!isLoadingDone)
    //return;
        //QMessageBox::information(this,tr("Missing Info"),tr("Please enter HTTP url"));
    id = ui->cmbSelectTemplate->currentData().toInt();

    qDebug()<<id;


    FormType="EDIT";
   SetFormLayout();
    FillFormData();



}
