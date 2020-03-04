/********************************************************************************
** Form generated from reading UI file 'frmsaveusecase.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSAVEUSECASE_H
#define UI_FRMSAVEUSECASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmSaveUseCase
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txtName;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *frmSaveUseCase)
    {
        if (frmSaveUseCase->objectName().isEmpty())
            frmSaveUseCase->setObjectName(QString::fromUtf8("frmSaveUseCase"));
        frmSaveUseCase->resize(440, 150);
        verticalLayout = new QVBoxLayout(frmSaveUseCase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(frmSaveUseCase);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        txtName = new QLineEdit(frmSaveUseCase);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        horizontalLayout_2->addWidget(txtName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(frmSaveUseCase);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(frmSaveUseCase);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(frmSaveUseCase);

        QMetaObject::connectSlotsByName(frmSaveUseCase);
    } // setupUi

    void retranslateUi(QDialog *frmSaveUseCase)
    {
        frmSaveUseCase->setWindowTitle(QApplication::translate("frmSaveUseCase", "Use Case", nullptr));
        label->setText(QApplication::translate("frmSaveUseCase", "Use Case Name", nullptr));
        btnSave->setText(QApplication::translate("frmSaveUseCase", "Save", nullptr));
        btnCancel->setText(QApplication::translate("frmSaveUseCase", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmSaveUseCase: public Ui_frmSaveUseCase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSAVEUSECASE_H
