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
//#include "mainwindow.h"
#include "viewtimeprofile.h"
#include "topics.h"
#include "dataprofile.h"
#include "timeprofile.h"
#include <QApplication>
#include "viewtopics.h"
#include "viewdataprofile.h"
#include "viewtimeprofile.h"
#include "qdir.h"
#include<frmnewdevice.h>
#include<frmkeyvalue.h>
#include<qstring.h>
#include<threadmain.h>
#include<frmdashboard2.h>
#include<frmnewdevicetemplateview.h>
#include<qvariant.h>
#include <tins/ip.h>
#include <tins/tcp.h>
#include <tins/udp.h>
#include <tins/ip_address.h>
#include <tins/ethernetII.h>
#include <tins/network_interface.h>
#include <tins/sniffer.h>
#include <tins/utils.h>
#include <tins/dhcp.h>
#include <tins/packet_sender.h>
#include <tins/icmp.h>
#include <tins/icmpv6.h>
#include <tins/rawpdu.h>

static QString PATH_EDITICON;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir dir(".");
    PATH_EDITICON= dir.absolutePath()+"/edit-icon.png";
    qDebug()<<"argv[0]: "<<argv[1];
    bool showConsole = false;

    ThreadMain th;
    QString filePath = argv[1];

    th.LoadUseCaseNew(filePath);

    //For Console
    //filePath = "/home/iot/Desktop/1.xml";
   // th.LoadUseCaseNew(filePath);

    //For GUI
    frmDashboard2 w;
    w.show();



   // QString filePath = "/home/iot/sessionhijacking1.xml";
    //  QString filePath = "/home/iot/Desktop/Dataset/Test000.xml";
   //th.LoadUseCaseNew(filePath);
    //*/
    // frmNewDeviceTemplateView w;
   // MainWindow w;
    //frmDashboard2 w;
    //  ViewTimeProfile w;
    //w.show();
    return a.exec();
}



//QString PATH_DELETEICON = dir.absolutePath()+"/delete-icon.png";
//QString PATH_VIEWICON = dir.absolutePath()+"/view-icon.png";
