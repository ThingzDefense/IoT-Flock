/********************************************************************************
** Form generated from reading UI file 'frmnewdevicetemplate.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMNEWDEVICETEMPLATE_H
#define UI_FRMNEWDEVICETEMPLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmNewDeviceTemplate
{
public:
    QTabWidget *tbMain;
    QWidget *tab;
    QGroupBox *gbIsAttackingEntity;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *cmbAttackType;
    QLabel *label_30;
    QLineEdit *txtAttackingSourceIP;
    QLabel *label_14;
    QLineEdit *txtAttackingTargetIP;
    QLabel *label_28;
    QSpinBox *sbAttackingTargetPort;
    QLabel *label_29;
    QSpinBox *sbAttackingInterval;
    QLabel *label_31;
    QPlainTextEdit *txtAttackingMsg;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QLabel *lblDeviceName2;
    QLineEdit *txtDeviceName2;
    QLabel *label_13;
    QComboBox *cmbProtocol;
    QLabel *label;
    QLineEdit *txtIPAddress;
    QLabel *label_12;
    QSpinBox *sbNumofDevices;
    QWidget *tpMQTT;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QRadioButton *rbMQTTRegular;
    QSpinBox *sbBrokerPortRegular;
    QRadioButton *rbMQTTTLS;
    QSpinBox *sbBrokerportTLS;
    QGroupBox *gbBrookerAuthentication;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QLineEdit *txtBrokerUserName;
    QLabel *label_11;
    QLineEdit *txtBrokerPassword;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_5;
    QLabel *label_3;
    QLineEdit *txtBrokerIP;
    QTabWidget *tbMQTTSubscribePublish;
    QWidget *tab_4;
    QPushButton *btnAddSubscribeTopic;
    QComboBox *cmbSubscribeTopic;
    QLabel *label_15;
    QTableWidget *tbWidgetSubscribeTopic;
    QPushButton *btnAdMQTTSubscribeTopic;
    QWidget *tab_5;
    QComboBox *cmbMQTTPublishTopic;
    QLabel *label_16;
    QComboBox *cmbMQTTPublishDataProfile;
    QLabel *label_17;
    QComboBox *cmbMQTTPublishTimeProfile;
    QLabel *label_18;
    QPushButton *btnMQTTPublishDataProfile;
    QLabel *label_19;
    QComboBox *cmbMQTTQoS;
    QTableWidget *tbWidgetMQTTPublish;
    QPushButton *btnMQTTPublishTimeProfile;
    QPushButton *btnAdMQTTPublishTopic;
    QPushButton *btnMQTTPublish;
    QWidget *tpCOAP;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QComboBox *cmbCoapCommand;
    QComboBox *cmbCoapTimeProfile;
    QPushButton *btnAddCoapTimeProfile;
    QPushButton *btnAddCoapDataProfile;
    QPushButton *btnCoapAdd;
    QTableWidget *tbWidgetCoap;
    QLabel *label_20;
    QLineEdit *txtCoapUrl;
    QLineEdit *txtCoapParameters;
    QComboBox *cmbCoapDataProfile;
    QWidget *tpHTTP;
    QComboBox *cmbHttpCommand;
    QLabel *label_25;
    QLineEdit *txtHttpUrl;
    QLabel *label_26;
    QComboBox *cmbHttpTimeProfile;
    QLabel *label_27;
    QPushButton *btnHttpAdd;
    QTableWidget *tbWidgetHttp;
    QPushButton *btnAddHttpDataProfile;
    QPushButton *btnAddHttpTimeProfile;
    QLabel *label_24;
    QLineEdit *txtHttpParameters;
    QComboBox *cmbHttpDataProfile;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCreate;
    QPushButton *btnClose;
    QComboBox *cmbTemplates;
    QLabel *lblDeviceName;
    QLineEdit *txtDeviceName;

    void setupUi(QDialog *frmNewDeviceTemplate)
    {
        if (frmNewDeviceTemplate->objectName().isEmpty())
            frmNewDeviceTemplate->setObjectName(QString::fromUtf8("frmNewDeviceTemplate"));
        frmNewDeviceTemplate->resize(572, 613);
        tbMain = new QTabWidget(frmNewDeviceTemplate);
        tbMain->setObjectName(QString::fromUtf8("tbMain"));
        tbMain->setGeometry(QRect(10, 50, 560, 531));
        tbMain->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gbIsAttackingEntity = new QGroupBox(tab);
        gbIsAttackingEntity->setObjectName(QString::fromUtf8("gbIsAttackingEntity"));
        gbIsAttackingEntity->setEnabled(true);
        gbIsAttackingEntity->setGeometry(QRect(10, 140, 541, 351));
        gbIsAttackingEntity->setCheckable(true);
        gbIsAttackingEntity->setChecked(false);
        formLayout = new QFormLayout(gbIsAttackingEntity);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(gbIsAttackingEntity);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        cmbAttackType = new QComboBox(gbIsAttackingEntity);
        cmbAttackType->addItem(QString());
        cmbAttackType->addItem(QString());
        cmbAttackType->addItem(QString());
        cmbAttackType->addItem(QString());
        cmbAttackType->addItem(QString());
        cmbAttackType->addItem(QString());
        cmbAttackType->addItem(QString());
        cmbAttackType->setObjectName(QString::fromUtf8("cmbAttackType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cmbAttackType);

        label_30 = new QLabel(gbIsAttackingEntity);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_30);

        txtAttackingSourceIP = new QLineEdit(gbIsAttackingEntity);
        txtAttackingSourceIP->setObjectName(QString::fromUtf8("txtAttackingSourceIP"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtAttackingSourceIP);

        label_14 = new QLabel(gbIsAttackingEntity);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_14);

        txtAttackingTargetIP = new QLineEdit(gbIsAttackingEntity);
        txtAttackingTargetIP->setObjectName(QString::fromUtf8("txtAttackingTargetIP"));

        formLayout->setWidget(2, QFormLayout::FieldRole, txtAttackingTargetIP);

        label_28 = new QLabel(gbIsAttackingEntity);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_28);

        sbAttackingTargetPort = new QSpinBox(gbIsAttackingEntity);
        sbAttackingTargetPort->setObjectName(QString::fromUtf8("sbAttackingTargetPort"));
        sbAttackingTargetPort->setMaximum(65535);

        formLayout->setWidget(3, QFormLayout::FieldRole, sbAttackingTargetPort);

        label_29 = new QLabel(gbIsAttackingEntity);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_29);

        sbAttackingInterval = new QSpinBox(gbIsAttackingEntity);
        sbAttackingInterval->setObjectName(QString::fromUtf8("sbAttackingInterval"));
        sbAttackingInterval->setMinimum(1);
        sbAttackingInterval->setMaximum(1000);

        formLayout->setWidget(4, QFormLayout::FieldRole, sbAttackingInterval);

        label_31 = new QLabel(gbIsAttackingEntity);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_31);

        txtAttackingMsg = new QPlainTextEdit(gbIsAttackingEntity);
        txtAttackingMsg->setObjectName(QString::fromUtf8("txtAttackingMsg"));

        formLayout->setWidget(5, QFormLayout::FieldRole, txtAttackingMsg);

        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(7, 10, 541, 121));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        lblDeviceName2 = new QLabel(layoutWidget);
        lblDeviceName2->setObjectName(QString::fromUtf8("lblDeviceName2"));
        lblDeviceName2->setStyleSheet(QString::fromUtf8(""));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, lblDeviceName2);

        txtDeviceName2 = new QLineEdit(layoutWidget);
        txtDeviceName2->setObjectName(QString::fromUtf8("txtDeviceName2"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, txtDeviceName2);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_13);

        cmbProtocol = new QComboBox(layoutWidget);
        cmbProtocol->addItem(QString());
        cmbProtocol->addItem(QString());
        cmbProtocol->addItem(QString());
        cmbProtocol->setObjectName(QString::fromUtf8("cmbProtocol"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, cmbProtocol);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label);

        txtIPAddress = new QLineEdit(layoutWidget);
        txtIPAddress->setObjectName(QString::fromUtf8("txtIPAddress"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, txtIPAddress);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_12);

        sbNumofDevices = new QSpinBox(layoutWidget);
        sbNumofDevices->setObjectName(QString::fromUtf8("sbNumofDevices"));
        sbNumofDevices->setMinimum(1);
        sbNumofDevices->setMaximum(1000);
        sbNumofDevices->setValue(1);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, sbNumofDevices);

        tbMain->addTab(tab, QString());
        tpMQTT = new QWidget();
        tpMQTT->setObjectName(QString::fromUtf8("tpMQTT"));
        groupBox_3 = new QGroupBox(tpMQTT);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(9, 44, 231, 111));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(13, 33, 211, 60));
        formLayout_2 = new QFormLayout(layoutWidget1);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        rbMQTTRegular = new QRadioButton(layoutWidget1);
        rbMQTTRegular->setObjectName(QString::fromUtf8("rbMQTTRegular"));
        rbMQTTRegular->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, rbMQTTRegular);

        sbBrokerPortRegular = new QSpinBox(layoutWidget1);
        sbBrokerPortRegular->setObjectName(QString::fromUtf8("sbBrokerPortRegular"));
        sbBrokerPortRegular->setMaximum(65535);
        sbBrokerPortRegular->setValue(1883);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sbBrokerPortRegular);

        rbMQTTTLS = new QRadioButton(layoutWidget1);
        rbMQTTTLS->setObjectName(QString::fromUtf8("rbMQTTTLS"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, rbMQTTTLS);

        sbBrokerportTLS = new QSpinBox(layoutWidget1);
        sbBrokerportTLS->setObjectName(QString::fromUtf8("sbBrokerportTLS"));
        sbBrokerportTLS->setMaximum(65535);
        sbBrokerportTLS->setValue(8883);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, sbBrokerportTLS);

        gbBrookerAuthentication = new QGroupBox(tpMQTT);
        gbBrookerAuthentication->setObjectName(QString::fromUtf8("gbBrookerAuthentication"));
        gbBrookerAuthentication->setGeometry(QRect(250, 50, 301, 102));
        gbBrookerAuthentication->setCheckable(true);
        gbBrookerAuthentication->setChecked(false);
        verticalLayout_6 = new QVBoxLayout(gbBrookerAuthentication);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_10 = new QLabel(gbBrookerAuthentication);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        txtBrokerUserName = new QLineEdit(gbBrookerAuthentication);
        txtBrokerUserName->setObjectName(QString::fromUtf8("txtBrokerUserName"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, txtBrokerUserName);

        label_11 = new QLabel(gbBrookerAuthentication);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);

        txtBrokerPassword = new QLineEdit(gbBrookerAuthentication);
        txtBrokerPassword->setObjectName(QString::fromUtf8("txtBrokerPassword"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, txtBrokerPassword);


        verticalLayout_6->addLayout(formLayout_3);

        layoutWidget2 = new QWidget(tpMQTT);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 541, 27));
        formLayout_5 = new QFormLayout(layoutWidget2);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_3);

        txtBrokerIP = new QLineEdit(layoutWidget2);
        txtBrokerIP->setObjectName(QString::fromUtf8("txtBrokerIP"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, txtBrokerIP);

        tbMQTTSubscribePublish = new QTabWidget(tpMQTT);
        tbMQTTSubscribePublish->setObjectName(QString::fromUtf8("tbMQTTSubscribePublish"));
        tbMQTTSubscribePublish->setGeometry(QRect(10, 150, 541, 351));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        btnAddSubscribeTopic = new QPushButton(tab_4);
        btnAddSubscribeTopic->setObjectName(QString::fromUtf8("btnAddSubscribeTopic"));
        btnAddSubscribeTopic->setGeometry(QRect(70, 33, 89, 25));
        cmbSubscribeTopic = new QComboBox(tab_4);
        cmbSubscribeTopic->setObjectName(QString::fromUtf8("cmbSubscribeTopic"));
        cmbSubscribeTopic->setGeometry(QRect(70, 5, 401, 25));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 6, 51, 17));
        tbWidgetSubscribeTopic = new QTableWidget(tab_4);
        tbWidgetSubscribeTopic->setObjectName(QString::fromUtf8("tbWidgetSubscribeTopic"));
        tbWidgetSubscribeTopic->setGeometry(QRect(20, 60, 512, 260));
        btnAdMQTTSubscribeTopic = new QPushButton(tab_4);
        btnAdMQTTSubscribeTopic->setObjectName(QString::fromUtf8("btnAdMQTTSubscribeTopic"));
        btnAdMQTTSubscribeTopic->setGeometry(QRect(471, 5, 23, 25));
        tbMQTTSubscribePublish->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        cmbMQTTPublishTopic = new QComboBox(tab_5);
        cmbMQTTPublishTopic->setObjectName(QString::fromUtf8("cmbMQTTPublishTopic"));
        cmbMQTTPublishTopic->setGeometry(QRect(100, 5, 281, 25));
        label_16 = new QLabel(tab_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 5, 51, 17));
        cmbMQTTPublishDataProfile = new QComboBox(tab_5);
        cmbMQTTPublishDataProfile->setObjectName(QString::fromUtf8("cmbMQTTPublishDataProfile"));
        cmbMQTTPublishDataProfile->setGeometry(QRect(100, 35, 381, 25));
        label_17 = new QLabel(tab_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(10, 35, 81, 17));
        cmbMQTTPublishTimeProfile = new QComboBox(tab_5);
        cmbMQTTPublishTimeProfile->setObjectName(QString::fromUtf8("cmbMQTTPublishTimeProfile"));
        cmbMQTTPublishTimeProfile->setGeometry(QRect(100, 65, 381, 25));
        label_18 = new QLabel(tab_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(10, 65, 111, 17));
        btnMQTTPublishDataProfile = new QPushButton(tab_5);
        btnMQTTPublishDataProfile->setObjectName(QString::fromUtf8("btnMQTTPublishDataProfile"));
        btnMQTTPublishDataProfile->setGeometry(QRect(480, 35, 23, 25));
        label_19 = new QLabel(tab_5);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(410, 5, 41, 25));
        cmbMQTTQoS = new QComboBox(tab_5);
        cmbMQTTQoS->addItem(QString());
        cmbMQTTQoS->addItem(QString());
        cmbMQTTQoS->addItem(QString());
        cmbMQTTQoS->setObjectName(QString::fromUtf8("cmbMQTTQoS"));
        cmbMQTTQoS->setGeometry(QRect(450, 5, 51, 25));
        tbWidgetMQTTPublish = new QTableWidget(tab_5);
        tbWidgetMQTTPublish->setObjectName(QString::fromUtf8("tbWidgetMQTTPublish"));
        tbWidgetMQTTPublish->setGeometry(QRect(10, 122, 521, 201));
        btnMQTTPublishTimeProfile = new QPushButton(tab_5);
        btnMQTTPublishTimeProfile->setObjectName(QString::fromUtf8("btnMQTTPublishTimeProfile"));
        btnMQTTPublishTimeProfile->setGeometry(QRect(480, 65, 23, 25));
        btnAdMQTTPublishTopic = new QPushButton(tab_5);
        btnAdMQTTPublishTopic->setObjectName(QString::fromUtf8("btnAdMQTTPublishTopic"));
        btnAdMQTTPublishTopic->setGeometry(QRect(382, 5, 23, 25));
        btnMQTTPublish = new QPushButton(tab_5);
        btnMQTTPublish->setObjectName(QString::fromUtf8("btnMQTTPublish"));
        btnMQTTPublish->setGeometry(QRect(100, 95, 89, 25));
        tbMQTTSubscribePublish->addTab(tab_5, QString());
        tbMain->addTab(tpMQTT, QString());
        tpCOAP = new QWidget();
        tpCOAP->setObjectName(QString::fromUtf8("tpCOAP"));
        label_21 = new QLabel(tpCOAP);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 40, 111, 17));
        label_22 = new QLabel(tpCOAP);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 70, 111, 17));
        label_23 = new QLabel(tpCOAP);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 100, 111, 17));
        cmbCoapCommand = new QComboBox(tpCOAP);
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->setObjectName(QString::fromUtf8("cmbCoapCommand"));
        cmbCoapCommand->setGeometry(QRect(140, 40, 411, 25));
        cmbCoapTimeProfile = new QComboBox(tpCOAP);
        cmbCoapTimeProfile->setObjectName(QString::fromUtf8("cmbCoapTimeProfile"));
        cmbCoapTimeProfile->setGeometry(QRect(140, 70, 391, 25));
        btnAddCoapTimeProfile = new QPushButton(tpCOAP);
        btnAddCoapTimeProfile->setObjectName(QString::fromUtf8("btnAddCoapTimeProfile"));
        btnAddCoapTimeProfile->setGeometry(QRect(530, 70, 23, 25));
        btnAddCoapDataProfile = new QPushButton(tpCOAP);
        btnAddCoapDataProfile->setObjectName(QString::fromUtf8("btnAddCoapDataProfile"));
        btnAddCoapDataProfile->setGeometry(QRect(530, 100, 23, 25));
        btnCoapAdd = new QPushButton(tpCOAP);
        btnCoapAdd->setObjectName(QString::fromUtf8("btnCoapAdd"));
        btnCoapAdd->setGeometry(QRect(140, 130, 89, 25));
        tbWidgetCoap = new QTableWidget(tpCOAP);
        tbWidgetCoap->setObjectName(QString::fromUtf8("tbWidgetCoap"));
        tbWidgetCoap->setGeometry(QRect(10, 160, 545, 341));
        label_20 = new QLabel(tpCOAP);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 11, 91, 17));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        txtCoapUrl = new QLineEdit(tpCOAP);
        txtCoapUrl->setObjectName(QString::fromUtf8("txtCoapUrl"));
        txtCoapUrl->setGeometry(QRect(140, 11, 411, 25));
        txtCoapParameters = new QLineEdit(tpCOAP);
        txtCoapParameters->setObjectName(QString::fromUtf8("txtCoapParameters"));
        txtCoapParameters->setEnabled(true);
        txtCoapParameters->setGeometry(QRect(140, 100, 391, 25));
        cmbCoapDataProfile = new QComboBox(tpCOAP);
        cmbCoapDataProfile->setObjectName(QString::fromUtf8("cmbCoapDataProfile"));
        cmbCoapDataProfile->setGeometry(QRect(140, 100, 391, 25));
        tbMain->addTab(tpCOAP, QString());
        txtCoapParameters->raise();
        label_21->raise();
        label_22->raise();
        label_23->raise();
        cmbCoapCommand->raise();
        cmbCoapTimeProfile->raise();
        btnAddCoapTimeProfile->raise();
        btnAddCoapDataProfile->raise();
        btnCoapAdd->raise();
        tbWidgetCoap->raise();
        label_20->raise();
        txtCoapUrl->raise();
        cmbCoapDataProfile->raise();
        tpHTTP = new QWidget();
        tpHTTP->setObjectName(QString::fromUtf8("tpHTTP"));
        cmbHttpCommand = new QComboBox(tpHTTP);
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->setObjectName(QString::fromUtf8("cmbHttpCommand"));
        cmbHttpCommand->setGeometry(QRect(140, 40, 411, 25));
        label_25 = new QLabel(tpHTTP);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 40, 111, 17));
        txtHttpUrl = new QLineEdit(tpHTTP);
        txtHttpUrl->setObjectName(QString::fromUtf8("txtHttpUrl"));
        txtHttpUrl->setGeometry(QRect(140, 11, 411, 25));
        label_26 = new QLabel(tpHTTP);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 11, 91, 17));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        cmbHttpTimeProfile = new QComboBox(tpHTTP);
        cmbHttpTimeProfile->setObjectName(QString::fromUtf8("cmbHttpTimeProfile"));
        cmbHttpTimeProfile->setGeometry(QRect(140, 70, 391, 25));
        label_27 = new QLabel(tpHTTP);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 70, 111, 17));
        btnHttpAdd = new QPushButton(tpHTTP);
        btnHttpAdd->setObjectName(QString::fromUtf8("btnHttpAdd"));
        btnHttpAdd->setGeometry(QRect(140, 130, 89, 25));
        tbWidgetHttp = new QTableWidget(tpHTTP);
        tbWidgetHttp->setObjectName(QString::fromUtf8("tbWidgetHttp"));
        tbWidgetHttp->setGeometry(QRect(10, 160, 545, 341));
        btnAddHttpDataProfile = new QPushButton(tpHTTP);
        btnAddHttpDataProfile->setObjectName(QString::fromUtf8("btnAddHttpDataProfile"));
        btnAddHttpDataProfile->setGeometry(QRect(530, 100, 23, 25));
        btnAddHttpTimeProfile = new QPushButton(tpHTTP);
        btnAddHttpTimeProfile->setObjectName(QString::fromUtf8("btnAddHttpTimeProfile"));
        btnAddHttpTimeProfile->setGeometry(QRect(530, 70, 23, 25));
        label_24 = new QLabel(tpHTTP);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 100, 111, 17));
        txtHttpParameters = new QLineEdit(tpHTTP);
        txtHttpParameters->setObjectName(QString::fromUtf8("txtHttpParameters"));
        txtHttpParameters->setGeometry(QRect(140, 100, 391, 25));
        cmbHttpDataProfile = new QComboBox(tpHTTP);
        cmbHttpDataProfile->setObjectName(QString::fromUtf8("cmbHttpDataProfile"));
        cmbHttpDataProfile->setGeometry(QRect(140, 100, 391, 25));
        tbMain->addTab(tpHTTP, QString());
        txtHttpParameters->raise();
        cmbHttpCommand->raise();
        label_25->raise();
        txtHttpUrl->raise();
        label_26->raise();
        cmbHttpTimeProfile->raise();
        label_27->raise();
        btnHttpAdd->raise();
        tbWidgetHttp->raise();
        btnAddHttpDataProfile->raise();
        btnAddHttpTimeProfile->raise();
        label_24->raise();
        cmbHttpDataProfile->raise();
        layoutWidget3 = new QWidget(frmNewDeviceTemplate);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 580, 491, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnCreate = new QPushButton(layoutWidget3);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        horizontalLayout_2->addWidget(btnCreate);

        btnClose = new QPushButton(layoutWidget3);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout_2->addWidget(btnClose);

        cmbTemplates = new QComboBox(frmNewDeviceTemplate);
        cmbTemplates->setObjectName(QString::fromUtf8("cmbTemplates"));
        cmbTemplates->setGeometry(QRect(140, 10, 421, 25));
        cmbTemplates->setEditable(false);
        lblDeviceName = new QLabel(frmNewDeviceTemplate);
        lblDeviceName->setObjectName(QString::fromUtf8("lblDeviceName"));
        lblDeviceName->setGeometry(QRect(11, 11, 81, 16));
        lblDeviceName->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        txtDeviceName = new QLineEdit(frmNewDeviceTemplate);
        txtDeviceName->setObjectName(QString::fromUtf8("txtDeviceName"));
        txtDeviceName->setGeometry(QRect(140, 10, 421, 23));
        txtDeviceName->raise();
        cmbTemplates->raise();
        tbMain->raise();
        layoutWidget->raise();
        lblDeviceName->raise();

        retranslateUi(frmNewDeviceTemplate);

        tbMain->setCurrentIndex(0);
        tbMQTTSubscribePublish->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(frmNewDeviceTemplate);
    } // setupUi

    void retranslateUi(QDialog *frmNewDeviceTemplate)
    {
        frmNewDeviceTemplate->setWindowTitle(QApplication::translate("frmNewDeviceTemplate", "New Device Template", nullptr));
        gbIsAttackingEntity->setTitle(QApplication::translate("frmNewDeviceTemplate", "Attacking Entity", nullptr));
        label_4->setText(QApplication::translate("frmNewDeviceTemplate", "Attack Type", nullptr));
        cmbAttackType->setItemText(0, QApplication::translate("frmNewDeviceTemplate", "MQTT Publish Flood", nullptr));
        cmbAttackType->setItemText(1, QApplication::translate("frmNewDeviceTemplate", "MQTT Authentication Bypass", nullptr));
        cmbAttackType->setItemText(2, QApplication::translate("frmNewDeviceTemplate", "MQTT Crafted Packet", nullptr));
        cmbAttackType->setItemText(3, QApplication::translate("frmNewDeviceTemplate", "COAP PUT Flood", nullptr));
        cmbAttackType->setItemText(4, QApplication::translate("frmNewDeviceTemplate", "COAP Crafted Payload", nullptr));
        cmbAttackType->setItemText(5, QApplication::translate("frmNewDeviceTemplate", "TCP Flood", nullptr));
        cmbAttackType->setItemText(6, QApplication::translate("frmNewDeviceTemplate", "UDP Flood", nullptr));

        label_30->setText(QApplication::translate("frmNewDeviceTemplate", "Source IP", nullptr));
        label_14->setText(QApplication::translate("frmNewDeviceTemplate", "Target IP", nullptr));
        label_28->setText(QApplication::translate("frmNewDeviceTemplate", "Target Port", nullptr));
        label_29->setText(QApplication::translate("frmNewDeviceTemplate", "Messages / sec", nullptr));
        label_31->setText(QApplication::translate("frmNewDeviceTemplate", "Message", nullptr));
        lblDeviceName2->setText(QApplication::translate("frmNewDeviceTemplate", "Device Name", nullptr));
        label_13->setText(QApplication::translate("frmNewDeviceTemplate", "Protocol", nullptr));
        cmbProtocol->setItemText(0, QString());
        cmbProtocol->setItemText(1, QApplication::translate("frmNewDeviceTemplate", "MQTT", nullptr));
        cmbProtocol->setItemText(2, QApplication::translate("frmNewDeviceTemplate", "COAP", nullptr));

        label->setText(QApplication::translate("frmNewDeviceTemplate", "IP Address", nullptr));
        txtIPAddress->setText(QString());
        label_12->setText(QApplication::translate("frmNewDeviceTemplate", "No. of Devices", nullptr));
        tbMain->setTabText(tbMain->indexOf(tab), QApplication::translate("frmNewDeviceTemplate", "General", nullptr));
        groupBox_3->setTitle(QApplication::translate("frmNewDeviceTemplate", "Broker Port", nullptr));
        rbMQTTRegular->setText(QApplication::translate("frmNewDeviceTemplate", "Regular", nullptr));
        rbMQTTTLS->setText(QApplication::translate("frmNewDeviceTemplate", "TLS", nullptr));
        gbBrookerAuthentication->setTitle(QApplication::translate("frmNewDeviceTemplate", "Broker Authentication", nullptr));
        label_10->setText(QApplication::translate("frmNewDeviceTemplate", "User Name", nullptr));
        label_11->setText(QApplication::translate("frmNewDeviceTemplate", "Password", nullptr));
        label_3->setText(QApplication::translate("frmNewDeviceTemplate", "Broker", nullptr));
        txtBrokerIP->setText(QString());
        btnAddSubscribeTopic->setText(QApplication::translate("frmNewDeviceTemplate", "Add", nullptr));
        label_15->setText(QApplication::translate("frmNewDeviceTemplate", "Topic", nullptr));
        btnAdMQTTSubscribeTopic->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        tbMQTTSubscribePublish->setTabText(tbMQTTSubscribePublish->indexOf(tab_4), QApplication::translate("frmNewDeviceTemplate", "Subscribe", nullptr));
        label_16->setText(QApplication::translate("frmNewDeviceTemplate", "Topic", nullptr));
        label_17->setText(QApplication::translate("frmNewDeviceTemplate", "Data Profile", nullptr));
        label_18->setText(QApplication::translate("frmNewDeviceTemplate", "Time Profile", nullptr));
        btnMQTTPublishDataProfile->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        label_19->setText(QApplication::translate("frmNewDeviceTemplate", "QoS", nullptr));
        cmbMQTTQoS->setItemText(0, QApplication::translate("frmNewDeviceTemplate", "0", nullptr));
        cmbMQTTQoS->setItemText(1, QApplication::translate("frmNewDeviceTemplate", "1", nullptr));
        cmbMQTTQoS->setItemText(2, QApplication::translate("frmNewDeviceTemplate", "2", nullptr));

        btnMQTTPublishTimeProfile->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        btnAdMQTTPublishTopic->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        btnMQTTPublish->setText(QApplication::translate("frmNewDeviceTemplate", "Add", nullptr));
        tbMQTTSubscribePublish->setTabText(tbMQTTSubscribePublish->indexOf(tab_5), QApplication::translate("frmNewDeviceTemplate", "Publish", nullptr));
        tbMain->setTabText(tbMain->indexOf(tpMQTT), QApplication::translate("frmNewDeviceTemplate", "MQTT", nullptr));
        label_21->setText(QApplication::translate("frmNewDeviceTemplate", "CoAP Command", nullptr));
        label_22->setText(QApplication::translate("frmNewDeviceTemplate", "Time Profile", nullptr));
        label_23->setText(QApplication::translate("frmNewDeviceTemplate", "Data Profile", nullptr));
        cmbCoapCommand->setItemText(0, QApplication::translate("frmNewDeviceTemplate", "GET", nullptr));
        cmbCoapCommand->setItemText(1, QApplication::translate("frmNewDeviceTemplate", "POST", nullptr));
        cmbCoapCommand->setItemText(2, QApplication::translate("frmNewDeviceTemplate", "PUT", nullptr));
        cmbCoapCommand->setItemText(3, QApplication::translate("frmNewDeviceTemplate", "DELETE", nullptr));
        cmbCoapCommand->setItemText(4, QApplication::translate("frmNewDeviceTemplate", "DISCOVER", nullptr));

        btnAddCoapTimeProfile->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        btnAddCoapDataProfile->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        btnCoapAdd->setText(QApplication::translate("frmNewDeviceTemplate", "Add", nullptr));
        label_20->setText(QApplication::translate("frmNewDeviceTemplate", "CoAP URL", nullptr));
        txtCoapUrl->setText(QString());
        txtCoapParameters->setText(QString());
        tbMain->setTabText(tbMain->indexOf(tpCOAP), QApplication::translate("frmNewDeviceTemplate", "COAP", nullptr));
        cmbHttpCommand->setItemText(0, QApplication::translate("frmNewDeviceTemplate", "GET", nullptr));
        cmbHttpCommand->setItemText(1, QApplication::translate("frmNewDeviceTemplate", "SEND", nullptr));
        cmbHttpCommand->setItemText(2, QApplication::translate("frmNewDeviceTemplate", "POST", nullptr));
        cmbHttpCommand->setItemText(3, QApplication::translate("frmNewDeviceTemplate", "RECEIVE", nullptr));

        label_25->setText(QApplication::translate("frmNewDeviceTemplate", "HTTP Command", nullptr));
        txtHttpUrl->setText(QString());
        label_26->setText(QApplication::translate("frmNewDeviceTemplate", "HTTP URL", nullptr));
        label_27->setText(QApplication::translate("frmNewDeviceTemplate", "Time Profile", nullptr));
        btnHttpAdd->setText(QApplication::translate("frmNewDeviceTemplate", "Add", nullptr));
        btnAddHttpDataProfile->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        btnAddHttpTimeProfile->setText(QApplication::translate("frmNewDeviceTemplate", "+", nullptr));
        label_24->setText(QApplication::translate("frmNewDeviceTemplate", "Parameters", nullptr));
        txtHttpParameters->setText(QString());
        tbMain->setTabText(tbMain->indexOf(tpHTTP), QApplication::translate("frmNewDeviceTemplate", "HTTP", nullptr));
        btnCreate->setText(QApplication::translate("frmNewDeviceTemplate", "Save", nullptr));
        btnClose->setText(QApplication::translate("frmNewDeviceTemplate", "Close", nullptr));
        cmbTemplates->setCurrentText(QString());
        lblDeviceName->setText(QApplication::translate("frmNewDeviceTemplate", "Device Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmNewDeviceTemplate: public Ui_frmNewDeviceTemplate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMNEWDEVICETEMPLATE_H
