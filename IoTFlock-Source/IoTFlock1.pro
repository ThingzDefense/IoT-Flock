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
QT       += core gui sql network xml

# uncomment for console
QT -= gui
CONFIG += c++11 console
CONFIG -= app_bundle
TARGET = IoTFlock-Console

#uncomment for gui
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
    constants.cpp \
    dal.cpp \
    dataprofile.cpp \
    device.cpp \
    dldataprofile.cpp \
    dldevicecoapdata.cpp \
    dldevicehttpdata.cpp \
    dldevicepublishdata.cpp \
    dldevicesubscribedata.cpp \
    dldevicetemplate.cpp \
    dlfrmnewdevicetemplateview.cpp \
    dltimeprofile.cpp \
    dltopic.cpp \
    dlusecase.cpp \
    filehandler.cpp \
    floodattack.cpp \
    frmdashboard2.cpp \
    frmkeyvalue.cpp \
    frmloadusecase.cpp \
    frmnewdevice.cpp \
    frmnewdevicetemplate.cpp \
    frmnewdevicetemplateview.cpp \
    frmsaveusecase.cpp \
    frmusecasedevices.cpp \
    frmviewlog.cpp \
    main.cpp \
    objdataprofile.cpp \
    objdevice.cpp \
    objdevicecoapdata.cpp \
    objdevicehttpdata.cpp \
    objdevicepublishdata.cpp \
    objdevicesubscribedata.cpp \
    objdevicetemplate.cpp \
    objfrmnewdevicetemplateview.cpp \
    objglobal.cpp \
    objtimeprofile.cpp \
    objtopic.cpp \
    objusecase.cpp \
    synattack.cpp \
    threadmain.cpp \
    timeprofile.cpp \
    topics.cpp \
    udpflood.cpp \
    viewdataprofile.cpp \
    viewtimeprofile.cpp \
    viewtopics.cpp \
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
    constants.h \
    dal.h \
    dataprofile.h \
    device.h \
    dldataprofile.h \
    dldevicecoapdata.h \
    dldevicehttpdata.h \
    dldevicepublishdata.h \
    dldevicesubscribedata.h \
    dldevicetemplate.h \
    dlfrmnewdevicetemplateview.h \
    dltimeprofile.h \
    dltopic.h \
    dlusecase.h \
    filehandler.h \
    floodattack.h \
    frmdashboard2.h \
    frmkeyvalue.h \
    frmloadusecase.h \
    frmnewdevice.h \
    frmnewdevicetemplate.h \
    frmnewdevicetemplateview.h \
    frmsaveusecase.h \
    frmusecasedevices.h \
    frmviewlog.h \
    objdataprofile.h \
    objdevice.h \
    objdevicecoapdata.h \
    objdevicehttpdata.h \
    objdevicepublishdata.h \
    objdevicesubscribedata.h \
    objdevicetemplate.h \
    objfrmnewdevicetemplateview.h \
    objglobal.h \
    objtimeprofile.h \
    objtopic.h \
    objusecase.h \
    synattack.h \
    threadmain.h \
    timeprofile.h \
    topics.h \
    udpflood.h \
    ui_dataprofile.h \
    ui_floodattack.h \
    ui_frmdashboard2.h \
    ui_frmkeyvalue.h \
    ui_frmloadusecase.h \
    ui_frmnewdevice.h \
    ui_frmnewdevicetemplate.h \
    ui_frmnewdevicetemplateview.h \
    ui_frmsaveusecase.h \
    ui_frmusecasedevices.h \
    ui_frmviewlog.h \
    ui_mainwindow.h \
    ui_synattack.h \
    ui_timeprofile.h \
    ui_topics.h \
    ui_udpflood.h \
    ui_viewdataprofile.h \
    ui_viewtimeprofile.h \
    ui_viewtopics.h \
    viewdataprofile.h \
    viewtimeprofile.h \
    viewtopics.h \
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
    dataprofile.ui \
    floodattack.ui \
    frmdashboard2.ui \
    frmkeyvalue.ui \
    frmloadusecase.ui \
    frmnewdevice.ui \
    frmnewdevicetemplate.ui \
    frmnewdevicetemplateview.ui \
    frmsaveusecase.ui \
    frmusecasedevices.ui \
    frmviewlog.ui \
    mainwindow.ui \
    synattack.ui \
    timeprofile.ui \
    topics.ui \
    udpflood.ui \
    viewdataprofile.ui \
    viewtimeprofile.ui \
    viewtopics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    IoTFlock.pro \
    mqtt/mqtt.pro

DISTFILES += \
    db2.db \
    IoTFlock.pro.user \
    IoTFlock.pro.user.9e0c872 \
    IoTFlock.pro.user.CIbKEI \
    IoTFlock.pro.user.MUJVlC \
    IoTFlock.pro.user.UgAgHk \
    delete-icon.png \
    edit-icon.png \
    load-icon.png \
    view-icon.png \
    Makefile \
    coap/coap.pri

unix:!macx: LIBS += -L$$PWD/./ -ltins

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
