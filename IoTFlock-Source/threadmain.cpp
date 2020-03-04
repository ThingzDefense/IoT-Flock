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
#include "threadmain.h"
#include<qdebug.h>
#include "objdevice.h"
#include<qthreadpool.h>
//#include<workerpool.h>
#include<qlist.h>
#include<qdatetime.h>
#include<filehandler.h>
#include<dlusecase.h>
#include<dldevicetemplate.h>
#include<dldevicesubscribedata.h>
#include<dldevicepublishdata.h>
#include<dldevicecoapdata.h>
#include<dldevicehttpdata.h>
#include<qnetworkinterface.h>
#include<QtXml>
#include<QFileDialog>
#include<qfiledialog.h>
#include <QtCore>
#include<QtConcurrent/QtConcurrent>


#define INETADDR(a, b, c, d)    (d + (c << 8) + (b << 16) + (a << 24))


static int jj =0;
static QList<Device*> lstWorkers;
static QMutex mutex;
static bool isSaveDB = false;
bool SaveUseCaseDeviceThread(objDevice _objDevice)
{
mutex.lock();
    //objDevice _objDevice = lstWorkers[j]->_objDevice;
    objDeviceTemplate _objDeviceTemplate;
    _objDeviceTemplate.deviceName = _objDevice.deviceName;
    _objDeviceTemplate.useCaseID = _objDevice.useCaseID;    //====
    //general tab information
    _objDeviceTemplate.deviceProtocol =_objDevice.protocol;
    _objDeviceTemplate.IPAddress =     _objDevice.sHostName;


    _objDeviceTemplate.isAttackingEntity = _objDevice.isAttackingEntity;
   if(_objDevice.isAttackingEntity)
   {
       _objDeviceTemplate.attackType = _objDevice.attackType;
       _objDeviceTemplate.sourceIP = _objDevice.sourceIP;
       _objDeviceTemplate.targetIP = _objDevice.targetIP;
       _objDeviceTemplate.targetPort = _objDevice.targetPort;
       _objDeviceTemplate.interval = _objDevice.interval;
       _objDeviceTemplate.message = _objDevice.message;

   }

//mqtt basic setting
_objDeviceTemplate.brokerIP = _objDevice.hostName;
if(_objDevice.portType == "REGULAR")
 {
   _objDeviceTemplate.isRegularPort = true;
   _objDeviceTemplate.portNO= _objDevice.port;
  }
  else
   {
    _objDeviceTemplate.isRegularPort = false;
    _objDeviceTemplate.portNO = _objDevice.port;
   }

   if(_objDevice.isAuthenticationRequire)
   {
       _objDeviceTemplate.isAuthenticationRequire = true;
       _objDeviceTemplate.brokerUserName = _objDevice.userName;
       _objDeviceTemplate.brokerPassword = _objDevice.password;
   }
   else
       _objDeviceTemplate.isAuthenticationRequire = false;

//coap basic setting
if(_objDevice.protocol=="COAP")
_objDeviceTemplate.coapURL = _objDevice.hostName;

//http basic setting
if(_objDevice.protocol=="HTTP")
_objDeviceTemplate.httpURL = _objDevice.hostName;

int  templateID = 0;

//saving parent table "device template"
dlDeviceTemplate *_dlDeviceTemplate = new dlDeviceTemplate();
templateID =  _dlDeviceTemplate->InsertForUseCase(_objDeviceTemplate);


if(templateID>0)
{
  //saving mqtt subscribe details
    dlDeviceSubscribeData _dlDeviceSubscribeData;
 // _dlDeviceSubscribeData.DelSubscribeData(templateID);

  for(int i=0;i<_objDevice.lstSubTopic.count();i++)
  {
      _objDevice.isSubscriber = true;
      objDeviceSubscribeData _objDeviceSubscribeData;
      _objDeviceSubscribeData.topicID = _objDevice.lstSubTopic[i].topicID;
      _objDeviceSubscribeData.deviceTemplateID = templateID;
      _dlDeviceSubscribeData.InsertForUseCase(_objDeviceSubscribeData);
  }

  //save mqtt publish details
     dlDevicePublishData _dlDevicePublishData;
//  _dlDevicePublishData.DelPublishData(templateID);
  for(int j=0; j<_objDevice.lstPubTopic.count();j++)
  {
     // titles2<<"TopicID"<<"DataProfileID"<<"TimeProfileID"<<"Topic"<<"QoS"<<"Data Profile"<<"Time Profile"<<" ";
       _objDevice.isPublisher = true;
       objDevicePublishData _objDevicePublishData;
      _objDevicePublishData.deviceTemplateID = templateID;
      _objDevicePublishData.topicID = _objDevice.lstPubTopic[j].topicID;
      _objDevicePublishData.dataProfileID = _objDevice.lstPubTopic[j].dataProfileID;
      _objDevicePublishData.timeProfileID = _objDevice.lstPubTopic[j].timeProfileID;

      _objDevicePublishData.topic = _objDevice.lstPubTopic[j].topic;
      _objDevicePublishData.QoS = _objDevice.lstPubTopic[j].QoS;
      _dlDevicePublishData.InsertForUseCase(_objDevicePublishData);


  }

  //save coap detials
  dlDeviceCoapData _dlDeviceCoapData;
 // _dlDeviceCoapData.DelCoapData(templateID);
 //titles3<<"URL"<<"Command"<<"parameters"<<"TimeProfileID"<<"Time Profile"<<"";
  for(int j=0; j<_objDevice.lstDeviceCoapData.count();j++)
  {
      objDeviceCoapData _objDeviceCoapData;
      _objDeviceCoapData.deviceTemplateID = templateID;
      _objDeviceCoapData.url = _objDevice.lstDeviceCoapData[j].url;
      _objDeviceCoapData.coapCommand = _objDevice.lstDeviceCoapData[j].coapCommand;
      //_objDeviceCoapData.parameters = _objDevice.lstDeviceCoapData[j].parameters;
      //_objDeviceCoapData.parametersWithID = _objDevice.lstDeviceCoapData[j].parametersWithID;
       _objDeviceCoapData.coapTimeProfileID = _objDevice.lstDeviceCoapData[j]._objTimeProfile._id;
       _objDeviceCoapData.timeprofile = _objDevice.lstDeviceCoapData[j].timeprofile;
       _objDeviceCoapData.coapDataProfileID = _objDevice.lstDeviceCoapData[j]._objDataProfile._id;
       _objDeviceCoapData.dataprofile = _objDevice.lstDeviceCoapData[j].dataprofile;
       dlDeviceCoapData _dlDeviceCoapData;
      _dlDeviceCoapData.InsertForUseCase(_objDeviceCoapData);
  }

  //save http details
  dlDeviceHttpData _dlDeviceHttpData;
  //_dlDeviceHttpData.DelHttpData(templateID);

  for(int j=0; j<_objDevice.lstDeviceHttpData.count();j++)
  {
      objDeviceHttpData _objDeviceHttpData;
      _objDeviceHttpData.deviceTemplateID = templateID;
      _objDeviceHttpData.url = _objDevice.lstDeviceHttpData[j].url;
     _objDeviceHttpData.httpCommand = _objDevice.lstDeviceHttpData[j].httpCommand;
    // _objDeviceHttpData.parameters = _objDevice.lstDeviceHttpData[j].parameters;
    // _objDeviceHttpData.parametersWithID = _objDevice.lstDeviceHttpData[j].parametersWithID;
     _objDeviceHttpData.httpTimeProfileID = _objDevice.lstDeviceHttpData[j]._objTimeProfile._id;
     _objDeviceHttpData.timeprofile = _objDevice.lstDeviceHttpData[j].timeprofile;
     _objDeviceHttpData.httpDataProfileID = _objDevice.lstDeviceHttpData[j]._objDataProfile._id;
     _objDeviceHttpData.dataprofile = _objDevice.lstDeviceHttpData[j].dataprofile;
     dlDeviceHttpData _dlDeviceHttpData;
     _dlDeviceHttpData.InsertForUseCase(_objDeviceHttpData);
  }


    qDebug()<<"Successfully inserted";

}
else {
    return false;

  qDebug()<<"Error while inserting";


}
mutex.unlock();
return  true;
}
void *CreateDeviceThread(void *threadid)
{

    objDevice* d = static_cast<objDevice*>(threadid);
    objDevice _objDevice;
    _objDevice.IPCount = d->IPCount;
     _objDevice.attackType = d->attackType;
      _objDevice.deviceName = d->deviceName;
       _objDevice.hostName = d->hostName;
        _objDevice.interval = d->interval;
         _objDevice.isAttackingEntity = d->isAttackingEntity;
          _objDevice.isAuthenticationRequire = d->isAuthenticationRequire;
           _objDevice.isPublisher = d->isPublisher;
            _objDevice.lastActivity = d->lastActivity;
             _objDevice.lstDeviceCoapData = d->lstDeviceCoapData;
              _objDevice.lstDeviceHttpData = d->lstDeviceHttpData;
               _objDevice.lstPubTopic = d->lstPubTopic;
                _objDevice.lstSubTopic = d->lstSubTopic;
                 _objDevice.message = d->message;
                  _objDevice.password = d->password;
                   _objDevice.port = d->port;
                    _objDevice.portType = d->portType;
                     _objDevice.protocol = d->protocol;
                      _objDevice.sHostName = d->sHostName;
                       _objDevice.sourceIP = d->sourceIP;
                        _objDevice.targetIP = d->targetIP;
                         _objDevice.targetPort = d->targetPort;
                          _objDevice.templateID = d->templateID;
                            _objDevice.useCaseID = d->useCaseID;
                              _objDevice.useCaseName = d->useCaseName;
                                _objDevice.userName = d->userName;


      bool isSave =  false;
      FileHandler _FileHandler;
      QString initialPrint ="";
      initialPrint += "\nDevice Name="+ _objDevice.deviceName + "\n";
      initialPrint += "IP="+ _objDevice.sHostName + "\n";
      initialPrint += "Protocol="+_objDevice.protocol + "\n";
      initialPrint += "IsAttackingEntity="+ QString::number(_objDevice.isAttackingEntity) + "\n";
      if(_objDevice.isAttackingEntity)
      {
          initialPrint += "AttackType="+ _objDevice.attackType + "\n";
          initialPrint +="SourceIP="+ _objDevice.sourceIP +"\n";
          initialPrint += "TargetIP="+ _objDevice.targetIP + "\n";
          initialPrint += "TargetPort="+ QString::number(_objDevice.targetPort) + "\n";
          initialPrint += "Messages/sec="+ QString::number(_objDevice.interval) + "\n";
          initialPrint +="Message="+ _objDevice.message +"\n";
      }

      if(_objDevice.protocol == "MQTT")
      {
          initialPrint += "**********MQTT DETAILS START**************\n";
          initialPrint += "Brooker IP="+_objDevice.hostName + "\n";
          if(_objDevice.isAuthenticationRequire)
          {
              initialPrint += "Authentication Require:"+QString::number( _objDevice.isAuthenticationRequire) +"\n";
              initialPrint += "UserName:"+_objDevice.userName +"\n";
              initialPrint += "Password:"+_objDevice.password +"\n";
          }

          initialPrint += "**********MQTT SUBSCRIBE DETAIL**************\n";
          for(int i=0;i<_objDevice.lstSubTopic.count();i++)
          {
              initialPrint += "Subscribe Topic="+_objDevice.lstSubTopic[i].topicName + "\n";
          }
          initialPrint += "**********MQTT PUBLISH DETAIL**************\n";
          for(int i=0;i<_objDevice.lstPubTopic.count();i++)
          {
              initialPrint += "Publish Topic="+_objDevice.lstPubTopic[i].topic + "\n";
              initialPrint += "Publish QoS="+QString::number(_objDevice.lstPubTopic[i].QoS) + "\n";
              initialPrint += "Publish timeprofile="+_objDevice.lstPubTopic[i]._objTimeProfile.name + "\n";
              initialPrint += "Publish dataprofile="+_objDevice.lstPubTopic[i]._objDataProfile.name + "\n";
          }
          initialPrint += "**********MQTT DETAILS END**************\n";
      }
      else if(_objDevice.protocol == "COAP")
      {
          initialPrint += "**********COAP DETAILS START**************\n";

          for(int i=0;i<_objDevice.lstDeviceCoapData.count();i++)
          {
             initialPrint += "Coap URL="+_objDevice.lstDeviceCoapData[i].url + "\n";
             initialPrint += "Coap Command="+_objDevice.lstDeviceCoapData[i].coapCommand + "\n";
             initialPrint += "Coap timeprofile="+_objDevice.lstDeviceCoapData[i].timeprofile + "\n";
             initialPrint += "Coap Dataprofile="+_objDevice.lstDeviceCoapData[i].dataprofile + "\n";
            // initialPrint += "Coap parameters=CreateDevice"+_objDevice.lstDeviceCoapData[i].parameters + "\n";
          }

          initialPrint += "**********COAP DETAILS END**************\n";
      }
      else if(_objDevice.protocol == "HTTP")
      {
          initialPrint += "**********HTTP DETAILS START**************\n";

          for(int i=0;i<_objDevice.lstDeviceHttpData.count();i++)
          {
             initialPrint += "HTTP URL="+_objDevice.lstDeviceHttpData[i].url + "\n";
             initialPrint += "HTTP Command="+_objDevice.lstDeviceHttpData[i].httpCommand + "\n";
             initialPrint += "HTTP timeprofile="+_objDevice.lstDeviceHttpData[i].timeprofile + "\n";
              initialPrint += "HTTP dataprofile="+_objDevice.lstDeviceHttpData[i].dataprofile + "\n";
          //   initialPrint += "HTTP parameters="+_objDevice.lstDeviceHttpData[i].parameters + "\n";
          }

          initialPrint += "**********HTTP DETAILS END**************\n";
      }


//data
    //  _FileHandler.writeFile(_objDevice.sHostName,initialPrint,false);
      QNetworkInterface interface;
      QList<QNetworkInterface> IpList = interface.allInterfaces();
       QByteArray interfaceName;
       for (int i = 0; i < IpList.size(); i++)
       {
           if(IpList[i].name()!= "lo" )
           {
               interfaceName.append(IpList[i].name());
               //qDebug()<< "Interface " << i << ":" << IpList.at(i).name() << endl;
               break;
           }
       }
//" + interfaceName +"

     //const char* ipval = "sudo -S ifconfig wlp1s0:"+ QString(j).toUtf8() + " " + __objDevice.sHostName.toUtf8() + " up";
//--------------------- Comment for Lab PC --------------------
      // QString command ="sudo -S ifconfig wlp1s0:"+ QString::number(jj) + " " + _objDevice.sHostName + " up";
//--------------------- Comment for Laptop --------------------
       QString command ="sudo -S ifconfig enp0s3:"+ QString::number(jj) + " " + _objDevice.sHostName + " up";
       char* ipval = new char[(command.length() + 1)];
       strcpy(ipval, command.toLatin1().constData());
       //qDebug()<<"ipval:"<<ipval;
       system(ipval);
       jj++;
      Device *device =  new Device(_objDevice);
      lstWorkers.append(device);

     // if(isSaveDB)
     // SaveUseCaseDeviceThread(_objDevice);


      //if(isSave)
      //SaveUseCaseDevice(_objDevice);
      //lastError = "";
     // return true;



}



