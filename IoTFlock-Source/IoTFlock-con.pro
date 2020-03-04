#/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# *                                                                         *
# *  Copyright (C) 2019 IRIL Lab, KICS, UET Lahore <iril@kics.edu.pk>       *
# *                                                                         *
# *  This file is part of IRIL Advanced Data Generator.                     *                                         *
# *                                                                         *
# *  IRIL Advanced Data Generator is free software: you can redistribute    *
# *  it and/or modify it under the terms of the GNU General Public License  *
# *  as published by the Free Software Foundation, version 3 of the License.*
# *                                                                         *
# *                                                                         *
# *  IRIL Advanced Data Generator is distributed in the hope that it will   *
# *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty *
# *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the        *
# *  GNU General Public License for more details.                           *
# *                                                                         *
# *  You should have received a copy of the GNU General Public License      *
# *  along with IRIL Advanced Data Generator.                               *
# *  If not, see <http://www.gnu.org/licenses/>.                            *
# *                                                                         *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T10:33:12
#
#-------------------------------------------------
QT       += core gui sql network xml opengl

# comment for gui
QT -= gui
CONFIG += c++11 console
CONFIG -= app_bundle
TARGET = IoTFlock-Console
TEMPLATE = app
#
#comment for console
#CONFIG += c++11
#TARGET = IoTFlock-GUI
#TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        main.cpp \
    topics.cpp \
    viewtopics.cpp \
    viewtimeprofile.cpp \
    viewdataprofile.cpp \
    udpflood.cpp \
    timeprofile.cpp \
    threadmain.cpp \
    synattack.cpp \
    objusecase.cpp \
    objtopic.cpp \
    objtimeprofile.cpp \
    objglobal.cpp \
    objfrmnewdevicetemplateview.cpp \
    objdevicetemplate.cpp \
    objdevicesubscribedata.cpp \
    objdevicepublishdata.cpp \
    objdevicehttpdata.cpp \
    objdevicecoapdata.cpp \
    objdevice.cpp \
    objdataprofile.cpp \
    frmviewlog.cpp \
    frmusecasedevices.cpp \
    frmsaveusecase.cpp \
    frmnewdevicetemplateview.cpp \
    frmnewdevicetemplate.cpp \
    frmnewdevice.cpp \
    frmloadusecase.cpp \
    frmkeyvalue.cpp \
    frmdashboard2.cpp \
    floodattack.cpp \
    filehandler.cpp \
    dlusecase.cpp \
    dltopic.cpp \
    dltimeprofile.cpp \
    dlfrmnewdevicetemplateview.cpp \
    dldevicetemplate.cpp \
    dldevicesubscribedata.cpp \
    dldevicepublishdata.cpp \
    dldevicehttpdata.cpp \
    dldevicecoapdata.cpp \
    dldataprofile.cpp \
    device.cpp \
    dataprofile.cpp \
    dal.cpp \
    constants.cpp \
    coap/coapnetworkaccessmanager.cpp \
    coap/coapobserveresource.cpp \
    coap/coapoption.cpp \
    coap/coappdu.cpp \
    coap/coappdublock.cpp \
    coap/coapreply.cpp \
    coap/coaprequest.cpp \
    coap/coaptarget.cpp \
    coap/corelink.cpp \
    coap/corelinkparser.cpp \
    mqtt/qmqttclient.cpp \
    mqtt/qmqttconnection.cpp \
    mqtt/qmqttcontrolpacket.cpp \
    mqtt/qmqttmessage.cpp \
    mqtt/qmqttsubscription.cpp \
    mqtt/qmqtttopicfilter.cpp \
    mqtt/qmqtttopicname.cpp

HEADERS += \
    topics.h \
    viewtopics.h \
    viewtimeprofile.h \
    viewdataprofile.h \
    udpflood.h \
    timeprofile.h \
    threadmain.h \
    synattack.h \
    objusecase.h \
    objtopic.h \
    objtimeprofile.h \
    objglobal.h \
    objfrmnewdevicetemplateview.h \
    objdevicetemplate.h \
    objdevicesubscribedata.h \
    objdevicepublishdata.h \
    objdevicehttpdata.h \
    objdevicecoapdata.h \
    objdevice.h \
    objdataprofile.h \
    frmviewlog.h \
    frmusecasedevices.h \
    frmsaveusecase.h \
    frmnewdevicetemplateview.h \
    frmnewdevicetemplate.h \
    frmnewdevice.h \
    frmloadusecase.h \
    frmkeyvalue.h \
    frmdashboard2.h \
    floodattack.h \
    filehandler.h \
    dlusecase.h \
    dltopic.h \
    dltimeprofile.h \
    dlfrmnewdevicetemplateview.h \
    dldevicetemplate.h \
    dldevicesubscribedata.h \
    dldevicepublishdata.h \
    dldevicehttpdata.h \
    dldevicecoapdata.h \
    dldataprofile.h \
    device.h \
    dataprofile.h \
    dal.h \
    constants.h \
    coap/coapnetworkaccessmanager.h \
    coap/coapobserveresource.h \
    coap/coapoption.h \
    coap/coappdu.h \
    coap/coappdublock.h \
    coap/coapreply.h \
    coap/coaprequest.h \
    coap/coaptarget.h \
    coap/corelink.h \
    coap/corelinkparser.h \
    mqtt/qguard_p.h \
    mqtt/qmqttclient.h \
    mqtt/qmqttclient_p.h \
    mqtt/qmqttconnection_p.h \
    mqtt/qmqttcontrolpacket_p.h \
    mqtt/qmqttglobal.h \
    mqtt/qmqttmessage.h \
    mqtt/qmqttsubscription.h \
    mqtt/qmqttsubscription_p.h \
    mqtt/qmqtttopicfilter.h \
    mqtt/qmqtttopicname.h \
    mqtt/qobject_p.h

FORMS += \
        mainwindow.ui \
    topics.ui \
    viewtopics.ui \
    viewtimeprofile.ui \
    viewdataprofile.ui \
    udpflood.ui \
    timeprofile.ui \
    synattack.ui \
    frmviewlog.ui \
    frmusecasedevices.ui \
    frmsaveusecase.ui \
    frmnewdevicetemplateview.ui \
    frmnewdevicetemplate.ui \
    frmnewdevice.ui \
    frmloadusecase.ui \
    frmkeyvalue.ui \
    frmdashboard2.ui \
    floodattack.ui \
    dataprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    libtins.so \
    db2.db \
    view-icon.png \
    load-icon.png \
    edit-icon.png \
    delete-icon.png \
    coap/coap.pri

SUBDIRS += \
    mqtt/mqtt.pro

unix:!macx: LIBS += -L$$PWD/./ -ltins

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: LIBS += -L$$PWD/./ -ltins

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
