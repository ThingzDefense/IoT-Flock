/********************************************************************************
** Form generated from reading UI file 'frmusecasedevices.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMUSECASEDEVICES_H
#define UI_FRMUSECASEDEVICES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmUsecaseDevices
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddNewdevice;
    QTableWidget *tableWidget;

    void setupUi(QDialog *frmUsecaseDevices)
    {
        if (frmUsecaseDevices->objectName().isEmpty())
            frmUsecaseDevices->setObjectName(QString::fromUtf8("frmUsecaseDevices"));
        frmUsecaseDevices->resize(725, 600);
        verticalLayout = new QVBoxLayout(frmUsecaseDevices);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frmUsecaseDevices);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAddNewdevice = new QPushButton(frmUsecaseDevices);
        btnAddNewdevice->setObjectName(QString::fromUtf8("btnAddNewdevice"));

        horizontalLayout->addWidget(btnAddNewdevice);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(frmUsecaseDevices);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(frmUsecaseDevices);

        QMetaObject::connectSlotsByName(frmUsecaseDevices);
    } // setupUi

    void retranslateUi(QDialog *frmUsecaseDevices)
    {
        frmUsecaseDevices->setWindowTitle(QApplication::translate("frmUsecaseDevices", "Dialog", nullptr));
        label->setText(QApplication::translate("frmUsecaseDevices", "List of Devices in Usecase", nullptr));
        btnAddNewdevice->setText(QApplication::translate("frmUsecaseDevices", "+ Add New Device", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmUsecaseDevices: public Ui_frmUsecaseDevices {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMUSECASEDEVICES_H
