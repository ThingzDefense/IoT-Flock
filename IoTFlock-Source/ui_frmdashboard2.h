/********************************************************************************
** Form generated from reading UI file 'frmdashboard2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDASHBOARD2_H
#define UI_FRMDASHBOARD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmDashboard2
{
public:
    QAction *actionTopic;
    QAction *actionData_Profile;
    QAction *actionTime_Profile;
    QAction *actionDevice_Template;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblSecTimer;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddNewUseCase;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuSetup;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *frmDashboard2)
    {
        if (frmDashboard2->objectName().isEmpty())
            frmDashboard2->setObjectName(QStringLiteral("frmDashboard2"));
        frmDashboard2->resize(800, 600);
        actionTopic = new QAction(frmDashboard2);
        actionTopic->setObjectName(QStringLiteral("actionTopic"));
        actionData_Profile = new QAction(frmDashboard2);
        actionData_Profile->setObjectName(QStringLiteral("actionData_Profile"));
        actionTime_Profile = new QAction(frmDashboard2);
        actionTime_Profile->setObjectName(QStringLiteral("actionTime_Profile"));
        actionDevice_Template = new QAction(frmDashboard2);
        actionDevice_Template->setObjectName(QStringLiteral("actionDevice_Template"));
        centralwidget = new QWidget(frmDashboard2);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblSecTimer = new QLabel(centralwidget);
        lblSecTimer->setObjectName(QStringLiteral("lblSecTimer"));

        horizontalLayout->addWidget(lblSecTimer);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAddNewUseCase = new QPushButton(centralwidget);
        btnAddNewUseCase->setObjectName(QStringLiteral("btnAddNewUseCase"));

        horizontalLayout->addWidget(btnAddNewUseCase);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        frmDashboard2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(frmDashboard2);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuSetup = new QMenu(menubar);
        menuSetup->setObjectName(QStringLiteral("menuSetup"));
        frmDashboard2->setMenuBar(menubar);
        statusbar = new QStatusBar(frmDashboard2);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        frmDashboard2->setStatusBar(statusbar);

        menubar->addAction(menuSetup->menuAction());
        menuSetup->addAction(actionTopic);
        menuSetup->addAction(actionData_Profile);
        menuSetup->addAction(actionTime_Profile);
        menuSetup->addAction(actionDevice_Template);

        retranslateUi(frmDashboard2);

        QMetaObject::connectSlotsByName(frmDashboard2);
    } // setupUi

    void retranslateUi(QMainWindow *frmDashboard2)
    {
        frmDashboard2->setWindowTitle(QApplication::translate("frmDashboard2", "MainWindow", nullptr));
        actionTopic->setText(QApplication::translate("frmDashboard2", "Topic", nullptr));
        actionData_Profile->setText(QApplication::translate("frmDashboard2", "Data Profile", nullptr));
        actionTime_Profile->setText(QApplication::translate("frmDashboard2", "Time Profile", nullptr));
        actionDevice_Template->setText(QApplication::translate("frmDashboard2", "Device Template", nullptr));
        lblSecTimer->setText(QApplication::translate("frmDashboard2", "Existing UseCases", nullptr));
        btnAddNewUseCase->setText(QApplication::translate("frmDashboard2", "+ Add New UseCase", nullptr));
        menuSetup->setTitle(QApplication::translate("frmDashboard2", "Setup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmDashboard2: public Ui_frmDashboard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDASHBOARD2_H
