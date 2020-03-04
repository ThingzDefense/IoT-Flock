/********************************************************************************
** Form generated from reading UI file 'timeprofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEPROFILE_H
#define UI_TIMEPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeProfile
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QLineEdit *txtProfileName;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *rbPeriodic;
    QRadioButton *rbEventDriven;
    QGroupBox *gbPeriodic;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *sbPeriodicInterval;
    QLabel *label_3;
    QGroupBox *gbEventDriven;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpinBox *sbEventRandomFrom;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpinBox *sbEventRandomTo;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblLamda;
    QSpinBox *sbEventValue;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *TimeProfile)
    {
        if (TimeProfile->objectName().isEmpty())
            TimeProfile->setObjectName(QString::fromUtf8("TimeProfile"));
        TimeProfile->resize(366, 318);
        QFont font;
        font.setPointSize(9);
        TimeProfile->setFont(font);
        verticalLayout = new QVBoxLayout(TimeProfile);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(TimeProfile);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        txtProfileName = new QLineEdit(TimeProfile);
        txtProfileName->setObjectName(QString::fromUtf8("txtProfileName"));

        horizontalLayout_9->addWidget(txtProfileName);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rbPeriodic = new QRadioButton(TimeProfile);
        rbPeriodic->setObjectName(QString::fromUtf8("rbPeriodic"));
        rbPeriodic->setCheckable(true);
        rbPeriodic->setChecked(true);

        horizontalLayout_7->addWidget(rbPeriodic);

        rbEventDriven = new QRadioButton(TimeProfile);
        rbEventDriven->setObjectName(QString::fromUtf8("rbEventDriven"));

        horizontalLayout_7->addWidget(rbEventDriven);


        verticalLayout->addLayout(horizontalLayout_7);

        gbPeriodic = new QGroupBox(TimeProfile);
        gbPeriodic->setObjectName(QString::fromUtf8("gbPeriodic"));
        gbPeriodic->setCheckable(false);
        gbPeriodic->setChecked(false);
        horizontalLayout_3 = new QHBoxLayout(gbPeriodic);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(gbPeriodic);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        sbPeriodicInterval = new QSpinBox(gbPeriodic);
        sbPeriodicInterval->setObjectName(QString::fromUtf8("sbPeriodicInterval"));
        sbPeriodicInterval->setMaximum(9999);

        horizontalLayout_2->addWidget(sbPeriodicInterval);

        label_3 = new QLabel(gbPeriodic);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(gbPeriodic);

        gbEventDriven = new QGroupBox(TimeProfile);
        gbEventDriven->setObjectName(QString::fromUtf8("gbEventDriven"));
        gbEventDriven->setCheckable(false);
        gbEventDriven->setChecked(false);
        layoutWidget = new QWidget(gbEventDriven);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 30, 151, 26));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        sbEventRandomFrom = new QSpinBox(layoutWidget);
        sbEventRandomFrom->setObjectName(QString::fromUtf8("sbEventRandomFrom"));
        sbEventRandomFrom->setMaximum(9999);

        horizontalLayout_4->addWidget(sbEventRandomFrom);

        layoutWidget1 = new QWidget(gbEventDriven);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(170, 30, 141, 26));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        sbEventRandomTo = new QSpinBox(layoutWidget1);
        sbEventRandomTo->setObjectName(QString::fromUtf8("sbEventRandomTo"));
        sbEventRandomTo->setMaximum(9999);

        horizontalLayout_5->addWidget(sbEventRandomTo);

        layoutWidget2 = new QWidget(gbEventDriven);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(310, 31, 63, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblLamda = new QLabel(layoutWidget2);
        lblLamda->setObjectName(QString::fromUtf8("lblLamda"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        lblLamda->setFont(font1);

        horizontalLayout->addWidget(lblLamda);

        sbEventValue = new QSpinBox(layoutWidget2);
        sbEventValue->setObjectName(QString::fromUtf8("sbEventValue"));

        horizontalLayout->addWidget(sbEventValue);


        verticalLayout->addWidget(gbEventDriven);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        btnSave = new QPushButton(TimeProfile);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout_8->addWidget(btnSave);

        btnCancel = new QPushButton(TimeProfile);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_8->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(TimeProfile);

        QMetaObject::connectSlotsByName(TimeProfile);
    } // setupUi

    void retranslateUi(QDialog *TimeProfile)
    {
        TimeProfile->setWindowTitle(QApplication::translate("TimeProfile", "Time Profile", nullptr));
        label->setText(QApplication::translate("TimeProfile", "Profile Name", nullptr));
        rbPeriodic->setText(QApplication::translate("TimeProfile", "Peroidic", nullptr));
        rbEventDriven->setText(QApplication::translate("TimeProfile", "Random", nullptr));
        gbPeriodic->setTitle(QApplication::translate("TimeProfile", "Periodic", nullptr));
        label_2->setText(QApplication::translate("TimeProfile", "Interval (sec)", nullptr));
        label_3->setText(QString());
        gbEventDriven->setTitle(QApplication::translate("TimeProfile", "Random", nullptr));
        label_4->setText(QApplication::translate("TimeProfile", "min (sec)", nullptr));
        label_5->setText(QApplication::translate("TimeProfile", "max (sec)", nullptr));
        lblLamda->setText(QApplication::translate("TimeProfile", "\316\273", nullptr));
        btnSave->setText(QApplication::translate("TimeProfile", "Save", nullptr));
        btnCancel->setText(QApplication::translate("TimeProfile", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeProfile: public Ui_TimeProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEPROFILE_H
