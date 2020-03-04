/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTopic;
    QAction *actionData_Profile;
    QAction *actionTime_Profile;
    QAction *actionUDP_Flood;
    QAction *actionDevice_Template;
    QAction *actionNew_Device;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionLoad;
    QAction *actionNew;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *ucNameLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QPushButton *btnRefresh;
    QCheckBox *chkTimer;
    QLabel *lblTimer;
    QSpinBox *sbAutoRefresh;
    QLabel *lblSecTimer;
    QPushButton *btnClear;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *UseCase;
    QMenu *menuSetup;
    QMenu *menuDevice;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(734, 329);
        actionTopic = new QAction(MainWindow);
        actionTopic->setObjectName(QString::fromUtf8("actionTopic"));
        actionData_Profile = new QAction(MainWindow);
        actionData_Profile->setObjectName(QString::fromUtf8("actionData_Profile"));
        actionTime_Profile = new QAction(MainWindow);
        actionTime_Profile->setObjectName(QString::fromUtf8("actionTime_Profile"));
        actionUDP_Flood = new QAction(MainWindow);
        actionUDP_Flood->setObjectName(QString::fromUtf8("actionUDP_Flood"));
        actionDevice_Template = new QAction(MainWindow);
        actionDevice_Template->setObjectName(QString::fromUtf8("actionDevice_Template"));
        actionNew_Device = new QAction(MainWindow);
        actionNew_Device->setObjectName(QString::fromUtf8("actionNew_Device"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setVisible(false);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionSave_As->setVisible(false);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        ucNameLabel = new QLabel(centralWidget);
        ucNameLabel->setObjectName(QString::fromUtf8("ucNameLabel"));

        horizontalLayout->addWidget(ucNameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        horizontalLayout->addWidget(btnStart);

        btnStop = new QPushButton(centralWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        horizontalLayout->addWidget(btnStop);

        btnRefresh = new QPushButton(centralWidget);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));

        horizontalLayout->addWidget(btnRefresh);

        chkTimer = new QCheckBox(centralWidget);
        chkTimer->setObjectName(QString::fromUtf8("chkTimer"));

        horizontalLayout->addWidget(chkTimer);

        lblTimer = new QLabel(centralWidget);
        lblTimer->setObjectName(QString::fromUtf8("lblTimer"));
        lblTimer->setEnabled(true);

        horizontalLayout->addWidget(lblTimer);

        sbAutoRefresh = new QSpinBox(centralWidget);
        sbAutoRefresh->setObjectName(QString::fromUtf8("sbAutoRefresh"));

        horizontalLayout->addWidget(sbAutoRefresh);

        lblSecTimer = new QLabel(centralWidget);
        lblSecTimer->setObjectName(QString::fromUtf8("lblSecTimer"));

        horizontalLayout->addWidget(lblSecTimer);

        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        horizontalLayout->addWidget(btnClear);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 734, 20));
        UseCase = new QMenu(menuBar);
        UseCase->setObjectName(QString::fromUtf8("UseCase"));
        menuSetup = new QMenu(menuBar);
        menuSetup->setObjectName(QString::fromUtf8("menuSetup"));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QString::fromUtf8("menuDevice"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSetup->menuAction());
        menuBar->addAction(UseCase->menuAction());
        menuBar->addAction(menuDevice->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        UseCase->addAction(actionSave);
        UseCase->addAction(actionSave_As);
        UseCase->addAction(actionLoad);
        menuSetup->addAction(actionTopic);
        menuSetup->addAction(actionData_Profile);
        menuSetup->addAction(actionTime_Profile);
        menuSetup->addAction(actionDevice_Template);
        menuDevice->addAction(actionNew_Device);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        actionTopic->setText(QApplication::translate("MainWindow", "Topic", nullptr));
        actionData_Profile->setText(QApplication::translate("MainWindow", "Data Profile", nullptr));
        actionTime_Profile->setText(QApplication::translate("MainWindow", "Time Profile", nullptr));
        actionUDP_Flood->setText(QApplication::translate("MainWindow", "UDP Flood", nullptr));
        actionDevice_Template->setText(QApplication::translate("MainWindow", "Device Template", nullptr));
        actionNew_Device->setText(QApplication::translate("MainWindow", "New Device", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", nullptr));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
        label->setText(QApplication::translate("MainWindow", "Use Case Name:", nullptr));
        ucNameLabel->setText(QApplication::translate("MainWindow", "[]", nullptr));
        btnStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        btnStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        btnRefresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        chkTimer->setText(QString());
        lblTimer->setText(QApplication::translate("MainWindow", "Auto Refresh", nullptr));
        lblSecTimer->setText(QApplication::translate("MainWindow", "Sec", nullptr));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        UseCase->setTitle(QApplication::translate("MainWindow", "Use Case", nullptr));
        menuSetup->setTitle(QApplication::translate("MainWindow", "Setup", nullptr));
        menuDevice->setTitle(QApplication::translate("MainWindow", "Device", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
