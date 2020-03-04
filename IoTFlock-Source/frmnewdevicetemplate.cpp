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
#include "frmnewdevicetemplate.h"
#include "ui_frmnewdevicetemplate.h"
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
#include<frmkeyvalue.h>
#include<QPushButton>
#include<qdebug.h>
#include<ui_frmkeyvalue.h>

frmNewDeviceTemplate::frmNewDeviceTemplate(QWidget *parent,QString _FormType, int _id) :
    QDialog(parent),
    ui(new Ui::frmNewDeviceTemplate)
{
 try{
    ui->setupUi(this);

    FormType = _FormType;
    id = _id;

    SetFormLayout();

    if(FormType == "EDIT" || FormType == "USECASEEDIT")  //to Edit device template
        BindData();


      ui->tbMain->removeTab(3);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }

    }
void frmNewDeviceTemplate::SetFormLayout()
{

    if(FormType == "NEWDEVICE")
    {
        ui->cmbTemplates->setVisible(true);
        ui->txtDeviceName->setVisible(false);
        ui->lblDeviceName->setText("Templates");
        ui->btnCreate->setText("Create");
        ui->lblDeviceName2->setVisible(true);
        ui->txtDeviceName2->setVisible(true);
       this->setWindowTitle("Add Device To Use Case");
    }
    else {
         ui->cmbTemplates->setVisible(false);
         ui->lblDeviceName2->setVisible(false);
         ui->txtDeviceName2->setVisible(false);
         if(FormType == "EDIT")
             this->setWindowTitle("Edit Device Template");
    }
    ui->txtCoapParameters->setVisible(false);
    ui->txtHttpParameters->setVisible(false);
    ui->txtCoapParameters->setDisabled(1);
    ui->txtHttpParameters->setDisabled(1);

    QStringList titles;
    ui->tbWidgetSubscribeTopic->setColumnCount(3);
    titles<<"TopicID"<<"Topic"<<" ";
    ui->tbWidgetSubscribeTopic->setHorizontalHeaderLabels(titles);
    ui->tbWidgetSubscribeTopic->setColumnHidden(0,true);  //topic id
    ui->tbWidgetSubscribeTopic->setColumnWidth(1,450);    //name
    ui->tbWidgetSubscribeTopic->setColumnWidth(2,50);     //button


    QStringList titles2;
    ui->tbWidgetMQTTPublish->setColumnCount(8);
    titles2<<"TopicID"<<"DataProfileID"<<"TimeProfileID"<<"Topic"<<"QoS"<<"Data Profile"<<"Time Profile"<<" ";
    ui->tbWidgetMQTTPublish->setHorizontalHeaderLabels(titles2);
    ui->tbWidgetMQTTPublish->setColumnHidden(0,true);
    ui->tbWidgetMQTTPublish->setColumnHidden(1,true);
    ui->tbWidgetMQTTPublish->setColumnHidden(2,true);
    ui->tbWidgetMQTTPublish->setColumnWidth(3,170);
    ui->tbWidgetMQTTPublish->setColumnWidth(4,70);
    ui->tbWidgetMQTTPublish->setColumnWidth(5,150);
    ui->tbWidgetMQTTPublish->setColumnWidth(6,150);
    ui->tbWidgetMQTTPublish->setColumnWidth(7,50);


    QStringList titles3;
    ui->tbWidgetCoap->setColumnCount(7);
    titles3<<"URL"<<"Command"<<"TimeProfileID"<<"Time Profile"<<"DataProfileID"<<"DataProfile"<<"";
    ui->tbWidgetCoap->setHorizontalHeaderLabels(titles3);
    ui->tbWidgetCoap->setColumnWidth(0,200);
    ui->tbWidgetCoap->setColumnWidth(1,100);
    ui->tbWidgetCoap->setColumnHidden(2,true); //timeProfileID
    ui->tbWidgetCoap->setColumnWidth(3,150);
    ui->tbWidgetCoap->setColumnHidden(4,true);  //dataProfileID
    ui->tbWidgetCoap->setColumnWidth(5,200);
    ui->tbWidgetCoap->setColumnWidth(6,50);

    QStringList titles4;
    ui->tbWidgetHttp->setColumnCount(7);
    titles4<<"URL"<<"Command"<<"TimeProfileID"<<"Time Profile"<<"DataProfileID"<<"DataProfile"<<"";
    ui->tbWidgetHttp->setHorizontalHeaderLabels(titles4);
    ui->tbWidgetHttp->setColumnWidth(0,200);
    ui->tbWidgetHttp->setColumnWidth(1,100);
    ui->tbWidgetHttp->setColumnHidden(2,true);  //timeProfileID
    ui->tbWidgetHttp->setColumnWidth(3,150);
    ui->tbWidgetHttp->setColumnHidden(4,true);  //dataProfileID
    ui->tbWidgetHttp->setColumnWidth(5,200);
    ui->tbWidgetHttp->setColumnWidth(6,50);

    BindTopicDropdown();
    BindDataProfileDropdown();
    BindTimeProfileDropdown();
    on_cmbProtocol_currentIndexChanged("");
  //  on_cmbCoapCommand_currentIndexChanged("");
  //  on_cmbHttpCommand_currentIndexChanged("");
    if(FormType == "NEWDEVICE")
        BindTemplatesDropdown();

}

void frmNewDeviceTemplate::BindData()
{
        BindForm();
        BindMQTTSubscribeGrid();
        BindMQTTPublishGrid();
        BindCoapGrid();
        BindHttpGrid();
}


void frmNewDeviceTemplate::BindTopicDropdown()
{
    dlTopic _dlTopic;
    QList<objTopic> lstObjTopic= _dlTopic.GetTopicList();
    foreach(objTopic obj,lstObjTopic)
    {
       ui->cmbSubscribeTopic->addItem(obj.name,QVariant(obj._id));
       ui->cmbMQTTPublishTopic->addItem(obj.name,QVariant(obj._id));
    }
}

