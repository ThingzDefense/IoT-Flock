/********************************************************************************
** Form generated from reading UI file 'frmnewdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMNEWDEVICE_H
#define UI_FRMNEWDEVICE_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmnewDevice
{
public:
    QTabWidget *tbMain;
    QWidget *tab;
    QWidget *layoutWidget;
    QFormLayout *formLayout_4;
    QLabel *label_13;
    QComboBox *cmbProtocol;
    QLabel *label;
    QLineEdit *txtIPAddress;
    QLabel *label_12;
    QSpinBox *sbNumofDevices;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget1;
    QFormLayout *formLayout_2;
    QRadioButton *rbMQTTRegular;
    QSpinBox *sbBrokerPortRegular;
    QRadioButton *rbMQTTTLS;
    QSpinBox *sbBrokerportTLS;
    QGroupBox *isBrookerAuthentication;
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
    QWidget *tab_3;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QComboBox *cmbCoapCommand;
    QComboBox *cmbCoapTimeProfile;
    QComboBox *cmbCoapDataProfile;
    QPushButton *btnAddCoapTimeProfile;
    QPushButton *btnAddCoapDataProfile;
    QPushButton *btnCoapAdd;
    QTableWidget *tbWidgetCoap;
    QLabel *label_20;
    QLineEdit *txtCoapUrl;
    QWidget *tab_6;
    QComboBox *cmbHttpDataProfile;
    QLabel *label_24;
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
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCreate;
    QPushButton *btnClose;
    QWidget *layoutWidget4;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *cmbSelectTemplate;

    void setupUi(QDialog *frmnewDevice)
    {
        if (frmnewDevice->objectName().isEmpty())
            frmnewDevice->setObjectName(QString::fromUtf8("frmnewDevice"));
        frmnewDevice->resize(544, 613);
        tbMain = new QTabWidget(frmnewDevice);
        tbMain->setObjectName(QString::fromUtf8("tbMain"));
        tbMain->setGeometry(QRect(10, 44, 531, 531));
        tbMain->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 461, 90));
        formLayout_4 = new QFormLayout(layoutWidget);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_13);

        cmbProtocol = new QComboBox(layoutWidget);
        cmbProtocol->addItem(QString());
        cmbProtocol->addItem(QString());
        cmbProtocol->addItem(QString());
        cmbProtocol->addItem(QString());
        cmbProtocol->addItem(QString());
        cmbProtocol->setObjectName(QString::fromUtf8("cmbProtocol"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, cmbProtocol);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label);

        txtIPAddress = new QLineEdit(layoutWidget);
        txtIPAddress->setObjectName(QString::fromUtf8("txtIPAddress"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, txtIPAddress);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_12);

        sbNumofDevices = new QSpinBox(layoutWidget);
        sbNumofDevices->setObjectName(QString::fromUtf8("sbNumofDevices"));
        sbNumofDevices->setMinimum(1);
        sbNumofDevices->setMaximum(1000);
        sbNumofDevices->setValue(1);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, sbNumofDevices);

        tbMain->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(9, 44, 181, 111));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(13, 33, 161, 60));
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

        isBrookerAuthentication = new QGroupBox(tab_2);
        isBrookerAuthentication->setObjectName(QString::fromUtf8("isBrookerAuthentication"));
        isBrookerAuthentication->setGeometry(QRect(200, 50, 281, 102));
        isBrookerAuthentication->setCheckable(true);
        isBrookerAuthentication->setChecked(false);
        verticalLayout_6 = new QVBoxLayout(isBrookerAuthentication);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_10 = new QLabel(isBrookerAuthentication);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        txtBrokerUserName = new QLineEdit(isBrookerAuthentication);
        txtBrokerUserName->setObjectName(QString::fromUtf8("txtBrokerUserName"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, txtBrokerUserName);

        label_11 = new QLabel(isBrookerAuthentication);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_11);

        txtBrokerPassword = new QLineEdit(isBrookerAuthentication);
        txtBrokerPassword->setObjectName(QString::fromUtf8("txtBrokerPassword"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, txtBrokerPassword);


        verticalLayout_6->addLayout(formLayout_3);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 471, 27));
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

        tbMQTTSubscribePublish = new QTabWidget(tab_2);
        tbMQTTSubscribePublish->setObjectName(QString::fromUtf8("tbMQTTSubscribePublish"));
        tbMQTTSubscribePublish->setGeometry(QRect(10, 150, 511, 351));
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        btnAddSubscribeTopic = new QPushButton(tab_4);
        btnAddSubscribeTopic->setObjectName(QString::fromUtf8("btnAddSubscribeTopic"));
        btnAddSubscribeTopic->setGeometry(QRect(70, 30, 89, 25));
        cmbSubscribeTopic = new QComboBox(tab_4);
        cmbSubscribeTopic->setObjectName(QString::fromUtf8("cmbSubscribeTopic"));
        cmbSubscribeTopic->setGeometry(QRect(70, 5, 401, 25));
        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 6, 51, 17));
        tbWidgetSubscribeTopic = new QTableWidget(tab_4);
        tbWidgetSubscribeTopic->setObjectName(QString::fromUtf8("tbWidgetSubscribeTopic"));
        tbWidgetSubscribeTopic->setGeometry(QRect(20, 60, 471, 250));
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
        tbWidgetMQTTPublish->setGeometry(QRect(3, 122, 501, 190));
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
        tbMain->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label_21 = new QLabel(tab_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 40, 111, 17));
        label_22 = new QLabel(tab_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 70, 111, 17));
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(10, 100, 111, 17));
        cmbCoapCommand = new QComboBox(tab_3);
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->addItem(QString());
        cmbCoapCommand->setObjectName(QString::fromUtf8("cmbCoapCommand"));
        cmbCoapCommand->setGeometry(QRect(140, 40, 361, 25));
        cmbCoapTimeProfile = new QComboBox(tab_3);
        cmbCoapTimeProfile->setObjectName(QString::fromUtf8("cmbCoapTimeProfile"));
        cmbCoapTimeProfile->setGeometry(QRect(140, 70, 341, 25));
        cmbCoapDataProfile = new QComboBox(tab_3);
        cmbCoapDataProfile->setObjectName(QString::fromUtf8("cmbCoapDataProfile"));
        cmbCoapDataProfile->setGeometry(QRect(140, 100, 341, 25));
        btnAddCoapTimeProfile = new QPushButton(tab_3);
        btnAddCoapTimeProfile->setObjectName(QString::fromUtf8("btnAddCoapTimeProfile"));
        btnAddCoapTimeProfile->setGeometry(QRect(481, 70, 23, 25));
        btnAddCoapDataProfile = new QPushButton(tab_3);
        btnAddCoapDataProfile->setObjectName(QString::fromUtf8("btnAddCoapDataProfile"));
        btnAddCoapDataProfile->setGeometry(QRect(481, 100, 23, 25));
        btnCoapAdd = new QPushButton(tab_3);
        btnCoapAdd->setObjectName(QString::fromUtf8("btnCoapAdd"));
        btnCoapAdd->setGeometry(QRect(140, 130, 89, 25));
        tbWidgetCoap = new QTableWidget(tab_3);
        tbWidgetCoap->setObjectName(QString::fromUtf8("tbWidgetCoap"));
        tbWidgetCoap->setGeometry(QRect(10, 160, 501, 321));
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 11, 91, 17));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        txtCoapUrl = new QLineEdit(tab_3);
        txtCoapUrl->setObjectName(QString::fromUtf8("txtCoapUrl"));
        txtCoapUrl->setGeometry(QRect(140, 11, 361, 25));
        tbMain->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        cmbHttpDataProfile = new QComboBox(tab_6);
        cmbHttpDataProfile->setObjectName(QString::fromUtf8("cmbHttpDataProfile"));
        cmbHttpDataProfile->setGeometry(QRect(140, 100, 341, 25));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 100, 111, 17));
        cmbHttpCommand = new QComboBox(tab_6);
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->addItem(QString());
        cmbHttpCommand->setObjectName(QString::fromUtf8("cmbHttpCommand"));
        cmbHttpCommand->setGeometry(QRect(140, 40, 361, 25));
        label_25 = new QLabel(tab_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(10, 40, 111, 17));
        txtHttpUrl = new QLineEdit(tab_6);
        txtHttpUrl->setObjectName(QString::fromUtf8("txtHttpUrl"));
        txtHttpUrl->setGeometry(QRect(140, 11, 361, 25));
        label_26 = new QLabel(tab_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 11, 91, 17));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        cmbHttpTimeProfile = new QComboBox(tab_6);
        cmbHttpTimeProfile->setObjectName(QString::fromUtf8("cmbHttpTimeProfile"));
        cmbHttpTimeProfile->setGeometry(QRect(140, 70, 341, 25));
        label_27 = new QLabel(tab_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(10, 70, 111, 17));
        btnHttpAdd = new QPushButton(tab_6);
        btnHttpAdd->setObjectName(QString::fromUtf8("btnHttpAdd"));
        btnHttpAdd->setGeometry(QRect(140, 130, 89, 25));
        tbWidgetHttp = new QTableWidget(tab_6);
        tbWidgetHttp->setObjectName(QString::fromUtf8("tbWidgetHttp"));
        tbWidgetHttp->setGeometry(QRect(10, 160, 501, 321));
        btnAddHttpDataProfile = new QPushButton(tab_6);
        btnAddHttpDataProfile->setObjectName(QString::fromUtf8("btnAddHttpDataProfile"));
        btnAddHttpDataProfile->setGeometry(QRect(481, 100, 23, 25));
        btnAddHttpTimeProfile = new QPushButton(tab_6);
        btnAddHttpTimeProfile->setObjectName(QString::fromUtf8("btnAddHttpTimeProfile"));
        btnAddHttpTimeProfile->setGeometry(QRect(481, 70, 23, 25));
        tbMain->addTab(tab_6, QString());
        layoutWidget3 = new QWidget(frmnewDevice);
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

        layoutWidget4 = new QWidget(frmnewDevice);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 10, 521, 25));
        formLayout = new QFormLayout(layoutWidget4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        cmbSelectTemplate = new QComboBox(layoutWidget4);
        cmbSelectTemplate->setObjectName(QString::fromUtf8("cmbSelectTemplate"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cmbSelectTemplate);


        retranslateUi(frmnewDevice);

        tbMain->setCurrentIndex(0);
        tbMQTTSubscribePublish->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(frmnewDevice);
    } // setupUi

    void retranslateUi(QDialog *frmnewDevice)
    {
        frmnewDevice->setWindowTitle(QApplication::translate("frmnewDevice", "New Device Template", nullptr));
        label_13->setText(QApplication::translate("frmnewDevice", "Protocol", nullptr));
        cmbProtocol->setItemText(0, QApplication::translate("frmnewDevice", "MQTT", nullptr));
        cmbProtocol->setItemText(1, QApplication::translate("frmnewDevice", "MQTTs", nullptr));
        cmbProtocol->setItemText(2, QApplication::translate("frmnewDevice", "COAP", nullptr));
        cmbProtocol->setItemText(3, QApplication::translate("frmnewDevice", "HTTP", nullptr));
        cmbProtocol->setItemText(4, QApplication::translate("frmnewDevice", "HTTPs", nullptr));

        label->setText(QApplication::translate("frmnewDevice", "IP Address", nullptr));
        txtIPAddress->setText(QString());
        label_12->setText(QApplication::translate("frmnewDevice", "No. of Devices", nullptr));
        tbMain->setTabText(tbMain->indexOf(tab), QApplication::translate("frmnewDevice", "General", nullptr));
        groupBox_3->setTitle(QApplication::translate("frmnewDevice", "Broker Port", nullptr));
        rbMQTTRegular->setText(QApplication::translate("frmnewDevice", "Regular", nullptr));
        rbMQTTTLS->setText(QApplication::translate("frmnewDevice", "TLS", nullptr));
        isBrookerAuthentication->setTitle(QApplication::translate("frmnewDevice", "Broker Authentication", nullptr));
        label_10->setText(QApplication::translate("frmnewDevice", "User Name", nullptr));
        label_11->setText(QApplication::translate("frmnewDevice", "Password", nullptr));
        label_3->setText(QApplication::translate("frmnewDevice", "Broker", nullptr));
        txtBrokerIP->setText(QString());
        btnAddSubscribeTopic->setText(QApplication::translate("frmnewDevice", "Add", nullptr));
        label_15->setText(QApplication::translate("frmnewDevice", "Topic", nullptr));
        btnAdMQTTSubscribeTopic->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        tbMQTTSubscribePublish->setTabText(tbMQTTSubscribePublish->indexOf(tab_4), QApplication::translate("frmnewDevice", "Subscribe", nullptr));
        label_16->setText(QApplication::translate("frmnewDevice", "Topic", nullptr));
        label_17->setText(QApplication::translate("frmnewDevice", "Data Profile", nullptr));
        label_18->setText(QApplication::translate("frmnewDevice", "Time Profile", nullptr));
        btnMQTTPublishDataProfile->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        label_19->setText(QApplication::translate("frmnewDevice", "QoS", nullptr));
        cmbMQTTQoS->setItemText(0, QApplication::translate("frmnewDevice", "0", nullptr));
        cmbMQTTQoS->setItemText(1, QApplication::translate("frmnewDevice", "1", nullptr));
        cmbMQTTQoS->setItemText(2, QApplication::translate("frmnewDevice", "2", nullptr));

        btnMQTTPublishTimeProfile->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        btnAdMQTTPublishTopic->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        btnMQTTPublish->setText(QApplication::translate("frmnewDevice", "Add", nullptr));
        tbMQTTSubscribePublish->setTabText(tbMQTTSubscribePublish->indexOf(tab_5), QApplication::translate("frmnewDevice", "Publish", nullptr));
        tbMain->setTabText(tbMain->indexOf(tab_2), QApplication::translate("frmnewDevice", "MQTT", nullptr));
        label_21->setText(QApplication::translate("frmnewDevice", "CoAP Command", nullptr));
        label_22->setText(QApplication::translate("frmnewDevice", "Time Profile", nullptr));
        label_23->setText(QApplication::translate("frmnewDevice", "Data Profile", nullptr));
        cmbCoapCommand->setItemText(0, QApplication::translate("frmnewDevice", "GET", nullptr));
        cmbCoapCommand->setItemText(1, QApplication::translate("frmnewDevice", "SEND", nullptr));
        cmbCoapCommand->setItemText(2, QApplication::translate("frmnewDevice", "POST", nullptr));
        cmbCoapCommand->setItemText(3, QApplication::translate("frmnewDevice", "RECEIVE", nullptr));

        btnAddCoapTimeProfile->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        btnAddCoapDataProfile->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        btnCoapAdd->setText(QApplication::translate("frmnewDevice", "Add", nullptr));
        label_20->setText(QApplication::translate("frmnewDevice", "CoAP URL", nullptr));
        txtCoapUrl->setText(QString());
        tbMain->setTabText(tbMain->indexOf(tab_3), QApplication::translate("frmnewDevice", "COAP", nullptr));
        label_24->setText(QApplication::translate("frmnewDevice", "Data Profile", nullptr));
        cmbHttpCommand->setItemText(0, QApplication::translate("frmnewDevice", "GET", nullptr));
        cmbHttpCommand->setItemText(1, QApplication::translate("frmnewDevice", "SEND", nullptr));
        cmbHttpCommand->setItemText(2, QApplication::translate("frmnewDevice", "POST", nullptr));
        cmbHttpCommand->setItemText(3, QApplication::translate("frmnewDevice", "RECEIVE", nullptr));

        label_25->setText(QApplication::translate("frmnewDevice", "HTTP Command", nullptr));
        txtHttpUrl->setText(QString());
        label_26->setText(QApplication::translate("frmnewDevice", "HTTP URL", nullptr));
        label_27->setText(QApplication::translate("frmnewDevice", "Time Profile", nullptr));
        btnHttpAdd->setText(QApplication::translate("frmnewDevice", "Add", nullptr));
        btnAddHttpDataProfile->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        btnAddHttpTimeProfile->setText(QApplication::translate("frmnewDevice", "+", nullptr));
        tbMain->setTabText(tbMain->indexOf(tab_6), QApplication::translate("frmnewDevice", "HTTP", nullptr));
        btnCreate->setText(QApplication::translate("frmnewDevice", "Save", nullptr));
        btnClose->setText(QApplication::translate("frmnewDevice", "Close", nullptr));
        label_4->setText(QApplication::translate("frmnewDevice", "Existing Device Tempaltes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmnewDevice: public Ui_frmnewDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMNEWDEVICE_H
