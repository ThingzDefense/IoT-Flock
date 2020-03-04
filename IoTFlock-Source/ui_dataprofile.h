/********************************************************************************
** Form generated from reading UI file 'dataprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAPROFILE_H
#define UI_DATAPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataProfile
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QGroupBox *gbRandomValue;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *sbRandomFrom;
    QLabel *label_3;
    QSpinBox *sbRandomTo;
    QGroupBox *gbEndText;
    QLineEdit *txtEndText;
    QGroupBox *gbStartText;
    QLineEdit *txtStartText;
    QWidget *layoutWidget2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *txtProfileName;

    void setupUi(QDialog *DataProfile)
    {
        if (DataProfile->objectName().isEmpty())
            DataProfile->setObjectName(QString::fromUtf8("DataProfile"));
        DataProfile->resize(472, 317);
        layoutWidget = new QWidget(DataProfile);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 280, 451, 25));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        btnSave = new QPushButton(layoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout_9->addWidget(btnSave);

        btnCancel = new QPushButton(layoutWidget);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_9->addWidget(btnCancel);

        gbRandomValue = new QGroupBox(DataProfile);
        gbRandomValue->setObjectName(QString::fromUtf8("gbRandomValue"));
        gbRandomValue->setGeometry(QRect(10, 110, 451, 91));
        gbRandomValue->setCheckable(true);
        gbRandomValue->setChecked(false);
        layoutWidget1 = new QWidget(gbRandomValue);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 31, 431, 56));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        sbRandomFrom = new QSpinBox(layoutWidget1);
        sbRandomFrom->setObjectName(QString::fromUtf8("sbRandomFrom"));
        sbRandomFrom->setMinimum(-1000);
        sbRandomFrom->setMaximum(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, sbRandomFrom);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        sbRandomTo = new QSpinBox(layoutWidget1);
        sbRandomTo->setObjectName(QString::fromUtf8("sbRandomTo"));
        sbRandomTo->setMinimum(-1000);
        sbRandomTo->setMaximum(1000);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbRandomTo);

        gbEndText = new QGroupBox(DataProfile);
        gbEndText->setObjectName(QString::fromUtf8("gbEndText"));
        gbEndText->setGeometry(QRect(10, 210, 451, 61));
        gbEndText->setCheckable(true);
        gbEndText->setChecked(false);
        txtEndText = new QLineEdit(gbEndText);
        txtEndText->setObjectName(QString::fromUtf8("txtEndText"));
        txtEndText->setGeometry(QRect(13, 31, 431, 23));
        gbStartText = new QGroupBox(DataProfile);
        gbStartText->setObjectName(QString::fromUtf8("gbStartText"));
        gbStartText->setGeometry(QRect(10, 40, 451, 61));
        gbStartText->setCheckable(true);
        gbStartText->setChecked(false);
        txtStartText = new QLineEdit(gbStartText);
        txtStartText->setObjectName(QString::fromUtf8("txtStartText"));
        txtStartText->setGeometry(QRect(13, 31, 431, 23));
        layoutWidget2 = new QWidget(DataProfile);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 451, 25));
        formLayout_2 = new QFormLayout(layoutWidget2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        txtProfileName = new QLineEdit(layoutWidget2);
        txtProfileName->setObjectName(QString::fromUtf8("txtProfileName"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, txtProfileName);


        retranslateUi(DataProfile);

        QMetaObject::connectSlotsByName(DataProfile);
    } // setupUi

    void retranslateUi(QDialog *DataProfile)
    {
        DataProfile->setWindowTitle(QApplication::translate("DataProfile", "Data Profile", nullptr));
        btnSave->setText(QApplication::translate("DataProfile", "Save", nullptr));
        btnCancel->setText(QApplication::translate("DataProfile", "Cancel", nullptr));
        gbRandomValue->setTitle(QApplication::translate("DataProfile", "Middle Text (Random Value)", nullptr));
        label_2->setText(QApplication::translate("DataProfile", "min", nullptr));
        label_3->setText(QApplication::translate("DataProfile", "max", nullptr));
        gbEndText->setTitle(QApplication::translate("DataProfile", "End Text", nullptr));
        gbStartText->setTitle(QApplication::translate("DataProfile", "Start Text", nullptr));
        label->setText(QApplication::translate("DataProfile", "Data Profile Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataProfile: public Ui_DataProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPROFILE_H
