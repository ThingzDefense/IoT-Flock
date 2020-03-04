/********************************************************************************
** Form generated from reading UI file 'synattack.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNATTACK_H
#define UI_SYNATTACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SynAttack
{
public:
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QLabel *label_9;
    QSpinBox *spinBox_2;
    QLabel *label_10;
    QLineEdit *lineEdit_7;

    void setupUi(QDialog *SynAttack)
    {
        if (SynAttack->objectName().isEmpty())
            SynAttack->setObjectName(QString::fromUtf8("SynAttack"));
        SynAttack->resize(399, 164);
        label_6 = new QLabel(SynAttack);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 10, 47, 13));
        lineEdit_4 = new QLineEdit(SynAttack);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(110, 10, 191, 20));
        label_7 = new QLabel(SynAttack);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 40, 61, 16));
        lineEdit_5 = new QLineEdit(SynAttack);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(110, 40, 191, 20));
        label_8 = new QLabel(SynAttack);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 70, 61, 16));
        lineEdit_6 = new QLineEdit(SynAttack);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(110, 70, 191, 20));
        label_9 = new QLabel(SynAttack);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 100, 131, 16));
        spinBox_2 = new QSpinBox(SynAttack);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(170, 100, 131, 22));
        label_10 = new QLabel(SynAttack);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 130, 61, 16));
        lineEdit_7 = new QLineEdit(SynAttack);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(110, 130, 191, 20));

        retranslateUi(SynAttack);

        QMetaObject::connectSlotsByName(SynAttack);
    } // setupUi

    void retranslateUi(QDialog *SynAttack)
    {
        SynAttack->setWindowTitle(QApplication::translate("SynAttack", "Dialog", nullptr));
        label_6->setText(QApplication::translate("SynAttack", "Target IP", nullptr));
        label_7->setText(QApplication::translate("SynAttack", "Target Port", nullptr));
        label_8->setText(QApplication::translate("SynAttack", "Delay (ms)", nullptr));
        label_9->setText(QApplication::translate("SynAttack", "No. of Attacking Entities", nullptr));
        label_10->setText(QApplication::translate("SynAttack", "Starting IP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SynAttack: public Ui_SynAttack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNATTACK_H