ThreadMain::ThreadMain()
{

}

bool ThreadMain::CreateDevice(objDevice _objDevice,bool isSave)
{

    /*
      FileHandler _FileHandler;
      QString initialPrint ="";
      initialPrint += "\nDevice Name="+ _objDevice.deviceName + "\n";
      initialPrint += "IP="+ _objDevice.sHostName + "\n";
      initialPrint += "Protocol="+_objDevice.protocol + "\n";
      initialPrint += "IsAttackingEntity="+ QString::number(_objDevice.isAttackingEntity) + "\n";
      if(_objDevice.isAttackingEntity)
      {
          initialPrint += "AttackType="+ _objDevice.attackType + "\n";
          initialPrint +="SourceIP="+ _objDevice.sourceIP +"\n";
          initialPrint += "TargetIP="+ _objDevice.targetIP + "\n";
          initialPrint += "TargetPort="+ QString::number(_objDevice.targetPort) + "\n";
          initialPrint += "Messages/sec="+ QString::number(_objDevice.interval) + "\n";
          initialPrint +="Message="+ _objDevice.message +"\n";
      }

      if(_objDevice.protocol == "MQTT")
      {
          initialPrint += "**********MQTT DETAILS START**************\n";
          initialPrint += "Brooker IP="+_objDevice.protocol + "\n";
          if(_objDevice.isAuthenticationRequire)
          {
              initialPrint += "Authentication Require:"+QString::number( _objDevice.isAuthenticationRequire) +"\n";
              initialPrint += "UserName:"+_objDevice.userName +"\n";
              initialPrint += "Password:"+_objDevice.password +"\n";
          }

          initialPrint += "**********MQTT SUBSCRIBE DETAIL**************\n";
          for(int i=0;i<_objDevice.lstSubTopic.count();i++)
          {
              initialPrint += "Subscribe Topic="+_objDevice.lstSubTopic[i].topicName + "\n";
          }
          initialPrint += "**********MQTT PUBLISH DETAIL**************\n";
          for(int i=0;i<_objDevice.lstPubTopic.count();i++)
          {
              initialPrint += "Publish Topic="+_objDevice.lstPubTopic[i].topic + "\n";
              initialPrint += "Publish QoS="+QString::number(_objDevice.lstPubTopic[i].QoS) + "\n";
              initialPrint += "Publish timeprofile="+_objDevice.lstPubTopic[i]._objTimeProfile.name + "\n";
              initialPrint += "Publish dataprofile="+_objDevice.lstPubTopic[i]._objDataProfile.name + "\n";
          }
          initialPrint += "**********MQTT DETAILS END**************\n";
      }
      else if(_objDevice.protocol == "COAP")
      {
          initialPrint += "**********COAP DETAILS START**************\n";

          for(int i=0;i<_objDevice.lstDeviceCoapData.count();i++)
          {
             initialPrint += "Coap URL="+_objDevice.lstDeviceCoapData[i].url + "\n";
             initialPrint += "Coap Command="+_objDevice.lstDeviceCoapData[i].coapCommand + "\n";
             initialPrint += "Coap timeprofile="+_objDevice.lstDeviceCoapData[i].timeprofile + "\n";
             initialPrint += "Coap Dataprofile="+_objDevice.lstDeviceCoapData[i].dataprofile + "\n";
            // initialPrint += "Coap parameters=CreateDevice"+_objDevice.lstDeviceCoapData[i].parameters + "\n";
          }

          initialPrint += "**********COAP DETAILS END**************\n";
      }
      else if(_objDevice.protocol == "HTTP")
      {
          initialPrint += "**********HTTP DETAILS START**************\n";

          for(int i=0;i<_objDevice.lstDeviceHttpData.count();i++)
          {
             initialPrint += "HTTP URL="+_objDevice.lstDeviceHttpData[i].url + "\n";
             initialPrint += "HTTP Command="+_objDevice.lstDeviceHttpData[i].httpCommand + "\n";
             initialPrint += "HTTP timeprofile="+_objDevice.lstDeviceHttpData[i].timeprofile + "\n";
              initialPrint += "HTTP dataprofile="+_objDevice.lstDeviceHttpData[i].dataprofile + "\n";
          //   initialPrint += "HTTP parameters="+_objDevice.lstDeviceHttpData[i].parameters + "\n";
          }

          initialPrint += "**********HTTP DETAILS END**************\n";
      }


//data
      _FileHandler.writeFile(_objDevice.sHostName,initialPrint,false);

      */
      QNetworkInterface interface;
      QList<QNetworkInterface> IpList = interface.allInterfaces();
       QByteArray interfaceName;
       for (int i = 0; i < IpList.size(); i++)
       {
           if(IpList[i].name()!= "lo" )
           {
               interfaceName.append(IpList[i].name());
               //qDebug()<< "Interface " << i << ":" << IpList.at(i).name() << endl;
               break;
           }
       }
//" + interfaceName +"

     //const char* ipval = "sudo -S ifconfig wlp1s0:"+ QString(j).toUtf8() + " " + __objDevice.sHostName.toUtf8() + " up";

       QString command ="sudo -S ifconfig enp0s3:"+ QString::number(j) + " " + _objDevice.sHostName + " up";
       char* ipval = new char[(command.length() + 1)];
       strcpy(ipval, command.toLatin1().constData());
       //qDebug()<<"ipval:"<<ipval;
       system(ipval);
       j++;
      Device *device =  new Device(_objDevice);

       //Device device(_objDevice);
       //lstWorkers.append(device);
      if(isSave)
        SaveUseCaseDevice(_objDevice);
      lastError = "";
      return true;
}
//typedef  void* (ThreadMain::*CreateDeviceThread)(void *threadid);
void ThreadMain::CreateDevices(objDevice __objDevice)
{
    char ip_buff[16];
    ipstr2dec(__objDevice.sHostName);
    unsigned long max_ips = from + __objDevice.IPCount;
    while ((from < max_ips) && (from < to))
    {
        getNextIP(ip_buff);
        //objDevice _objDevice(__objDevice);
        //_objDevice.sHostName = ip_buff;

        __objDevice.sHostName = ip_buff;

    /*    //const char* ipval = "sudo -S ifconfig wlp1s0:"+ QString(j).toUtf8() + " " + __objDevice.sHostName.toUtf8() + " up";
         QNetworkInterface interface;
         QList<QNetworkInterface> IpList = interface.allInterfaces();
          QByteArray interfaceName;
          for (int i = 0; i < IpList.size(); i++)
          {
              if(IpList[i].name()!= "lo" )
              {
                  interfaceName.append(IpList[i].name());
                  //qDebug()<< "Interface " << i << ":" << IpList.at(i).name() << endl;
                  break;
              }
          }
//" + interfaceName +"

        //const char* ipval = "sudo -S ifconfig wlp1s0:"+ QString(j).toUtf8() + " " + __objDevice.sHostName.toUtf8() + " up";

          QString command ="sudo -S ifconfig wlp1s0:"+ QString::number(j) + " " + __objDevice.sHostName + " up";
          char* ipval = new char[(command.length() + 1)];
          strcpy(ipval, command.toLatin1().constData());
          qDebug()<<"ipval:"<<ipval;
          system(ipval);
          j++;

          */

        CreateDevice(__objDevice,true);
        /*   int rc;
            pthread_t threads;

 isSaveDB =true;
            objDevice *obj1 = new objDevice();
            obj1->IPCount = __objDevice.IPCount;
              obj1->attackType = __objDevice.attackType;
               obj1->deviceName = __objDevice.deviceName;
                obj1->hostName = __objDevice.hostName;
                 obj1->interval = __objDevice.interval;
                  obj1->isAttackingEntity = __objDevice.isAttackingEntity;
                   obj1->isAuthenticationRequire = __objDevice.isAuthenticationRequire;
                    obj1->isPublisher = __objDevice.isPublisher;
                     obj1->lastActivity = __objDevice.lastActivity;
                      obj1->lstDeviceCoapData = __objDevice.lstDeviceCoapData;
                       obj1->lstDeviceHttpData = __objDevice.lstDeviceHttpData;
                        obj1->lstPubTopic = __objDevice.lstPubTopic;
                         obj1->lstSubTopic = __objDevice.lstSubTopic;
                          obj1->message = __objDevice.message;
                           obj1->password = __objDevice.password;
                            obj1->port = __objDevice.port;
                             obj1->portType = __objDevice.portType;
                              obj1->protocol = __objDevice.protocol;
                               obj1->sHostName = __objDevice.sHostName;
                                obj1->sourceIP = __objDevice.sourceIP;
                                 obj1->targetIP = __objDevice.targetIP;
                                  obj1->targetPort = __objDevice.targetPort;
                                   obj1->templateID = __objDevice.templateID;
                                     obj1->useCaseID = __objDevice.useCaseID;
                                       obj1->useCaseName = __objDevice.useCaseName;
                                         obj1->userName = __objDevice.userName;
           rc = pthread_create(&threads, NULL,CreateDeviceThread,obj1);

           QString p = "";
           //       QMetaObject::invokeMethod(this, "CreateDeviceThread", Qt::QueuedConnection,Q_ARG(QString, obj1));
           if (rc) {
             printf("ERROR; return code from pthread_create() is %d\n", rc);
             exit(-1);
             }
             */
    }
    //qDebug()<<"END Time:"<<QDateTime::currentDateTime()<<"\n";
  //  qDebug()<<"CreateDevice : "<<CreateDevice(__objDevice);
}