void frmNewDeviceTemplate::BindTimeProfileDropdown()
{
    dlTimeProfile _dlTimeProfile;
    QList<objTimeProfile> lstObjTimeProfile = _dlTimeProfile.GetTimeProfileList();
    foreach(objTimeProfile obj, lstObjTimeProfile)
    {
        ui->cmbMQTTPublishTimeProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbCoapTimeProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbHttpTimeProfile->addItem(obj.name, QVariant(obj._id));
    }
}
void frmNewDeviceTemplate::BindDataProfileDropdown()
{
    dlDataProfile _dlDataProfile;
    QList<objDataProfile> lstObjDataProfile = _dlDataProfile.GetDataProfileList();
    foreach(objDataProfile obj, lstObjDataProfile)
    {
        ui->cmbMQTTPublishDataProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbCoapDataProfile->addItem(obj.name, QVariant(obj._id));
        ui->cmbHttpDataProfile->addItem(obj.name, QVariant(obj._id));

    }
}
void frmNewDeviceTemplate::BindTemplatesDropdown()
{
    dlDeviceTemplate _dlDeviceTemplate;
    QList<objDeviceTemplate> lstObjDeviceTemplate = _dlDeviceTemplate.GetDeviceList();

    foreach(objDeviceTemplate _objDeviceTemplate, lstObjDeviceTemplate)
    {
        ui->cmbTemplates->addItem(_objDeviceTemplate.deviceName,QVariant(_objDeviceTemplate._id));
    }

    ui->cmbTemplates->setCurrentIndex(-1);
    //on_cmbTemplates_currentIndexChanged(-1);
}
void frmNewDeviceTemplate::BindForm()
{
   // FormType == "USECASEEDIT"

    objDeviceTemplate _objDeviceTemplate;

    if(FormType == "USECASEEDIT")
        {
            dlDeviceTemplate _dlDeviceTemplate;
            _objDeviceTemplate = _dlDeviceTemplate.GetDeviceListNew(id);

        }
    else
    {
    dlDeviceTemplate _dlDeviceTemplate;
    _objDeviceTemplate = _dlDeviceTemplate.GetDeviceList(id);
    }

    this->ui->txtDeviceName->setText(_objDeviceTemplate.deviceName);
    this->ui->txtDeviceName2->setText(_objDeviceTemplate.deviceName);
    this->ui->cmbProtocol->setCurrentText(_objDeviceTemplate.deviceProtocol);        this->ui->txtIPAddress->setText(_objDeviceTemplate.IPAddress);
    this->ui->sbNumofDevices->setValue(_objDeviceTemplate.NumofDevices);
     this->ui->txtBrokerIP->setText(_objDeviceTemplate.brokerIP);

    //MQTT Tab
    this->ui->rbMQTTRegular->setChecked(_objDeviceTemplate.isRegularPort);
    this->ui->rbMQTTTLS->setChecked(!_objDeviceTemplate.isRegularPort);
    if (_objDeviceTemplate.isRegularPort == true)
       this->ui->sbBrokerPortRegular->setValue(_objDeviceTemplate.portNO);
    else
        this->ui->sbBrokerportTLS->setValue(_objDeviceTemplate.portNO);

    this->ui->gbBrookerAuthentication->setChecked(_objDeviceTemplate.isAuthenticationRequire);
    if(_objDeviceTemplate.isAuthenticationRequire)
    {
        this->ui->txtBrokerUserName->setText(_objDeviceTemplate.brokerUserName);
        this->ui->txtBrokerPassword->setText(_objDeviceTemplate.brokerPassword);
    }

    this->ui->txtCoapUrl->setText(_objDeviceTemplate.coapURL);
    this->ui->txtHttpUrl->setText(_objDeviceTemplate.httpURL);
    if(_objDeviceTemplate.isAttackingEntity)
    {
        this->ui->gbIsAttackingEntity->setChecked(1);
        this->ui->cmbAttackType->setCurrentIndex(_objDeviceTemplate.attackType.toInt());
        this->ui->txtAttackingSourceIP->setText(_objDeviceTemplate.sourceIP);
        this->ui->txtAttackingTargetIP->setText(_objDeviceTemplate.targetIP);
        this->ui->sbAttackingTargetPort->setValue(_objDeviceTemplate.targetPort);
        this->ui->sbAttackingInterval->setValue(_objDeviceTemplate.interval);
        this->ui->txtAttackingMsg->setPlainText(_objDeviceTemplate.message);

    }
}

void frmNewDeviceTemplate::BindMQTTSubscribeGrid()
{
    QList<objDeviceSubscribeData> _lstObjDeviceSubscribeData;
    dlDeviceSubscribeData _dlDeviceSubscribeData;
   if(FormType == "USECASEEDIT")
    {
    _lstObjDeviceSubscribeData = _dlDeviceSubscribeData.fillTbWidgetMQTTSubscribeForUseCase(id);
    }
    else
    {
     _lstObjDeviceSubscribeData = _dlDeviceSubscribeData.fillTbWidgetMQTTSubscribe(id);
    }
    ui->tbWidgetSubscribeTopic->setColumnCount(3);
    foreach(objDeviceSubscribeData _objDeviceSubscribeData,_lstObjDeviceSubscribeData)
    {
        ui->tbWidgetSubscribeTopic->insertRow(ui->tbWidgetSubscribeTopic->rowCount());
        int rowNum=ui->tbWidgetSubscribeTopic->rowCount()-1;
        ui->tbWidgetSubscribeTopic->setItem(rowNum,0,new QTableWidgetItem(QString::number(_objDeviceSubscribeData.topicID)));
        ui->tbWidgetSubscribeTopic->setItem(rowNum,1,new QTableWidgetItem(_objDeviceSubscribeData.topicName));
        QPushButton *bt=new QPushButton(" ");
        bt->setFixedWidth(50);
        bt->setFixedHeight(30);
        QPixmap pixmapDelete(_constants.PATH_DELETEICON);
        QIcon DeleteButtonIcon(pixmapDelete);
        bt->setIcon(DeleteButtonIcon);
        bt->setIconSize(QSize(30,20));
        ui->tbWidgetSubscribeTopic->setCellWidget(rowNum,2,bt);
        connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removeSubscribeRow);
    }
 }

