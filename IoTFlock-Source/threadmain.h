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
#ifndef THREADMAIN_H
#define THREADMAIN_H
#include <qthread.h>
#include <device.h>
#include<QMainWindow>
#include<objdevice.h>
#include<QtXml>
//#include<workerpool.h>


class ThreadMain:QMainWindow
{
public:
    ThreadMain();
    ~ThreadMain();
    int threadLimit;
    int devicesCount;
    int threadCounter = 0;
    QString GetDevicesInfo();
    void CreateDevices(objDevice __objDevice);
    void CreateDevicesNew(objDevice __objDevice);
    bool CreateDevice(objDevice _objDevice,bool isSave);
    bool RemoveDevice(QString _IP);
    bool isIPinUse(QString _IP);
    void ipstr2dec(QString ip);
    void getNextIP(char ip_addr[]);
    unsigned long from, to;
    QString lastError = "";
    //QList<Device*> lstWorkers;
    int j=0;

    bool SaveUseCase(QString ucName);
    bool LoadUseCase(int UseCaseID);
    bool LoadUseCaseNew(QString fileName);
    bool StartUsecase(int rowCount);
    bool StopUsecase(int rowCount);
    QString RefreshUseCase();
    bool ClearUseCase();
    bool DeleteDevice(QString IP);
    bool DeleteDeviceNew(int templateID);
    bool DeleteUseCase(int useCaseID);
    QString ViewDeviceData(QString IP);
    bool SaveUseCaseDevice(objDevice _objDevice);
    bool SaveUseCaseXML(int UseCaseID, bool isRun);
    QString GenerateUseCaseXML(int UseCaseID, QString useCaseName);
    QList<objDevice> ReadXMLFile(QString fileName);
    //bool Traverse(const QDomNode &node);
    bool Traverse(const QDomNode &node,QList<objDevice> &lstDevcies,QString LastTag);

private:
   QMutex mutex;


    /**
     * @brief Thread object which will let us manipulate the running thread
     */
    QThread *thread[100];

    /**
     * @brief Object which contains methods that should be runned in another thread
     */
    Device *worker[100];
};

#endif // THREADMAIN_H
