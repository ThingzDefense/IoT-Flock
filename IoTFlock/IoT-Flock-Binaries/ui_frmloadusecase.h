/********************************************************************************
** Form generated from reading UI file 'frmloadusecase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOADUSECASE_H
#define UI_FRMLOADUSECASE_H

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

class Ui_frmLoadUseCase
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdNewUseCase;
    QTableWidget *tableWidget;

    void setupUi(QDialog *frmLoadUseCase)
    {
        if (frmLoadUseCase->objectName().isEmpty())
            frmLoadUseCase->setObjectName(QString::fromUtf8("frmLoadUseCase"));
        frmLoadUseCase->resize(550, 300);
        verticalLayout = new QVBoxLayout(frmLoadUseCase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frmLoadUseCase);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdNewUseCase = new QPushButton(frmLoadUseCase);
        btnAdNewUseCase->setObjectName(QString::fromUtf8("btnAdNewUseCase"));

        horizontalLayout->addWidget(btnAdNewUseCase);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(frmLoadUseCase);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(frmLoadUseCase);

        QMetaObject::connectSlotsByName(frmLoadUseCase);
    } // setupUi

    void retranslateUi(QDialog *frmLoadUseCase)
    {
        frmLoadUseCase->setWindowTitle(QApplication::translate("frmLoadUseCase", "Use Case", nullptr));
        label->setText(QApplication::translate("frmLoadUseCase", "Here you can view existing use cases", nullptr));
        btnAdNewUseCase->setText(QApplication::translate("frmLoadUseCase", "+New Use Case", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLoadUseCase: public Ui_frmLoadUseCase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOADUSECASE_H