void ThreadMain::CreateDevicesNew(objDevice __objDevice)
{
    char ip_buff[16];
    ipstr2dec(__objDevice.sHostName);
    unsigned long max_ips = from + __objDevice.IPCount;
    while ((from < max_ips) && (from < to))
    {
        getNextIP(ip_buff);
        __objDevice.sHostName = ip_buff;

        //CreateDevice(__objDevice,true);
        SaveUseCaseDevice(__objDevice);


    }
    //qDebug()<<"END Time:"<<QDateTime::currentDateTime()<<"\n";
  //  qDebug()<<"CreateDevice : "<<CreateDevice(__objDevice);
}


QString ThreadMain::GetDevicesInfo()
{
    QString finalOutput = "";
   // mutex.lock();
    {
        QString output = "";
        for(int i=0;i<lstWorkers.count();i++)
        {
            output = output + lstWorkers[i]->_objDevice.sHostName+","+
                     lstWorkers[i]->_objDevice.protocol+","+
                     lstWorkers[i]->m_client->state()+"\n";

        }

        finalOutput = output;
    }
   // mutex.unlock();
return finalOutput;
}


bool ThreadMain::RemoveDevice(QString _IP)
{
   // mutex.lock();
    {
        for(int i=0;i<lstWorkers.count();i++)
        {
            if(lstWorkers[i]->objectName() == _IP)
            {
                //lstWorkers[i]->abort();
                delete lstWorkers[i];
                i--;
                qDebug()<<lstWorkers.count() + " "+ _IP<<"\n";
                break;
            }
        }
    }
   // mutex.unlock();
    return true;
}



