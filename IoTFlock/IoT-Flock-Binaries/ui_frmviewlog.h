/********************************************************************************
** Form generated from reading UI file 'frmviewlog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMVIEWLOG_H
#define UI_FRMVIEWLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmViewLog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *txtLog;

    void setupUi(QDialog *frmViewLog)
    {
        if (frmViewLog->objectName().isEmpty())
            frmViewLog->setObjectName(QString::fromUtf8("frmViewLog"));
        frmViewLog->resize(498, 467);
        verticalLayout = new QVBoxLayout(frmViewLog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtLog = new QTextEdit(frmViewLog);
        txtLog->setObjectName(QString::fromUtf8("txtLog"));

        verticalLayout->addWidget(txtLog);


        retranslateUi(frmViewLog);

        QMetaObject::connectSlotsByName(frmViewLog);
    } // setupUi

    void retranslateUi(QDialog *frmViewLog)
    {
        frmViewLog->setWindowTitle(QApplication::translate("frmViewLog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmViewLog: public Ui_frmViewLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMVIEWLOG_H
