/********************************************************************************
** Form generated from reading UI file 'viewtopics.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTOPICS_H
#define UI_VIEWTOPICS_H

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

class Ui_ViewTopics
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnNewTopic;
    QTableWidget *tableWidget;

    void setupUi(QDialog *ViewTopics)
    {
        if (ViewTopics->objectName().isEmpty())
            ViewTopics->setObjectName(QString::fromUtf8("ViewTopics"));
        ViewTopics->resize(630, 280);
        verticalLayout = new QVBoxLayout(ViewTopics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ViewTopics);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnNewTopic = new QPushButton(ViewTopics);
        btnNewTopic->setObjectName(QString::fromUtf8("btnNewTopic"));

        horizontalLayout->addWidget(btnNewTopic);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(ViewTopics);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(ViewTopics);

        QMetaObject::connectSlotsByName(ViewTopics);
    } // setupUi

    void retranslateUi(QDialog *ViewTopics)
    {
        ViewTopics->setWindowTitle(QApplication::translate("ViewTopics", "Topics", nullptr));
        label->setText(QApplication::translate("ViewTopics", "Topics are used in MQTT publish/subscribe requests", nullptr));
        btnNewTopic->setText(QApplication::translate("ViewTopics", "+Create New Topic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewTopics: public Ui_ViewTopics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTOPICS_H