// //////////////////////IP Checks\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

bool ThreadMain::isIPinUse(QString _IP)
{
    QString output = "";
   // mutex.lock();
    {
        for(int i=0;i<lstWorkers.count();i++)
        {
            if(lstWorkers[i]->objectName() == _IP)
            {
                lastError = _IP + "IP INUSE" ;
                qDebug()<<_IP<<" INUSE\n";
                break;
            }
        }
    }
   // mutex.unlock();

    if(lastError == "")
        return   false;
    return  true;
}

void ThreadMain::getNextIP(char ip_addr[]){

    unsigned char *ip;
    ip = (unsigned char *)&from;
    if (ip[0] == 0){
        from++;
    }
    else if (ip[0] == 255){
        from += 2;
    }

    ip = (unsigned char *)&from;
    sprintf(ip_addr, "%u.%u.%u.%u", ip[3], ip[2], ip[1], ip[0]);
    from++;
}

void ThreadMain::ipstr2dec(QString ip)
{
    QStringList server_octets = ip.split(".");
    unsigned int s1 = server_octets.at(0).toUInt();
    unsigned int s2 = server_octets.at(1).toUInt();
    unsigned int s3 = server_octets.at(2).toUInt();
    unsigned int s4 = server_octets.at(3).toUInt();
    from = INETADDR(s1,s2,s3,s4);
    to   = INETADDR(255,255,255,254);
}


// //////////////////////DESTRUCTOR\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

ThreadMain::~ThreadMain()
{

}

bool ThreadMain::SaveUseCase(QString ucName){

    dlUseCase _dlUseCase;
    objUseCase _objUseCase;
    _objUseCase.name = ucName;
    int useCaseID =  _dlUseCase.Insert(_objUseCase);

    for(int j=0;j<lstWorkers.count();j++)
    {
        SaveUseCaseDevice(lstWorkers[j]->_objDevice);
    }
    qDebug()<<"Successfully Done";

    return true;

}