void frmNewDeviceTemplate::BindMQTTPublishGrid()
{

    dlDevicePublishData _dlDevicePublishData;
    QList<objDevicePublishData> _lstObjDevicePublishData;
    if(FormType == "USECASEEDIT")
    {
        _lstObjDevicePublishData = _dlDevicePublishData.GetDevicePublishDataForUseCase(id);
    }
    else
    {
    _lstObjDevicePublishData = _dlDevicePublishData.GetDevicePublishData(id);
    }

    ui->tbWidgetMQTTPublish->setColumnCount(8);
    foreach(objDevicePublishData _objDevicePublishData, _lstObjDevicePublishData)
    {
    this->ui->tbWidgetMQTTPublish->insertRow(ui->tbWidgetMQTTPublish->rowCount());
    int rowNum=this->ui->tbWidgetMQTTPublish->rowCount()-1;
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,0,new QTableWidgetItem(QString::number(_objDevicePublishData.topicID)) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,1,new QTableWidgetItem(QString::number(_objDevicePublishData.dataProfileID)) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,2,new QTableWidgetItem(QString::number(_objDevicePublishData.timeProfileID)) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,3,new QTableWidgetItem(_objDevicePublishData.topic) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,4,new QTableWidgetItem(QString::number(_objDevicePublishData.QoS)) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,5,new QTableWidgetItem(_objDevicePublishData.dataprofile) );
     this->ui->tbWidgetMQTTPublish->setItem(rowNum,6,new QTableWidgetItem(_objDevicePublishData.timeprofile) );
    QPushButton *bt=new QPushButton(" ");
    bt->setFixedWidth(50);
    bt->setFixedHeight(30);
    QPixmap pixmapDelete(_constants.PATH_DELETEICON);
    QIcon DeleteButtonIcon(pixmapDelete);
    bt->setIcon(DeleteButtonIcon);
    bt->setIconSize(QSize(30,20));
     this->ui->tbWidgetMQTTPublish->setCellWidget(rowNum,7,bt);
     connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removePublishRow);
    }
}

void frmNewDeviceTemplate::BindCoapGrid()
{
    dlDeviceCoapData _dlDeviceCoapData;
    QList<objDeviceCoapData> _lstObjDeviceCoapData;
    if(FormType == "USECASEEDIT")
    {
     _lstObjDeviceCoapData = _dlDeviceCoapData.GetDeviceCoapDataForUseCase(id);
    }
    else
    {
     _lstObjDeviceCoapData = _dlDeviceCoapData.GetDeviceCoapData(id);
    }

    ui->tbWidgetCoap->setColumnCount(7);

    foreach(objDeviceCoapData _objDeviceCoapData, _lstObjDeviceCoapData)
    {
        this->ui->tbWidgetCoap->insertRow(ui->tbWidgetCoap->rowCount());
        int rowNum = ui->tbWidgetCoap->rowCount()-1;

        this->ui->tbWidgetCoap->setItem(rowNum,0,new QTableWidgetItem(_objDeviceCoapData.url) );
        this->ui->tbWidgetCoap->setItem(rowNum,1,new QTableWidgetItem(_objDeviceCoapData.coapCommand) );
        this->ui->tbWidgetCoap->setItem(rowNum,2,new QTableWidgetItem(QString::number(_objDeviceCoapData.coapTimeProfileID)) );
        this->ui->tbWidgetCoap->setItem(rowNum,3,new QTableWidgetItem(_objDeviceCoapData.timeprofile) );
        this->ui->tbWidgetCoap->setItem(rowNum,4,new QTableWidgetItem(QString::number(_objDeviceCoapData.coapDataProfileID)) );
        this->ui->tbWidgetCoap->setItem(rowNum,5,new QTableWidgetItem(_objDeviceCoapData.dataprofile) );
        QPushButton *bt=new QPushButton(" ");
        bt->setFixedWidth(50);
        bt->setFixedHeight(30);
        QPixmap pixmapDelete(_constants.PATH_DELETEICON);
        QIcon DeleteButtonIcon(pixmapDelete);
        bt->setIcon(DeleteButtonIcon);
        bt->setIconSize(QSize(30,20));
        this->ui->tbWidgetCoap->setCellWidget(rowNum,6,bt);
        connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removeCoapRow);
    }

}

