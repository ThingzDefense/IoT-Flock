/********************************************************************************
** Form generated from reading UI file 'frmnewdevicetemplateview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMNEWDEVICETEMPLATEVIEW_H
#define UI_FRMNEWDEVICETEMPLATEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmNewDeviceTemplateView
{
public:
    QTableWidget *tbWidegtViewDB;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *frmNewDeviceTemplateView)
    {
        if (frmNewDeviceTemplateView->objectName().isEmpty())
            frmNewDeviceTemplateView->setObjectName(QString::fromUtf8("frmNewDeviceTemplateView"));
        frmNewDeviceTemplateView->resize(630, 280);
        tbWidegtViewDB = new QTableWidget(frmNewDeviceTemplateView);
        tbWidegtViewDB->setObjectName(QString::fromUtf8("tbWidegtViewDB"));
        tbWidegtViewDB->setGeometry(QRect(9, 42, 612, 229));
        layoutWidget = new QWidget(frmNewDeviceTemplateView);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 606, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(frmNewDeviceTemplateView);

        QMetaObject::connectSlotsByName(frmNewDeviceTemplateView);
    } // setupUi

    void retranslateUi(QDialog *frmNewDeviceTemplateView)
    {
        frmNewDeviceTemplateView->setWindowTitle(QApplication::translate("frmNewDeviceTemplateView", "Device Template", nullptr));
        label->setText(QApplication::translate("frmNewDeviceTemplateView", "Device templates are created to be used later.", nullptr));
        pushButton->setText(QApplication::translate("frmNewDeviceTemplateView", "+New Device Template", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmNewDeviceTemplateView: public Ui_frmNewDeviceTemplateView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMNEWDEVICETEMPLATEVIEW_H