bool ThreadMain::SaveUseCaseDevice(objDevice _objDevice)
{

    //objDevice _objDevice = lstWorkers[j]->_objDevice;
    objDeviceTemplate _objDeviceTemplate;
    _objDeviceTemplate.deviceName = _objDevice.deviceName;
    _objDeviceTemplate.useCaseID = _objDevice.useCaseID;
    _objDeviceTemplate.NumofDevices = 1; //====
    //general tab information
    _objDeviceTemplate.deviceProtocol =_objDevice.protocol;
    _objDeviceTemplate.IPAddress =     _objDevice.sHostName;


    _objDeviceTemplate.isAttackingEntity = _objDevice.isAttackingEntity;
   if(_objDevice.isAttackingEntity)
   {
       _objDeviceTemplate.attackType = _objDevice.attackType;
       _objDeviceTemplate.sourceIP = _objDevice.sourceIP;
       _objDeviceTemplate.targetIP = _objDevice.targetIP;
       _objDeviceTemplate.targetPort = _objDevice.targetPort;
       _objDeviceTemplate.interval = _objDevice.interval;
       _objDeviceTemplate.message = _objDevice.message;

   }

//mqtt basic setting
_objDeviceTemplate.brokerIP = _objDevice.hostName;
if(_objDevice.portType == "REGULAR")
 {
   _objDeviceTemplate.isRegularPort = true;
   _objDeviceTemplate.portNO= _objDevice.port;
  }
  else
   {
    _objDeviceTemplate.isRegularPort = false;
    _objDeviceTemplate.portNO = _objDevice.port;
   }

   if(_objDevice.isAuthenticationRequire)
   {
       _objDeviceTemplate.isAuthenticationRequire = true;
       _objDeviceTemplate.brokerUserName = _objDevice.userName;
       _objDeviceTemplate.brokerPassword = _objDevice.password;
   }
   else
       _objDeviceTemplate.isAuthenticationRequire = false;

//coap basic setting
if(_objDevice.protocol=="COAP")
_objDeviceTemplate.coapURL = _objDevice.hostName;

//http basic setting
if(_objDevice.protocol=="HTTP")
_objDeviceTemplate.httpURL = _objDevice.hostName;

int  templateID = 0;

//saving parent table "device template"
dlDeviceTemplate *_dlDeviceTemplate = new dlDeviceTemplate();
templateID =  _dlDeviceTemplate->InsertForUseCase(_objDeviceTemplate);


if(templateID>0)
{
  //saving mqtt subscribe details
    dlDeviceSubscribeData _dlDeviceSubscribeData;
 // _dlDeviceSubscribeData.DelSubscribeData(templateID);

  for(int i=0;i<_objDevice.lstSubTopic.count();i++)
  {
      _objDevice.isSubscriber = true;
      objDeviceSubscribeData _objDeviceSubscribeData;
      _objDeviceSubscribeData.topicID = _objDevice.lstSubTopic[i].topicID;
      _objDeviceSubscribeData.deviceTemplateID = templateID;
      _dlDeviceSubscribeData.InsertForUseCase(_objDeviceSubscribeData);
  }

  //save mqtt publish details
     dlDevicePublishData _dlDevicePublishData;
//  _dlDevicePublishData.DelPublishData(templateID);
  for(int j=0; j<_objDevice.lstPubTopic.count();j++)
  {
     // titles2<<"TopicID"<<"DataProfileID"<<"TimeProfileID"<<"Topic"<<"QoS"<<"Data Profile"<<"Time Profile"<<" ";
       _objDevice.isPublisher = true;
       objDevicePublishData _objDevicePublishData;
      _objDevicePublishData.deviceTemplateID = templateID;
      _objDevicePublishData.topicID = _objDevice.lstPubTopic[j].topicID;
      _objDevicePublishData.dataProfileID = _objDevice.lstPubTopic[j].dataProfileID;
      _objDevicePublishData.timeProfileID = _objDevice.lstPubTopic[j].timeProfileID;

      _objDevicePublishData.topic = _objDevice.lstPubTopic[j].topic;
      _objDevicePublishData.QoS = _objDevice.lstPubTopic[j].QoS;
      _dlDevicePublishData.InsertForUseCase(_objDevicePublishData);


  }

  //save coap detials
  dlDeviceCoapData _dlDeviceCoapData;
 // _dlDeviceCoapData.DelCoapData(templateID);
 //titles3<<"URL"<<"Command"<<"parameters"<<"TimeProfileID"<<"Time Profile"<<"";
  for(int j=0; j<_objDevice.lstDeviceCoapData.count();j++)
  {
      objDeviceCoapData _objDeviceCoapData;
      _objDeviceCoapData.deviceTemplateID = templateID;
      _objDeviceCoapData.url = _objDevice.lstDeviceCoapData[j].url;
      _objDeviceCoapData.coapCommand = _objDevice.lstDeviceCoapData[j].coapCommand;
      //_objDeviceCoapData.parameters = _objDevice.lstDeviceCoapData[j].parameters;
      //_objDeviceCoapData.parametersWithID = _objDevice.lstDeviceCoapData[j].parametersWithID;
       _objDeviceCoapData.coapTimeProfileID = _objDevice.lstDeviceCoapData[j]._objTimeProfile._id;
       _objDeviceCoapData.timeprofile = _objDevice.lstDeviceCoapData[j].timeprofile;
       _objDeviceCoapData.coapDataProfileID = _objDevice.lstDeviceCoapData[j]._objDataProfile._id;
       _objDeviceCoapData.dataprofile = _objDevice.lstDeviceCoapData[j].dataprofile;
       dlDeviceCoapData _dlDeviceCoapData;
      _dlDeviceCoapData.InsertForUseCase(_objDeviceCoapData);
  }

  //save http details
  dlDeviceHttpData _dlDeviceHttpData;
  //_dlDeviceHttpData.DelHttpData(templateID);

  for(int j=0; j<_objDevice.lstDeviceHttpData.count();j++)
  {
      objDeviceHttpData _objDeviceHttpData;
      _objDeviceHttpData.deviceTemplateID = templateID;
      _objDeviceHttpData.url = _objDevice.lstDeviceHttpData[j].url;
     _objDeviceHttpData.httpCommand = _objDevice.lstDeviceHttpData[j].httpCommand;
    // _objDeviceHttpData.parameters = _objDevice.lstDeviceHttpData[j].parameters;
    // _objDeviceHttpData.parametersWithID = _objDevice.lstDeviceHttpData[j].parametersWithID;
     _objDeviceHttpData.httpTimeProfileID = _objDevice.lstDeviceHttpData[j]._objTimeProfile._id;
     _objDeviceHttpData.timeprofile = _objDevice.lstDeviceHttpData[j].timeprofile;
     _objDeviceHttpData.httpDataProfileID = _objDevice.lstDeviceHttpData[j]._objDataProfile._id;
     _objDeviceHttpData.dataprofile = _objDevice.lstDeviceHttpData[j].dataprofile;
     dlDeviceHttpData _dlDeviceHttpData;
     _dlDeviceHttpData.InsertForUseCase(_objDeviceHttpData);
  }
  return  true;

    qDebug()<<"Successfully inserted";

}
else {
    return false;

  qDebug()<<"Error while inserting";


}

}
bool ThreadMain::SaveUseCaseXML(int UseCaseID, bool isRun){

    dlDeviceTemplate _dlDeviceTemplate;
    QList<objDevice> lstObjDevice = _dlDeviceTemplate.GetDeviceListForUseCase(UseCaseID);

    QString filename = "";
    if(!isRun)
            filename = QFileDialog::getSaveFileName(this, tr("Save Xml"), ".", tr("Xml files (*.xml)"));
    else
        filename = "output";

        QFile file(filename+".xml");
        //QFile file("UseCase.xml");
        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("UseCase");
        //xmlWriter.writeAttribute("UseCase_Name",QString("Use Case Name"));

        for(int k=0;k<lstObjDevice.length();k++)
        {
             objDevice _objDevice  = lstObjDevice[k] ;

        //Device Details
        xmlWriter.writeStartElement("Device");
        xmlWriter.writeTextElement("Device_Name",_objDevice.deviceName);
        xmlWriter.writeTextElement("Protocol", _objDevice.protocol );
        xmlWriter.writeTextElement("IP_Address", _objDevice.sHostName);
        xmlWriter.writeTextElement("Num_Of_Devices", QString::number(_objDevice.IPCount));
        xmlWriter.writeTextElement("Is_AttackingEntity", QString::number(_objDevice.isAttackingEntity));
        xmlWriter.writeTextElement("Attack_Type", _objDevice.attackType );
        xmlWriter.writeTextElement("Source_IP", _objDevice.sourceIP );
        xmlWriter.writeTextElement("Target_IP", _objDevice.targetIP );
        xmlWriter.writeTextElement("Target_Port", QString::number(_objDevice.targetPort) );
        xmlWriter.writeTextElement("Messages_Per_Sec", QString::number(_objDevice.interval) );
        xmlWriter.writeTextElement("Message", _objDevice.message );

        if( _objDevice.protocol == "MQTT")
        {
            //MQTT Deatails
             xmlWriter.writeStartElement("MQTT");
             xmlWriter.writeTextElement("Brooker_IP",_objDevice.hostName );
             xmlWriter.writeTextElement("Is_Authentication_Require",QString::number( _objDevice.isAuthenticationRequire) );
             xmlWriter.writeTextElement("User_Name",_objDevice.userName );
             xmlWriter.writeTextElement("Password",_objDevice.password );
             xmlWriter.writeTextElement("Port",QString::number(_objDevice.port) );

             //Subscribe Details

             for(int i=0;i<_objDevice.lstSubTopic.count();i++)
             {
                 xmlWriter.writeStartElement("Subscribe_Detail");
                 xmlWriter.writeTextElement("Topic",_objDevice.lstSubTopic[i].topicName );
                 xmlWriter.writeEndElement();
             }

             //Publish Details

              for(int i=0;i<_objDevice.lstPubTopic.count();i++)
              {
                 xmlWriter.writeStartElement("Publish_Detail");
                 xmlWriter.writeTextElement("Topic",_objDevice.lstPubTopic[i].topic );
                 xmlWriter.writeTextElement("QoS",QString::number(_objDevice.lstPubTopic[i].QoS) );
                 xmlWriter.writeTextElement("Time_Profile_Type",_objDevice.lstPubTopic[i]._objTimeProfile.type );
                 xmlWriter.writeTextElement("Time_Profile_Interval", QString::number(_objDevice.lstPubTopic[i]._objTimeProfile.interval) );
                 xmlWriter.writeTextElement("Time_Profile_RandomFrom", QString::number(_objDevice.lstPubTopic[i]._objTimeProfile.randomFrom) );
                 xmlWriter.writeTextElement("Time_Profile_RandomTo", QString::number(_objDevice.lstPubTopic[i]._objTimeProfile.randomTo) );

                 xmlWriter.writeTextElement("Data_Profile_IsStartText",QString::number(_objDevice.lstPubTopic[i]._objDataProfile.isStartText) );
                 xmlWriter.writeTextElement("Data_Profile_StartText", _objDevice.lstPubTopic[i]._objDataProfile.startText );
                 xmlWriter.writeTextElement("Data_Profile_IsRandom",QString::number( _objDevice.lstPubTopic[i]._objDataProfile.isRandom) );
                 xmlWriter.writeTextElement("Data_Profile_RandomFrom",QString::number( _objDevice.lstPubTopic[i]._objDataProfile.randomFrom) );
                 xmlWriter.writeTextElement("Data_Profile_RandomTo",QString::number( _objDevice.lstPubTopic[i]._objDataProfile.randomTo) );
                 xmlWriter.writeTextElement("Data_Profile_IsEndText",QString::number(_objDevice.lstPubTopic[i]._objDataProfile.isEndText) );
                 xmlWriter.writeTextElement("Data_Profile_EndText", _objDevice.lstPubTopic[i]._objDataProfile.endText );
                 xmlWriter.writeEndElement(); //end Publish Details
              }

              xmlWriter.writeEndElement(); //end MQTT deatails
            }
        else
        {
            for(int j=0; j<_objDevice.lstDeviceCoapData.count();j++)
            {
                //CoAP Detaails
                xmlWriter.writeStartElement("COAP");
                xmlWriter.writeTextElement("Coap_URL",_objDevice.lstDeviceCoapData[j].url);
                xmlWriter.writeTextElement("Coap_Command",_objDevice.lstDeviceCoapData[j].coapCommand );
                xmlWriter.writeTextElement("Time_Profile_Type",_objDevice.lstDeviceCoapData[j]._objTimeProfile.type);
                xmlWriter.writeTextElement("Time_Profile_Interval",QString::number(_objDevice.lstDeviceCoapData[j]._objTimeProfile.interval));
                xmlWriter.writeTextElement("Time_Profile_RandomFrom",QString::number(_objDevice.lstDeviceCoapData[j]._objTimeProfile.randomFrom));
                xmlWriter.writeTextElement("Time_Profile_RandomTo",QString::number(_objDevice.lstDeviceCoapData[j]._objTimeProfile.randomTo));
                //Data Profile Details
                xmlWriter.writeTextElement("Data_Profile_IsStartText",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.isStartText));
                xmlWriter.writeTextElement("Data_Profile_StartText",_objDevice.lstDeviceCoapData[j]._objDataProfile.startText);
                xmlWriter.writeTextElement("Data_Profile_IsRandom",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.isRandom));
                xmlWriter.writeTextElement("Data_Profile_RandomFrom",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.randomFrom));
                xmlWriter.writeTextElement("Data_Profile_RandomTo",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.randomTo));
                xmlWriter.writeTextElement("Data_Profile_IsEndText",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.isEndText));
                xmlWriter.writeTextElement("Data_Profile_EndText",_objDevice.lstDeviceCoapData[j]._objDataProfile.endText);
                xmlWriter.writeEndElement(); //end Coap Details
            }


        }
         xmlWriter.writeEndElement(); //end Device Details
    }

        xmlWriter.writeEndElement(); //end UseCase Details

    file.close();

   if(isRun)
   {

       QString command =QString("sudo ./consoleApp ") + "'/home/iot/Desktop/WorkingFolder/build-IOT Advanced Data Generator-Desktop_Qt_5_11_2_GCC_64bit-Debug/UseCase.xml'";

     //  QString command ="sudo ./consoleApp " + "\\home\\iot\\Desktop\\WorkingFolder\\build-IOT Advanced Data Generator-Desktop_Qt_5_11_2_GCC_64bit-Debug\\"+"UseCase.xml";

       qDebug()<<"command: "<<command;
       char* ipval = new char[(command.length() + 1)];
       strcpy(ipval, command.toLatin1().constData());
       //qDebug()<<"ipval:"<<ipval;
       system(ipval);

   }

    return true;

}
QString ThreadMain::GenerateUseCaseXML(int UseCaseID, QString useCaseName){

    dlDeviceTemplate _dlDeviceTemplate;
    QList<objDevice> lstObjDevice = _dlDeviceTemplate.GetDeviceListForUseCase(UseCaseID);
    QString filename = useCaseName+".xml";

        QFile file(filename);
        file.open(QIODevice::WriteOnly);

        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("UseCase");
        //xmlWriter.writeAttribute("UseCase_Name",QString("Use Case Name"));

        for(int k=0;k<lstObjDevice.length();k++)
        {
             objDevice _objDevice  = lstObjDevice[k] ;

        //Device Details
        xmlWriter.writeStartElement("Device");
        xmlWriter.writeTextElement("Device_Name",_objDevice.deviceName);
        xmlWriter.writeTextElement("Protocol", _objDevice.protocol );
        xmlWriter.writeTextElement("IP_Address", _objDevice.sHostName);
        xmlWriter.writeTextElement("Num_Of_Devices", QString::number(_objDevice.IPCount));
        xmlWriter.writeTextElement("Is_AttackingEntity", QString::number(_objDevice.isAttackingEntity));
        xmlWriter.writeTextElement("Attack_Type", _objDevice.attackType );
        xmlWriter.writeTextElement("Source_IP", _objDevice.sourceIP );
        xmlWriter.writeTextElement("Target_IP", _objDevice.targetIP );
        xmlWriter.writeTextElement("Target_Port", QString::number(_objDevice.targetPort) );
        xmlWriter.writeTextElement("Messages_Per_Sec", QString::number(_objDevice.interval) );
        xmlWriter.writeTextElement("Message", _objDevice.message );

        if( _objDevice.protocol == "MQTT")
        {
            //MQTT Deatails
             xmlWriter.writeStartElement("MQTT");
             xmlWriter.writeTextElement("Brooker_IP",_objDevice.hostName );
             xmlWriter.writeTextElement("Is_Authentication_Require",QString::number( _objDevice.isAuthenticationRequire) );
             xmlWriter.writeTextElement("User_Name",_objDevice.userName );
             xmlWriter.writeTextElement("Password",_objDevice.password );
             xmlWriter.writeTextElement("Port",QString::number(_objDevice.port) );

             //Subscribe Details

             for(int i=0;i<_objDevice.lstSubTopic.count();i++)
             {
                 xmlWriter.writeStartElement("Subscribe_Detail");
                 xmlWriter.writeTextElement("Topic",_objDevice.lstSubTopic[i].topicName );
                 xmlWriter.writeEndElement();
             }

             //Publish Details

              for(int i=0;i<_objDevice.lstPubTopic.count();i++)
              {
                 xmlWriter.writeStartElement("Publish_Detail");
                 xmlWriter.writeTextElement("Topic",_objDevice.lstPubTopic[i].topic );
                 xmlWriter.writeTextElement("QoS",QString::number(_objDevice.lstPubTopic[i].QoS) );
                 xmlWriter.writeTextElement("Time_Profile_Type",_objDevice.lstPubTopic[i]._objTimeProfile.type );
                 xmlWriter.writeTextElement("Time_Profile_Interval", QString::number(_objDevice.lstPubTopic[i]._objTimeProfile.interval) );
                 xmlWriter.writeTextElement("Time_Profile_RandomFrom", QString::number(_objDevice.lstPubTopic[i]._objTimeProfile.randomFrom) );
                 xmlWriter.writeTextElement("Time_Profile_RandomTo", QString::number(_objDevice.lstPubTopic[i]._objTimeProfile.randomTo) );

                 xmlWriter.writeTextElement("Data_Profile_IsStartText",QString::number(_objDevice.lstPubTopic[i]._objDataProfile.isStartText) );
                 xmlWriter.writeTextElement("Data_Profile_StartText", _objDevice.lstPubTopic[i]._objDataProfile.startText );
                 xmlWriter.writeTextElement("Data_Profile_IsRandom",QString::number( _objDevice.lstPubTopic[i]._objDataProfile.isRandom) );
                 xmlWriter.writeTextElement("Data_Profile_RandomFrom",QString::number( _objDevice.lstPubTopic[i]._objDataProfile.randomFrom) );
                 xmlWriter.writeTextElement("Data_Profile_RandomTo",QString::number( _objDevice.lstPubTopic[i]._objDataProfile.randomTo) );
                 xmlWriter.writeTextElement("Data_Profile_IsEndText",QString::number(_objDevice.lstPubTopic[i]._objDataProfile.isEndText) );
                 xmlWriter.writeTextElement("Data_Profile_EndText", _objDevice.lstPubTopic[i]._objDataProfile.endText );
                 xmlWriter.writeEndElement(); //end Publish Details
              }

              xmlWriter.writeEndElement(); //end MQTT deatails
            }
        else
        {
            for(int j=0; j<_objDevice.lstDeviceCoapData.count();j++)
            {
                //CoAP Detaails
                xmlWriter.writeStartElement("COAP");
                xmlWriter.writeTextElement("Coap_URL",_objDevice.lstDeviceCoapData[j].url);
                xmlWriter.writeTextElement("Coap_Command",_objDevice.lstDeviceCoapData[j].coapCommand );
                xmlWriter.writeTextElement("Time_Profile_Type",_objDevice.lstDeviceCoapData[j]._objTimeProfile.type);
                xmlWriter.writeTextElement("Time_Profile_Interval",QString::number(_objDevice.lstDeviceCoapData[j]._objTimeProfile.interval));
                xmlWriter.writeTextElement("Time_Profile_RandomFrom",QString::number(_objDevice.lstDeviceCoapData[j]._objTimeProfile.randomFrom));
                xmlWriter.writeTextElement("Time_Profile_RandomTo",QString::number(_objDevice.lstDeviceCoapData[j]._objTimeProfile.randomTo));
                //Data Profile Details
                xmlWriter.writeTextElement("Data_Profile_IsStartText",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.isStartText));
                xmlWriter.writeTextElement("Data_Profile_StartText",_objDevice.lstDeviceCoapData[j]._objDataProfile.startText);
                xmlWriter.writeTextElement("Data_Profile_IsRandom",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.isRandom));
                xmlWriter.writeTextElement("Data_Profile_RandomFrom",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.randomFrom));
                xmlWriter.writeTextElement("Data_Profile_RandomTo",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.randomTo));
                xmlWriter.writeTextElement("Data_Profile_IsEndText",QString::number(_objDevice.lstDeviceCoapData[j]._objDataProfile.isEndText));
                xmlWriter.writeTextElement("Data_Profile_EndText",_objDevice.lstDeviceCoapData[j]._objDataProfile.endText);
                xmlWriter.writeEndElement(); //end Coap Details
            }


        }
         xmlWriter.writeEndElement(); //end Device Details
    }

        xmlWriter.writeEndElement(); //end UseCase Details

    file.close();

    return filename;

}

