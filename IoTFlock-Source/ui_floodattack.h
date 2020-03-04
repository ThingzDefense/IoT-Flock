/********************************************************************************
** Form generated from reading UI file 'floodattack.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLOODATTACK_H
#define UI_FLOODATTACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_FloodAttack
{
public:
    QSpinBox *spinBox_2;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_9;
    QComboBox *comboBox;
    QLabel *label_11;
    QLineEdit *lineEdit_8;
    QCheckBox *checkBox;

    void setupUi(QDialog *FloodAttack)
    {
        if (FloodAttack->objectName().isEmpty())
            FloodAttack->setObjectName(QString::fromUtf8("FloodAttack"));
        FloodAttack->resize(400, 194);
        spinBox_2 = new QSpinBox(FloodAttack);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(160, 130, 131, 22));
        lineEdit_6 = new QLineEdit(FloodAttack);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(100, 100, 191, 20));
        label_6 = new QLabel(FloodAttack);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 10, 47, 13));
        lineEdit_7 = new QLineEdit(FloodAttack);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 160, 191, 20));
        label_8 = new QLabel(FloodAttack);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 100, 61, 16));
        lineEdit_5 = new QLineEdit(FloodAttack);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(100, 70, 191, 20));
        label_10 = new QLabel(FloodAttack);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 160, 61, 16));
        label_7 = new QLabel(FloodAttack);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 70, 61, 16));
        label_9 = new QLabel(FloodAttack);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 130, 131, 16));
        comboBox = new QComboBox(FloodAttack);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 10, 191, 22));
        label_11 = new QLabel(FloodAttack);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 40, 61, 16));
        lineEdit_8 = new QLineEdit(FloodAttack);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(100, 40, 191, 20));
        checkBox = new QCheckBox(FloodAttack);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(300, 70, 70, 20));

        retranslateUi(FloodAttack);

        QMetaObject::connectSlotsByName(FloodAttack);
    } // setupUi

    void retranslateUi(QDialog *FloodAttack)
    {
        FloodAttack->setWindowTitle(QApplication::translate("FloodAttack", "Dialog", nullptr));
        label_6->setText(QApplication::translate("FloodAttack", "Protocol", nullptr));
        label_8->setText(QApplication::translate("FloodAttack", "Delay (ms)", nullptr));
        label_10->setText(QApplication::translate("FloodAttack", "Starting IP", nullptr));
        label_7->setText(QApplication::translate("FloodAttack", "Target Port", nullptr));
        label_9->setText(QApplication::translate("FloodAttack", "No. of Attacking Entities", nullptr));
        comboBox->setItemText(0, QApplication::translate("FloodAttack", "UDP", nullptr));
        comboBox->setItemText(1, QApplication::translate("FloodAttack", "TCP", nullptr));
        comboBox->setItemText(2, QApplication::translate("FloodAttack", "ICMP", nullptr));

        label_11->setText(QApplication::translate("FloodAttack", "Target IP", nullptr));
        checkBox->setText(QApplication::translate("FloodAttack", "Random", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FloodAttack: public Ui_FloodAttack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLOODATTACK_H