void frmNewDeviceTemplate::BindHttpGrid()
{
    dlDeviceHttpData _dlDeviceHttpData;
    QList<objDeviceHttpData> _lstObjDeviceHttpData = _dlDeviceHttpData.GetDeviceHttpData(id);
    ui->tbWidgetHttp->setColumnCount(7);

    foreach(objDeviceHttpData _objDeviceHttpData, _lstObjDeviceHttpData)
    {
        this->ui->tbWidgetHttp->insertRow(ui->tbWidgetHttp->rowCount());
        int rowNum = ui->tbWidgetHttp->rowCount()-1;
        this->ui->tbWidgetHttp->setItem(rowNum,0,new QTableWidgetItem(_objDeviceHttpData.url) );
        this->ui->tbWidgetHttp->setItem(rowNum,1,new QTableWidgetItem(_objDeviceHttpData.httpCommand) );
        this->ui->tbWidgetHttp->setItem(rowNum,2,new QTableWidgetItem(QString::number(_objDeviceHttpData.httpTimeProfileID)) );
        this->ui->tbWidgetHttp->setItem(rowNum,3,new QTableWidgetItem(_objDeviceHttpData.timeprofile) );
        this->ui->tbWidgetHttp->setItem(rowNum,4,new QTableWidgetItem(QString::number(_objDeviceHttpData.httpDataProfileID)) );
        this->ui->tbWidgetHttp->setItem(rowNum,5,new QTableWidgetItem(_objDeviceHttpData.dataprofile) );
        QPushButton *bt=new QPushButton(" ");
        bt->setFixedWidth(50);
        bt->setFixedHeight(30);
        QPixmap pixmapDelete(_constants.PATH_DELETEICON);
        QIcon DeleteButtonIcon(pixmapDelete);
        bt->setIcon(DeleteButtonIcon);
        bt->setIconSize(QSize(30,20));
        this->ui->tbWidgetHttp->setCellWidget(rowNum,6,bt);
        connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removeHttpRow);
    }
}