QList<objDevice> ThreadMain::ReadXMLFile(QString fileName)
{
     QDomDocument doc;
     QFile file(fileName);
     QList<objDevice> lstDevcies;
     if(file.open(QIODevice::ReadOnly))
     {
         if(doc.setContent(&file))
         {
             QDomElement elem = doc.documentElement();
             Traverse(elem,lstDevcies,"");
         }
        file.close();
     }

         return lstDevcies;
}

bool ThreadMain::Traverse(const QDomNode &node,QList<objDevice> &lstDevcies,QString LastTag)
{
    QDomNode domNode = node.firstChild();
    //qDebug()<<"FirstChild_TagName:"<<domNode.toElement().tagName();
    while(!domNode.isNull())
    {
        if(domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
           // qDebug()<<"domElement_TagName:"<<domElement.tagName();
            if(!domElement.isNull())
            {
                if(domElement.tagName() =="Device")
                {
                    //qDebug()<<"DeviceName:"<<domElement.attribute("Device_Name","");
                    qDebug()<<"-----Device Details----";
                   objDevice _objDevice;
                   lstDevcies.append(_objDevice);
                   LastTag = "Device";
                }else if(domElement.tagName() =="MQTT")
                {
                    qDebug()<<"\t"<<domElement.tagName()<<":"<<domElement.tagName();
                    LastTag="MQTT";
                }
                else if(domElement.tagName() =="Subscribe_Detail")
                {
                    objDeviceSubscribeData _objDeviceSubscribeData;
                   lstDevcies[lstDevcies.count()-1].lstSubTopic.append(_objDeviceSubscribeData);
                    qDebug()<<"\t"<<domElement.tagName()<<":"<<domElement.tagName();
                    LastTag = "Subscribe_Detail";
                }
                    else if(domElement.tagName() =="Publish_Detail")
                {
                     qDebug()<<"\t"<<domElement.tagName()<<":"<<domElement.tagName();
                     objDevicePublishData _objDevicePublishData;
                     lstDevcies[lstDevcies.count()-1].lstPubTopic.append(_objDevicePublishData);
                     LastTag="Publish_Detail";
                }

                else if(domElement.tagName() =="COAP")
                {
                    qDebug()<<"\t"<<domElement.tagName()<<":"<<domElement.tagName();
                    objDeviceCoapData _objDeviceCoapData;
                    lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.append(_objDeviceCoapData);
                     LastTag="COAP";
                }

                else if(domElement.tagName() ==""){
                    qDebug()<<"\t"<<domElement.tagName()<<":"<<domElement.tagName();
                    domNode = domNode.nextSibling();}
                else
                {
                    if(domElement.tagName() == "Device_Name" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].deviceName = domElement.text();
                    }
                    else if(domElement.tagName() == "Protocol" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].protocol = domElement.text();
                    }
                    else if(domElement.tagName() == "IP_Address" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].sHostName = domElement.text();
                    }
                    else if(domElement.tagName() == "Is_AttackingEntity" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].isAttackingEntity = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Attack_Type" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].attackType = domElement.text();
                    }
                    else if(domElement.tagName() == "Source_IP" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].sourceIP = domElement.text();
                    }
                    else if(domElement.tagName() == "Target_IP" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].targetIP = domElement.text();
                    }
                    else if(domElement.tagName() == "IP_Address" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].sHostName = domElement.text();
                    }
                    else if(domElement.tagName() == "Target_Port" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].targetPort = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Messages_Per_Sec" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].interval = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Message" && LastTag == "Device")
                    {
                        lstDevcies[lstDevcies.count()-1].message = domElement.text();
                    }
                    else if(domElement.tagName() == "Brooker_IP" && LastTag == "MQTT")
                    {
                        lstDevcies[lstDevcies.count()-1].hostName = domElement.text();
                    }
                    else if(domElement.tagName() == "Is_Authentication_Require" && LastTag == "MQTT")
                    {
                        lstDevcies[lstDevcies.count()-1].isAuthenticationRequire = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "User_Name" && LastTag == "MQTT")
                    {
                        lstDevcies[lstDevcies.count()-1].userName = domElement.text();
                    }
                    else if(domElement.tagName() == "Password" && LastTag == "MQTT")
                    {
                        lstDevcies[lstDevcies.count()-1].password = domElement.text();
                    }
                    else if(domElement.tagName() == "Port" && LastTag == "MQTT")
                    {
                        lstDevcies[lstDevcies.count()-1].port = domElement.text().toInt();
                    }

                    else if(domElement.tagName() == "Topic" && LastTag == "Subscribe_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstSubTopic[lstDevcies[lstDevcies.count()-1].lstSubTopic.count()-1].topicName = domElement.text();
                    }

                    else if(domElement.tagName() == "Topic" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1].topic = domElement.text();
                    }
                    else if(domElement.tagName() == "QoS" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1].QoS = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Time_Profile_Type" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.type = domElement.text();
                    }
                    else if(domElement.tagName() == "Time_Profile_Interval" && LastTag == "Publish_Detail" &&  lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.type =="Periodic")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.interval = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Time_Profile_RandomFrom" && LastTag == "Publish_Detail" &&  lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.type =="Random")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.randomFrom = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Time_Profile_RandomTo" && LastTag == "Publish_Detail" &&  lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.type =="Random")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objTimeProfile.randomTo = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Data_Profile_IsStartText" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.isStartText = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Data_Profile_StartText" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.startText = domElement.text();
                    }
                    else if(domElement.tagName() == "Data_Profile_IsRandom" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.isRandom = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Data_Profile_RandomFrom" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.randomFrom = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Data_Profile_RandomTo" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.randomTo = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Data_Profile_IsEndText" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.isEndText = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Data_Profile_EndText" && LastTag == "Publish_Detail")
                    {
                        lstDevcies[lstDevcies.count()-1].lstPubTopic[lstDevcies[lstDevcies.count()-1].lstPubTopic.count()-1]._objDataProfile.endText = domElement.text();
                    }
                    else if(domElement.tagName() == "Coap_URL" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1].url = domElement.text();
                    }
                    else if(domElement.tagName() == "Coap_Command" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1].coapCommand = domElement.text();
                    }
                    else if(domElement.tagName() == "Time_Profile_Type" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.type = domElement.text();
                    }
                    else if(domElement.tagName() == "Time_Profile_Interval" && LastTag == "COAP" && lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.type=="Periodic")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.interval = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Time_Profile_RandomFrom" && LastTag == "COAP" && lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.type=="Random")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.randomFrom = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Time_Profile_RandomTo" && LastTag == "COAP" && lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.type=="Random")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objTimeProfile.randomTo = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Data_Profile_IsStartText" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.isStartText = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Data_Profile_StartText" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.startText = domElement.text();
                    }
                    else if(domElement.tagName() == "Data_Profile_IsRandom" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.isRandom = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Data_Profile_RandomFrom" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.randomFrom = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Data_Profile_RandomTo" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.randomTo = domElement.text().toInt();
                    }
                    else if(domElement.tagName() == "Data_Profile_IsEndText" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.isEndText = domElement.text().toInt()==1?true:false;
                    }
                    else if(domElement.tagName() == "Data_Profile_EndText" && LastTag == "COAP")
                    {
                        lstDevcies[lstDevcies.count()-1].lstDeviceCoapData[lstDevcies[lstDevcies.count()-1].lstDeviceCoapData.count()-1]._objDataProfile.endText = domElement.text();
                    }

                    qDebug()<<"\t"<<domElement.tagName()<<":"<<domElement.text();
            }
                }
           // qDebug()<<"IF_NextSibling:"<<domNode.toElement().tagName();
        }
        Traverse(domNode,lstDevcies,LastTag);
        domNode = domNode.nextSibling();
        //qDebug()<<"NextSibling:"<<domNode.toElement().tagName();
    }

   // qDebug()<<"End & Return : "<<domNode.toElement().tagName();
    return true;
}
bool ThreadMain::LoadUseCaseNew(QString fileName){


    dlDeviceTemplate _dlDeviceTemplate;
    QList<objDevice> lstObjDevice = ReadXMLFile(fileName);
    foreach(objDevice __objDevice,lstObjDevice)
    {
        // QFuture<void> future = QtConcurrent::run([=]() {
       CreateDevice(__objDevice,false);
//});
    }
    return true;
}
bool ThreadMain::LoadUseCase(int UseCaseID){


    dlDeviceTemplate _dlDeviceTemplate;
   // QList<objDevice> lstObjDevice = _dlDeviceTemplate.GetDeviceListForUseCase(UseCaseID);
    QList<objDevice> lstObjDevice = ReadXMLFile("/home/iot/Desktop/mqt.xml");
    foreach(objDevice __objDevice,lstObjDevice)
    {
       CreateDevice(__objDevice,false);
       /* isSaveDB =false;
        int rc;
         pthread_t threads;
         objDevice *obj1 = new objDevice();
         obj1->IPCount = __objDevice.IPCount;
           obj1->attackType = __objDevice.attackType;
            obj1->deviceName = __objDevice.deviceName;
             obj1->hostName = __objDevice.hostName;
              obj1->interval = __objDevice.interval;
               obj1->isAttackingEntity = __objDevice.isAttackingEntity;
                obj1->isAuthenticationRequire = __objDevice.isAuthenticationRequire;
                 obj1->isPublisher = __objDevice.isPublisher;
                  obj1->lastActivity = __objDevice.lastActivity;
                   obj1->lstDeviceCoapData = __objDevice.lstDeviceCoapData;
                    obj1->lstDeviceHttpData = __objDevice.lstDeviceHttpData;
                     obj1->lstPubTopic = __objDevice.lstPubTopic;
                      obj1->lstSubTopic = __objDevice.lstSubTopic;
                       obj1->message = __objDevice.message;
                        obj1->password = __objDevice.password;
                         obj1->port = __objDevice.port;
                          obj1->portType = __objDevice.portType;
                           obj1->protocol = __objDevice.protocol;
                            obj1->sHostName = __objDevice.sHostName;
                             obj1->sourceIP = __objDevice.sourceIP;
                              obj1->targetIP = __objDevice.targetIP;
                               obj1->targetPort = __objDevice.targetPort;
                                obj1->templateID = __objDevice.templateID;
                                  obj1->useCaseID = __objDevice.useCaseID;
                                    obj1->useCaseName = __objDevice.useCaseName;
                                      obj1->userName = __objDevice.userName;
        rc = pthread_create(&threads, NULL,CreateDeviceThread,obj1);

        if (rc) {
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
          }
          */
    }
    return true;
}
bool ThreadMain::StartUsecase(int rowCount)
{
    return true;
}
bool ThreadMain::StopUsecase(int rowCount)
{
    return true;
}

