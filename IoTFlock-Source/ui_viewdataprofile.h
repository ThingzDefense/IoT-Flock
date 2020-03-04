/********************************************************************************
** Form generated from reading UI file 'viewdataprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDATAPROFILE_H
#define UI_VIEWDATAPROFILE_H

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

class Ui_ViewDataProfile
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNewDataProfile;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ViewDataProfile)
    {
        if (ViewDataProfile->objectName().isEmpty())
            ViewDataProfile->setObjectName(QString::fromUtf8("ViewDataProfile"));
        ViewDataProfile->resize(637, 280);
        verticalLayout = new QVBoxLayout(ViewDataProfile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ViewDataProfile);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnNewDataProfile = new QPushButton(ViewDataProfile);
        btnNewDataProfile->setObjectName(QString::fromUtf8("btnNewDataProfile"));

        horizontalLayout->addWidget(btnNewDataProfile);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(ViewDataProfile);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ViewDataProfile);

        QMetaObject::connectSlotsByName(ViewDataProfile);
    } // setupUi

    void retranslateUi(QDialog *ViewDataProfile)
    {
        ViewDataProfile->setWindowTitle(QApplication::translate("ViewDataProfile", "Data Profile", nullptr));
        label->setText(QApplication::translate("ViewDataProfile", "Data profile is data sent by device. Data can contain static/random text", nullptr));
        btnNewDataProfile->setText(QApplication::translate("ViewDataProfile", "+Create New Data Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewDataProfile: public Ui_ViewDataProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDATAPROFILE_H
