/********************************************************************************
** Form generated from reading UI file 'frmkeyvalue.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMKEYVALUE_H
#define UI_FRMKEYVALUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrmKeyValue
{
public:
    QTableWidget *tbWidgetFrmKey;
    QPushButton *btnAddFrmKey;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *OK;
    QPushButton *Cancel;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txtFrmKeyParameter;
    QLabel *label_2;
    QComboBox *cmbFrmKeyValue;

    void setupUi(QDialog *FrmKeyValue)
    {
        if (FrmKeyValue->objectName().isEmpty())
            FrmKeyValue->setObjectName(QString::fromUtf8("FrmKeyValue"));
        FrmKeyValue->resize(424, 331);
        tbWidgetFrmKey = new QTableWidget(FrmKeyValue);
        tbWidgetFrmKey->setObjectName(QString::fromUtf8("tbWidgetFrmKey"));
        tbWidgetFrmKey->setGeometry(QRect(30, 110, 361, 181));
        btnAddFrmKey = new QPushButton(FrmKeyValue);
        btnAddFrmKey->setObjectName(QString::fromUtf8("btnAddFrmKey"));
        btnAddFrmKey->setGeometry(QRect(90, 80, 80, 23));
        layoutWidget = new QWidget(FrmKeyValue);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 300, 361, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        OK = new QPushButton(layoutWidget);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout_2->addWidget(OK);

        Cancel = new QPushButton(layoutWidget);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        horizontalLayout_2->addWidget(Cancel);

        widget = new QWidget(FrmKeyValue);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(21, 21, 371, 54));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txtFrmKeyParameter = new QLineEdit(widget);
        txtFrmKeyParameter->setObjectName(QString::fromUtf8("txtFrmKeyParameter"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtFrmKeyParameter);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        cmbFrmKeyValue = new QComboBox(widget);
        cmbFrmKeyValue->setObjectName(QString::fromUtf8("cmbFrmKeyValue"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cmbFrmKeyValue);


        retranslateUi(FrmKeyValue);

        QMetaObject::connectSlotsByName(FrmKeyValue);
    } // setupUi

    void retranslateUi(QDialog *FrmKeyValue)
    {
        FrmKeyValue->setWindowTitle(QApplication::translate("FrmKeyValue", "Dialog", nullptr));
        btnAddFrmKey->setText(QApplication::translate("FrmKeyValue", "Add", nullptr));
        OK->setText(QApplication::translate("FrmKeyValue", "OK", nullptr));
        Cancel->setText(QApplication::translate("FrmKeyValue", "Cancel", nullptr));
        label->setText(QApplication::translate("FrmKeyValue", "Parameter", nullptr));
        label_2->setText(QApplication::translate("FrmKeyValue", "Value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmKeyValue: public Ui_FrmKeyValue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMKEYVALUE_H