QString ThreadMain::RefreshUseCase(){

    QString finalOutput = "";
   // mutex.lock();
    {
        QString output = "";
        for(int i=0;i<lstWorkers.count();i++)
        {
            output = output + lstWorkers[i]->_objDevice.deviceName+","+
                     lstWorkers[i]->_objDevice.protocol+","+
                     lstWorkers[i]->_objDevice.sHostName+","+
                     lstWorkers[i]->_objDevice.attackType+","+
                     lstWorkers[i]->_objDevice.lastActivity;

            if((i+1)!= lstWorkers.count())
                output += ";";
        }

        finalOutput = output;
    }
    //mutex.unlock();
return finalOutput;
}

bool ThreadMain::ClearUseCase(){


    for(int i=0;i<lstWorkers.count();i++)
    {
        if(lstWorkers[i]->_objDevice.protocol == "MQTT")
        {
            lstWorkers[i]->m_client->disconnectFromHost();
            delete lstWorkers[i]->m_client;
        }
    if (lstWorkers[i]->isTimerActive)
    {
           lstWorkers[i]->timer->stop();
            delete lstWorkers[i]->timer;
    }
    if (lstWorkers[i]->isAttackTimerActive)
    {
           lstWorkers[i]->attackTimer->stop();
           delete lstWorkers[i]->attackTimer;
    }
    }

    lstWorkers.clear();
    return true;

}
bool ThreadMain::DeleteUseCase(int useCaseID)
{


    dlDeviceTemplate _dlDeviceTemplate;
    QList<objDevice> lstObjDevice = _dlDeviceTemplate.GetDeviceListForUseCase(useCaseID);
    for(int i=0;i<lstObjDevice.count();i++)
    {
        int deviceTemplateID= lstObjDevice[i].templateID;
        dlDeviceSubscribeData _dlDeviceSubscribeData;
        _dlDeviceSubscribeData.DelSubscribeDataForUseCase(deviceTemplateID);
        dlDevicePublishData _dlDevicePublishData;
        _dlDevicePublishData.DelPublishDataForUseCase(deviceTemplateID);
        dlDeviceCoapData _dlDeviceCoapData;
        _dlDeviceCoapData.DelCoapDataForUseCase(deviceTemplateID);
        dlDeviceHttpData _dlDeviceHttpData;
        _dlDeviceHttpData.DelHttpDataForUseCase(deviceTemplateID);
        _dlDeviceTemplate.DelDeviceTemplateDataForUseCase(deviceTemplateID);
    }
    dlUseCase _dlUseCase;
    _dlUseCase.DelUseCase(useCaseID);
}


