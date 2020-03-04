/********************************************************************************
** Form generated from reading UI file 'viewtimeprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTIMEPROFILE_H
#define UI_VIEWTIMEPROFILE_H

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

class Ui_ViewTimeProfile
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNewTimeProfile;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ViewTimeProfile)
    {
        if (ViewTimeProfile->objectName().isEmpty())
            ViewTimeProfile->setObjectName(QString::fromUtf8("ViewTimeProfile"));
        ViewTimeProfile->resize(630, 280);
        verticalLayout = new QVBoxLayout(ViewTimeProfile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ViewTimeProfile);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnNewTimeProfile = new QPushButton(ViewTimeProfile);
        btnNewTimeProfile->setObjectName(QString::fromUtf8("btnNewTimeProfile"));

        horizontalLayout->addWidget(btnNewTimeProfile);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(ViewTimeProfile);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ViewTimeProfile);

        QMetaObject::connectSlotsByName(ViewTimeProfile);
    } // setupUi

    void retranslateUi(QDialog *ViewTimeProfile)
    {
        ViewTimeProfile->setWindowTitle(QApplication::translate("ViewTimeProfile", "Time Profile", nullptr));
        label->setText(QApplication::translate("ViewTimeProfile", "Time profile tells device when to send data. It can be priodic or random.", nullptr));
        btnNewTimeProfile->setText(QApplication::translate("ViewTimeProfile", "+Create New Time Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewTimeProfile: public Ui_ViewTimeProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTIMEPROFILE_H
