/********************************************************************************
** Form generated from reading UI file 'topics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPICS_H
#define UI_TOPICS_H

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

class Ui_Topics
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txtTopic;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSave;
    QPushButton *btnCancel;

    void setupUi(QDialog *Topics)
    {
        if (Topics->objectName().isEmpty())
            Topics->setObjectName(QString::fromUtf8("Topics"));
        Topics->resize(440, 150);
        verticalLayout = new QVBoxLayout(Topics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Topics);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        txtTopic = new QLineEdit(Topics);
        txtTopic->setObjectName(QString::fromUtf8("txtTopic"));

        horizontalLayout_2->addWidget(txtTopic);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnSave = new QPushButton(Topics);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnCancel = new QPushButton(Topics);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Topics);

        QMetaObject::connectSlotsByName(Topics);
    } // setupUi

    void retranslateUi(QDialog *Topics)
    {
        Topics->setWindowTitle(QApplication::translate("Topics", "Topic", nullptr));
        label->setText(QApplication::translate("Topics", "Topic", nullptr));
        btnSave->setText(QApplication::translate("Topics", "Save", nullptr));
        btnCancel->setText(QApplication::translate("Topics", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Topics: public Ui_Topics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPICS_H