//Fire when form is saving
void frmNewDeviceTemplate::on_btnCreate_clicked()
{
 try{
    if(!validateForm())
        return;

     Save();

     if(FormType == "NEWDEVICE")
     {
      this->close();
      this->setResult(1);
     }
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::Save()
{
    objDeviceTemplate _objDeviceTemplate;

    int templateID = _objDeviceTemplate._id = id;
     _objDevice.deviceName = _objDeviceTemplate.deviceName = ui->txtDeviceName->text();
     if(FormType == "NEWDEVICE")
     {
          _objDevice.deviceName = _objDeviceTemplate.deviceName = ui->txtDeviceName2->text();
     }
   //general tab information
   _objDevice.protocol=_objDeviceTemplate.deviceProtocol = ui->cmbProtocol->currentText();
   _objDevice.sHostName=_objDeviceTemplate.IPAddress = ui->txtIPAddress->text();
   _objDevice.IPCount=_objDeviceTemplate.NumofDevices = ui->sbNumofDevices->value();
   _objDevice.isAttackingEntity = _objDeviceTemplate.isAttackingEntity = false;
   if(ui->gbIsAttackingEntity->isChecked())
   {
       _objDevice.isAttackingEntity = _objDeviceTemplate.isAttackingEntity = true;
       _objDevice.attackType = _objDeviceTemplate.attackType = ui->cmbAttackType->currentText();
       _objDevice.sourceIP = _objDeviceTemplate.sourceIP = ui->txtAttackingSourceIP->text();
       _objDevice.targetIP =_objDeviceTemplate.targetIP = ui->txtAttackingTargetIP->text();
       _objDevice.targetPort =_objDeviceTemplate.targetPort = ui->sbAttackingTargetPort->text().toInt();
       _objDevice.interval =_objDeviceTemplate.interval = ui->sbAttackingInterval->text().toInt();
       _objDevice.message = _objDeviceTemplate.message =ui->txtAttackingMsg->toPlainText();

   }


   //mqtt basic setting
   _objDevice.hostName=_objDeviceTemplate.brokerIP = ui->txtBrokerIP->text();
   if(ui->rbMQTTRegular->isChecked())
     {
       _objDeviceTemplate.isRegularPort = true;
       _objDevice.port= _objDeviceTemplate.portNO = (ui->sbBrokerPortRegular->value());
       _objDevice.portType ="REGULAR";
      }
       if(ui->rbMQTTTLS->isChecked())
       {
        _objDeviceTemplate.isRegularPort = false;
        _objDevice.port= _objDeviceTemplate.portNO = ui->sbBrokerportTLS->value();
       _objDevice.portType ="TTLS";
       }

       if(ui->gbBrookerAuthentication->isChecked())
       {
           _objDevice.isAuthenticationRequire =  _objDeviceTemplate.isAuthenticationRequire = true;
           _objDevice.userName = _objDeviceTemplate.brokerUserName = ui->txtBrokerUserName->text();
           _objDevice.password = _objDeviceTemplate.brokerPassword = ui->txtBrokerPassword->text();
       }
       else
           _objDevice.isAuthenticationRequire =  _objDeviceTemplate.isAuthenticationRequire = false;

    //coap basic setting
  if(ui->cmbProtocol->currentText()=="COAP")
   _objDevice.hostName = _objDeviceTemplate.coapURL = ui->txtCoapUrl->text();

   //http basic setting
  if(ui->cmbProtocol->currentText()=="HTTP")
  _objDevice.hostName = _objDeviceTemplate.httpURL = ui->txtHttpUrl->text();

   //saving parent table "device template"
   dlDeviceTemplate *_dlDeviceTemplate = new dlDeviceTemplate();

   if(FormType == "ADD")
        templateID =  _dlDeviceTemplate->Insert(_objDeviceTemplate);
   else if(FormType == "EDIT")
        _dlDeviceTemplate->UpdateDeviceTemplate(_objDeviceTemplate);
   else if(FormType == "USECASEEDIT")
        _dlDeviceTemplate->UpdateUseCaseDeviceTemplate(_objDeviceTemplate);

   if(templateID>0 || FormType == "NEWDEVICE")
   {
       //saving mqtt subscribe details
       dlDeviceSubscribeData _dlDeviceSubscribeData;
       if(FormType == "EDIT")
            _dlDeviceSubscribeData.DelSubscribeData(id);
       else if(FormType == "USECASEEDIT")
            _dlDeviceSubscribeData.DelSubscribeDataForUseCase(id);
       for(int i=0;i<ui->tbWidgetSubscribeTopic->rowCount();i++)
       {
          _objDevice.isSubscriber = true;
           objDeviceSubscribeData _objDeviceSubscribeData;
           _objDeviceSubscribeData.topicID = ui->tbWidgetSubscribeTopic->item(i,0)->text().toInt();           
           _objDeviceSubscribeData.deviceTemplateID = templateID;
           if(FormType == "NEWDEVICE")
           {
             _objDeviceSubscribeData.topicName = ui->tbWidgetSubscribeTopic->item(i,1)->text();
             _objDevice.lstSubTopic.append(_objDeviceSubscribeData);
            }
           else {
                if(FormType == "EDIT")
                         _dlDeviceSubscribeData.Insert(_objDeviceSubscribeData);
                  else if(FormType == "USECASEEDIT")
                        _dlDeviceSubscribeData.InsertForUseCase(_objDeviceSubscribeData);
           }
       }

       //save mqtt publish details
       dlDevicePublishData _dlDevicePublishData;
       if(FormType == "EDIT")
            _dlDevicePublishData.DelPublishData(id);
       else if(FormType == "USECASEEDIT")
            _dlDevicePublishData.DelPublishDataForUseCase(id);

       for(int j=0; j<ui->tbWidgetMQTTPublish->rowCount();j++)
       {
          // titles2<<"TopicID"<<"DataProfileID"<<"TimeProfileID"<<"Topic"<<"QoS"<<"Data Profile"<<"Time Profile"<<" ";
            _objDevice.isPublisher = true;
            objDevicePublishData _objDevicePublishData;
           _objDevicePublishData.deviceTemplateID = templateID;
           _objDevicePublishData.topicID = ui->tbWidgetMQTTPublish->item(j,0)->text().toInt();
           _objDevicePublishData.dataProfileID = ui->tbWidgetMQTTPublish->item(j,1)->text().toInt();
           _objDevicePublishData.timeProfileID = ui->tbWidgetMQTTPublish->item(j,2)->text().toInt();

           _objDevicePublishData.topic = ui->tbWidgetMQTTPublish->item(j,3)->text();
           _objDevicePublishData.QoS = ui->tbWidgetMQTTPublish->item(j,4)->text().toInt();
           //_objDevicePublishData.time = ui->tbWidgetMQTTPublish->item(j,5)->text();

         if(FormType == "NEWDEVICE")
         {

             dlTimeProfile _dlTimeProfile;
             _objDevicePublishData._objTimeProfile = _dlTimeProfile.GetTimeProfile(_objDevicePublishData.timeProfileID);
             dlDataProfile _dlDataProfile;
             _objDevicePublishData._objDataProfile = _dlDataProfile.GetDataProfile(_objDevicePublishData.dataProfileID);
             _objDevice.lstPubTopic.append(_objDevicePublishData);
         }
         else
         {
             if(FormType == "EDIT")
              _dlDevicePublishData.Insert(_objDevicePublishData);
             else if(FormType == "USECASEEDIT")
             _dlDevicePublishData.InsertForUseCase(_objDevicePublishData);

         }

       }

       //save coap detials
       dlDeviceCoapData _dlDeviceCoapData;
       if(FormType == "EDIT")
            _dlDeviceCoapData.DelCoapData(id);
       else if(FormType == "USECASEEDIT")
            _dlDeviceCoapData.DelCoapDataForUseCase(id);

       for(int j=0; j<ui->tbWidgetCoap->rowCount();j++)
       {
           qDebug()<<"TimeprofileID: "<<ui->tbWidgetCoap->item(j,4)->text().toInt();
           objDeviceCoapData _objDeviceCoapData;
           _objDeviceCoapData.deviceTemplateID = templateID;
           _objDeviceCoapData.url = ui->tbWidgetCoap->item(j,0)->text(); //URL
           _objDeviceCoapData.coapCommand = ui->tbWidgetCoap->item(j,1)->text();
           _objDeviceCoapData.coapTimeProfileID = ui->tbWidgetCoap->item(j,2)->text().toInt();
           _objDeviceCoapData.timeprofile = ui->tbWidgetCoap->item(j,3)->text();
           _objDeviceCoapData.coapDataProfileID = ui->tbWidgetCoap->item(j,4)->text().toInt();
            _objDeviceCoapData.dataprofile = ui->tbWidgetCoap->item(j,5)->text();
           if(FormType == "NEWDEVICE")
           {
               dlTimeProfile _dlTimeProfile;
               _objDeviceCoapData._objTimeProfile = _dlTimeProfile.GetTimeProfile(_objDeviceCoapData.coapTimeProfileID);

                dlDataProfile _dlDataProfile;
              _objDeviceCoapData._objDataProfile = _dlDataProfile.GetDataProfile(_objDeviceCoapData.coapDataProfileID);
              _objDevice.lstDeviceCoapData.append(_objDeviceCoapData); //functionality removed
           }
           else {
                if(FormType == "EDIT")
                _dlDeviceCoapData.Insert(_objDeviceCoapData);
                else if(FormType == "USECASEEDIT")
                _dlDeviceCoapData.InsertForUseCase(_objDeviceCoapData);
           }
       }

       //save http details
       dlDeviceHttpData _dlDeviceHttpData;
       if(FormType == "EDIT")
            _dlDeviceHttpData.DelHttpData(id);

       for(int j=0; j<ui->tbWidgetHttp->rowCount();j++)
       {
           objDeviceHttpData _objDeviceHttpData;
           _objDeviceHttpData.deviceTemplateID = templateID;
           _objDeviceHttpData.url = ui->tbWidgetHttp->item(j,0)->text();
          _objDeviceHttpData.httpCommand = ui->tbWidgetHttp->item(j,1)->text();
          _objDeviceHttpData.httpTimeProfileID = ui->tbWidgetHttp->item(j,2)->text().toInt();
          _objDeviceHttpData.timeprofile = ui->tbWidgetHttp->item(j,3)->text();
          _objDeviceHttpData.httpDataProfileID = ui->tbWidgetHttp->item(j,4)->text().toInt();
          _objDeviceHttpData.dataprofile = ui->tbWidgetHttp->item(j,5)->text();
          if(FormType == "NEWDEVICE")
          {
              dlTimeProfile _dlTimeProfile;
              _objDeviceHttpData._objTimeProfile = _dlTimeProfile.GetTimeProfile(_objDeviceHttpData.httpTimeProfileID);
              dlDataProfile _dlDataProfile;
              _objDeviceHttpData._objDataProfile = _dlDataProfile.GetDataProfile(_objDeviceHttpData.httpDataProfileID);
              _objDevice.lstDeviceHttpData.append(_objDeviceHttpData);
          }
          else {
              _dlDeviceHttpData.Insert(_objDeviceHttpData);

          }
       }

       if(FormType == "NEWDEVICE")
       {
            QMessageBox::information(this,tr("Query Info"),tr("Saved Successfully"));
            ClearForm();
       }
    }
   else {
       QMessageBox::information(this,tr("Query Info"),tr("Error Occured"));
   }

}

void frmNewDeviceTemplate::ClearForm()
{
    this->ui->txtDeviceName2->setText("");
    this->ui->txtDeviceName->clear();
    this->ui->cmbProtocol->setCurrentIndex(0);
    this->ui->txtIPAddress->clear();
    this->ui->sbNumofDevices->setValue(1);

    this->ui->gbIsAttackingEntity->setChecked(false);
    this->ui->cmbAttackType->setCurrentIndex(0);
    this->ui->txtAttackingSourceIP->clear();
    this->ui->txtAttackingTargetIP->clear();
    this->ui->sbAttackingTargetPort->setValue(0);
    this->ui->sbAttackingInterval->setValue(0);
    this->ui->txtAttackingMsg->clear();

    this->ui->txtBrokerIP->clear();
    this->ui->sbBrokerPortRegular->setValue(1883);
    this->ui->sbBrokerportTLS->setValue(1883);
    this->ui->txtBrokerUserName->clear();
    this->ui->txtBrokerPassword->clear();
    this->ui->gbBrookerAuthentication->setChecked(false);
    this->ui->rbMQTTRegular->setChecked(1);
    this->ui->rbMQTTTLS->setChecked(0);

    this->ui->cmbSubscribeTopic->setCurrentIndex(0);
    this->ui->tbWidgetSubscribeTopic->setRowCount(0);


    this->ui->cmbMQTTPublishTopic->setCurrentIndex(0);
    this->ui->cmbMQTTQoS->setCurrentIndex(0);
    this->ui->cmbMQTTPublishDataProfile->setCurrentIndex(0);
    this->ui->cmbMQTTPublishTimeProfile->setCurrentIndex(0);
    this->ui->tbWidgetMQTTPublish->setRowCount(0);

    this->ui->txtCoapUrl->clear();
   this->ui->cmbCoapCommand->setCurrentIndex(0);
   this->ui->cmbCoapDataProfile->setCurrentIndex(0);
   this->ui->cmbCoapTimeProfile->setCurrentIndex(0);
   // this->ui->txtCoapParameters->clear();
   this->ui->tbWidgetCoap->setRowCount(0);
    //this->ui->txtCoapTimeInterval->clear();

   this->ui->txtHttpUrl->clear();
  this->ui->cmbHttpCommand->setCurrentIndex(0);
  this->ui->cmbHttpDataProfile->setCurrentIndex(0);
  this->ui->cmbHttpTimeProfile->setCurrentIndex(0);
  //this->ui->txtHttpParameters->clear();
  this->ui->tbWidgetHttp->setRowCount(0);

}

void frmNewDeviceTemplate::on_btnClose_clicked()
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

//===========================================================================================
void frmNewDeviceTemplate::on_btnAddSubscribeTopic_clicked()
{
  try{
    ui->tbWidgetSubscribeTopic->insertRow(ui->tbWidgetSubscribeTopic->rowCount());
    int rowNum=ui->tbWidgetSubscribeTopic->rowCount()-1;
    QString topicID = ui->cmbSubscribeTopic->currentData().toString();  ////////////////////////
    QString list_item = ui->cmbSubscribeTopic->currentText(); //topiclist

    ui->tbWidgetSubscribeTopic->setItem(rowNum,0,new QTableWidgetItem(topicID) );
    ui->tbWidgetSubscribeTopic->setItem(rowNum,1,new QTableWidgetItem(list_item) );



    QPushButton *bt=new QPushButton(" ");
    bt->setFixedWidth(50);
    bt->setFixedHeight(30);
    QPixmap pixmapDelete(_constants.PATH_DELETEICON);
    QIcon DeleteButtonIcon(pixmapDelete);
    bt->setIcon(DeleteButtonIcon);
    bt->setIconSize(QSize(30,20));

    ui->tbWidgetSubscribeTopic->setCellWidget(rowNum,2,bt);
    connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removeSubscribeRow);
  // topicList.append(list_item);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}


void frmNewDeviceTemplate::on_btnMQTTPublish_clicked()  //(+ btn) MQTT Publish
{
try{
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


   QPushButton *bt=new QPushButton(" ");
   bt->setFixedWidth(50);
   bt->setFixedHeight(30);
   QPixmap pixmapDelete(_constants.PATH_DELETEICON);
   QIcon DeleteButtonIcon(pixmapDelete);
   bt->setIcon(DeleteButtonIcon);
   bt->setIconSize(QSize(30,20));

    ui->tbWidgetMQTTPublish->setCellWidget(rowNum,7,bt);
    connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removePublishRow);
  // topicList.append(list_item);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::on_btnCoapAdd_clicked()
{
    if(ui->txtCoapUrl->text().isEmpty() | ui->cmbCoapTimeProfile->currentData().isNull() | ui->cmbCoapCommand->currentText().isEmpty())
    {
         QMessageBox::information(this,tr("Missing Info"),tr("Please enter required fields."));
    }
    else{
        try{
            ui->tbWidgetCoap->insertRow(ui->tbWidgetCoap->rowCount());
            int rowNum=ui->tbWidgetCoap->rowCount()-1;


             ui->tbWidgetCoap->setItem(rowNum,0,new QTableWidgetItem(ui->txtCoapUrl->text()) );
             ui->tbWidgetCoap->setItem(rowNum,1,new QTableWidgetItem(ui->cmbCoapCommand->currentText()) );
             ui->tbWidgetCoap->setItem(rowNum,2,new QTableWidgetItem(ui->cmbCoapTimeProfile->currentData().toString()));
             ui->tbWidgetCoap->setItem(rowNum,3,new QTableWidgetItem(ui->cmbCoapTimeProfile->currentText()));
             ui->tbWidgetCoap->setItem(rowNum,4,new QTableWidgetItem(ui->cmbCoapDataProfile->currentData().toString()));
             //ui->tbWidgetCoap->setItem(rowNum,3,new QTableWidgetItem(coapDataProfile) );
             ui->tbWidgetCoap->setItem(rowNum,5,new QTableWidgetItem(ui->cmbCoapDataProfile->currentText()) );


             QPushButton *bt=new QPushButton(" ");
             bt->setFixedWidth(50);
            bt->setFixedHeight(30);
            QPixmap pixmapDelete(_constants.PATH_DELETEICON);
            QIcon DeleteButtonIcon(pixmapDelete);
            bt->setIcon(DeleteButtonIcon);
            bt->setIconSize(QSize(30,20));

            this->ui->tbWidgetCoap->setCellWidget(rowNum,6,bt);
            connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removeCoapRow);
              } catch (std::exception &e) {
                                              msgBox.setText(e.what());
                                              msgBox.exec();
              } catch (...) {
                               msgBox.setText("Problem occured");
                               msgBox.exec();
                 }

   }
}

void frmNewDeviceTemplate::on_btnHttpAdd_clicked()
{
    if(ui->txtHttpUrl->text().isEmpty() | ui->cmbHttpTimeProfile->currentData().isNull() | ui->cmbHttpCommand->currentText().isEmpty())
    {
         QMessageBox::information(this,tr("Missing Info"),tr("Please enter required fields."));
    }
    else{
         try{
                ui->tbWidgetHttp->insertRow(ui->tbWidgetHttp->rowCount());
                int rowNum=ui->tbWidgetHttp->rowCount()-1;

                ui->tbWidgetHttp->setItem(rowNum,0,new QTableWidgetItem(ui->txtHttpUrl->text()) ); //_id
                ui->tbWidgetHttp->setItem(rowNum,1,new QTableWidgetItem(ui->cmbHttpCommand->currentText()));
                ui->tbWidgetHttp->setItem(rowNum,2,new QTableWidgetItem(ui->cmbHttpTimeProfile->currentData().toString()));
                ui->tbWidgetHttp->setItem(rowNum,3,new QTableWidgetItem(ui->cmbHttpTimeProfile->currentText()));
                ui->tbWidgetHttp->setItem(rowNum,4,new QTableWidgetItem(ui->cmbHttpDataProfile->currentData().toString()));
                ui->tbWidgetHttp->setItem(rowNum,5,new QTableWidgetItem(ui->cmbHttpDataProfile->currentText()));

               QPushButton *bt=new QPushButton(" ");
               bt->setFixedWidth(50);
               bt->setFixedHeight(30);
               QPixmap pixmapDelete(_constants.PATH_DELETEICON);
               QIcon DeleteButtonIcon(pixmapDelete);
               bt->setIcon(DeleteButtonIcon);
               bt->setIconSize(QSize(30,20));

               this->ui->tbWidgetHttp->setCellWidget(rowNum,6,bt);
               connect(bt,&QPushButton::clicked,this,&frmNewDeviceTemplate::removeHttpRow);
                } catch (std::exception &e) {
                        msgBox.setText(e.what());
                        msgBox.exec();
                    } catch (...) {
                        msgBox.setText("Problem occured");
                        msgBox.exec();
                    }
    }
}

void frmNewDeviceTemplate::removeSubscribeRow()  //Subs Action Btn
{
  try{
    int rowNum=ui->tbWidgetSubscribeTopic->currentRow();
    ui->tbWidgetSubscribeTopic->removeRow(rowNum);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::removePublishRow()
{
    try{
    int rowNum=ui->tbWidgetMQTTPublish->currentRow();
    ui->tbWidgetMQTTPublish->removeRow(rowNum);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}
void frmNewDeviceTemplate::removeCoapRow()
{
 try{
    int rowNum=ui->tbWidgetCoap->currentRow();
    ui->tbWidgetCoap->removeRow(rowNum);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}
void frmNewDeviceTemplate::removeHttpRow()
{
 try{

    int rowNum=ui->tbWidgetHttp->currentRow();
    ui->tbWidgetHttp->removeRow(rowNum);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::addNewTopic()
{

    Topics topics;
    topics.setModal(true);
    int result = topics.exec();

 }
void frmNewDeviceTemplate::addNewDataProfile()
{

    DataProfile dataprofile;
    dataprofile.setModal(true);
    int result = dataprofile.exec();

 }
void frmNewDeviceTemplate::addNewTimeProfile()
{

    TimeProfile timeprofile;
    timeprofile.setModal(true);
    int result = timeprofile.exec();

 }


void frmNewDeviceTemplate::on_btnAdMQTTSubscribeTopic_clicked()
{
    try{
    addNewTopic();
    BindTopicDropdown();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}
void frmNewDeviceTemplate::on_btnAdMQTTPublishTopic_clicked()
{
    try{
    addNewTopic();
    BindTopicDropdown();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::on_btnMQTTPublishDataProfile_clicked()
{
    try{
    addNewDataProfile();
    BindDataProfileDropdown();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}


void frmNewDeviceTemplate::on_btnMQTTPublishTimeProfile_clicked()
{
   try{
    addNewTimeProfile();
    BindTimeProfileDropdown();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }




void frmNewDeviceTemplate::on_btnAddCoapTimeProfile_clicked()
{
 try{
    addNewTimeProfile();
    BindTimeProfileDropdown();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }


void frmNewDeviceTemplate::on_btnAddCoapDataProfile_clicked()
{
 try{
    addNewDataProfile();
    BindDataProfileDropdown();
  /*  FrmKeyValue _FrmKeyValue;
    _FrmKeyValue.setModal(true);
    _FrmKeyValue.exec();

    ui->txtCoapParameters->setText(_FrmKeyValue.keyValue);
    parameterValueWithID = _FrmKeyValue.keyValueWithID; */
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }

void frmNewDeviceTemplate::on_btnAddHttpTimeProfile_clicked()
{
  try{
    addNewTimeProfile();
    BindTimeProfileDropdown();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }

void frmNewDeviceTemplate::on_btnAddHttpDataProfile_clicked()
{
  try{
    addNewDataProfile();
    BindDataProfileDropdown();
   /* FrmKeyValue _FrmKeyValue;
    _FrmKeyValue.setModal(true);
    _FrmKeyValue.exec();

    ui->txtHttpParameters->setText(_FrmKeyValue.keyValue);
    parameterValueWithID = _FrmKeyValue.keyValueWithID; */
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
 }

bool frmNewDeviceTemplate::validateForm()
{
    if(FormType != "NEWDEVICE")
    {
        if(ui->txtDeviceName->text().isEmpty())
        {
          QMessageBox::information(this,tr("Missing Info"),tr("Please enter device name"));
          return false;
        }
    }
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
        if(ui->gbBrookerAuthentication->isChecked())
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

frmNewDeviceTemplate::~frmNewDeviceTemplate()
{
    delete ui;
}

void frmNewDeviceTemplate::on_cmbTemplates_currentIndexChanged(int index)
{
  try{
   id =   ui->cmbTemplates->currentData().toInt();

   ClearForm();
   if(id <=0)
       return;
   BindData();
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::on_cmbProtocol_currentIndexChanged(const QString &arg1)
{
 try{
   ui->tbMain->setTabEnabled(1,ui->cmbProtocol->currentText() == "MQTT");
   ui->tbMain->setTabEnabled(2,ui->cmbProtocol->currentText() == "COAP");
   ui->tbMain->setTabEnabled(3,ui->cmbProtocol->currentText() == "HTTP");
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }

}

void frmNewDeviceTemplate::on_cmbCoapCommand_currentIndexChanged(const QString &arg1)
{
  try{
    bool isEnable = ui->cmbCoapCommand->currentText() == "POST" | ui->cmbCoapCommand->currentText() == "PUT";
    //ui->txtCoapParameters->setEnabled(isEnable);
    ui->btnAddCoapDataProfile->setEnabled(isEnable);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::on_cmbHttpCommand_currentIndexChanged(const QString &arg1)
{
    try{
    bool isEnable = ui->cmbHttpCommand->currentText() == "POST" | ui->cmbHttpCommand->currentText() == "SEND";
   // ui->txtHttpParameters->setEnabled(isEnable);
    ui->btnAddHttpDataProfile->setEnabled(isEnable);
    } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }
}

void frmNewDeviceTemplate::on_gbBrookerAuthentication_clicked()
{

}

void frmNewDeviceTemplate::on_gbIsAttackingEntity_toggled(bool arg1)
{

}

void frmNewDeviceTemplate::on_gbIsAttackingEntity_clicked(bool checked)
{

}

void frmNewDeviceTemplate::on_cmbTemplates_activated(const QString &arg1)
{

}

void frmNewDeviceTemplate::on_cmbTemplates_currentIndexChanged(const QString &arg1)
{

}

void frmNewDeviceTemplate::on_cmbAttackType_currentIndexChanged(const QString &arg1)
{
   try{

    if(arg1.endsWith("MQTT"))
    {
        this->ui->cmbProtocol->setCurrentIndex(1); //MQTT Tab Enabled
        this->ui->txtAttackingSourceIP->setEnabled(false);
        this->ui->txtAttackingTargetIP->setEnabled(false);
        this->ui->sbAttackingTargetPort->setEnabled(false);
        this->ui->sbAttackingInterval->setEnabled(false);
        this->ui->txtAttackingMsg->setEnabled(false);
    }
    else if(arg1.endsWith("COAP"))
    {
        this->ui->cmbProtocol->setCurrentIndex(2); //COAP Tab Enabled
        this->ui->txtAttackingSourceIP->setEnabled(false);
        this->ui->txtAttackingTargetIP->setEnabled(false);
        this->ui->sbAttackingTargetPort->setEnabled(false);
        this->ui->sbAttackingInterval->setEnabled(false);
        this->ui->txtAttackingMsg->setEnabled(false);
    }
    else
    {
       this->ui->cmbProtocol->setCurrentIndex(0);
       this->ui->txtAttackingSourceIP->setEnabled(true);
       this->ui->txtAttackingTargetIP->setEnabled(true);
       this->ui->sbAttackingTargetPort->setEnabled(true);
       this->ui->sbAttackingInterval->setEnabled(true);
       this->ui->txtAttackingMsg->setEnabled(true);
    }
  } catch (std::exception &e) {
            msgBox.setText(e.what());
            msgBox.exec();
        } catch (...) {
            msgBox.setText("Problem occured");
            msgBox.exec();
        }

}