bool ThreadMain::DeleteDevice(QString IP){

    objDevice _objDevice;
    int i=0;
    bool isDelete = false;
    qDebug()<<"I m in Thread main: "<<_objDevice.sHostName;


    for(;i<lstWorkers.count();i++)
    {
        if(lstWorkers[i]->_objDevice.sHostName == IP)
             _objDevice = lstWorkers[i]->_objDevice;

            dlDeviceSubscribeData _dlDeviceSubscribeData;
            _dlDeviceSubscribeData.DelSubscribeDataForUseCase(_objDevice.templateID);
            dlDevicePublishData _dlDevicePublishData;
            _dlDevicePublishData.DelPublishDataForUseCase(_objDevice.templateID);
            dlDeviceCoapData _dlDeviceCoapData;
            _dlDeviceCoapData.DelCoapDataForUseCase(_objDevice.templateID);
            dlDeviceHttpData _dlDeviceHttpData;
            _dlDeviceHttpData.DelHttpDataForUseCase(_objDevice.templateID);
            dlDeviceTemplate _dlDeviceTemplate;
            _dlDeviceTemplate.DelDeviceTemplateDataForUseCase(_objDevice.templateID);
            if(lstWorkers[i]->_objDevice.protocol == "MQTT")
            {
                lstWorkers[i]->m_client->disconnectFromHost();
                delete lstWorkers[i]->m_client;
            }
           //
            if (lstWorkers[i]->isTimerActive)
            {
                   lstWorkers[i]->timer->stop();
                    delete lstWorkers[i]->timer;
            }
            if (lstWorkers[i]->isAttackTimerActive)
            {
                   lstWorkers[i]->attackTimer->stop();
                   delete lstWorkers[i]->attackTimer;
            }
            lstWorkers.removeAt(i);
            isDelete = true;
            break;
    }

    //if(isDelete)
       //lstWorkers.removeAt(i);



    qDebug() << IP;
}
bool ThreadMain::DeleteDeviceNew(int templateID){
    qDebug()<<"templateID: "<<templateID;

            dlDeviceSubscribeData _dlDeviceSubscribeData;
            _dlDeviceSubscribeData.DelSubscribeDataForUseCase(templateID);
            dlDevicePublishData _dlDevicePublishData;
            _dlDevicePublishData.DelPublishDataForUseCase(templateID);
            dlDeviceCoapData _dlDeviceCoapData;
            _dlDeviceCoapData.DelCoapDataForUseCase(templateID);
            dlDeviceHttpData _dlDeviceHttpData;
            _dlDeviceHttpData.DelHttpDataForUseCase(templateID);
            dlDeviceTemplate _dlDeviceTemplate;
            _dlDeviceTemplate.DelDeviceTemplateDataForUseCase(templateID);


            return  true;
}
QString ThreadMain::ViewDeviceData(QString IP){

    FileHandler _FileHandler;
   return  _FileHandler.readFile(IP);


}



