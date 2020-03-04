/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2019 IRIL Lab, KICS, UET Lahore <iril@kics.edu.pk>       *
 *                                                                         *
 *  This file is part of IRIL Advanced Data Generator.                     *                                         *
 *                                                                         *
 *  IRIL Advanced Data Generator is free software: you can redistribute    *
 *  it and/or modify it under the terms of the GNU General Public License  *
 *  as published by the Free Software Foundation, version 3 of the License.*
 *                                                                         *
 *                                                                         *
 *  IRIL Advanced Data Generator is distributed in the hope that it will   *
 *  be useful, but WITHOUT ANY WARRANTY; without even the implied warranty *
 *  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the        *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with IRIL Advanced Data Generator.                               *
 *  If not, see <http://www.gnu.org/licenses/>.                            *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef FRMNEWDEVICE_H
#define FRMNEWDEVICE_H
#include<QString>
#include<objdevice.h>
#include <QDialog>
#include<qmessagebox.h>

namespace Ui {
class frmnewDevice;
}

class frmnewDevice : public QDialog
{
    Q_OBJECT

public:
    explicit frmnewDevice(QWidget *parent = nullptr, QString _FormType = "SAVE", int _id = -1);
    ~frmnewDevice();

    int id;
       QString FormType;
      objDevice _objDevice;

       void FillFormData();
       void SetFormLayout();
       void ClearForm();

       void Save();
       void Edit();
       void Update();
       //void deleteChildData();

       void fillSelectTemplateDropdown();
       void fillProfileDropdown();
       void fillTimeProfileDropdown();
       void fillDataProfileDropdown();
       void fillTopicDropdown();

       void fillForm();
       void fillTbWidgetMQTTSubscribe();
       void fillTbWidgetMQTTPublish();
       void fillTbWidgetCoap();
       void fillTbWidgetHttp();

       void layoutTbWidgetMQTTPublish();
       void layoutTbWidgetMQTTSubscribe();
       void layoutTbWidgetCoap();
       void layoutTbWidgetHttp();

       bool validateForm();



   private slots:

       void on_btnCreate_clicked();

       void on_btnClose_clicked();

   /*
       void on_cmbSubscribeTopic_currentIndexChanged(const QString &arg1);

       void on_cmbMQTTPublishDataProfile_currentIndexChanged(const QString &arg1);

       void on_cmbMQTTPublishTimeProfile_currentIndexChanged(const QString &arg1); */


       void removeSubscribeRow();
       void removePublishRow();
       void removeCoapRow();
       void removeHttpRow();

       void addNewTopic();
       void addNewDataProfile();
       void addNewTimeProfile();

       void on_btnAddSubscribeTopic_clicked();
       void on_btnMQTTPublish_clicked();
       void on_btnCoapAdd_clicked();
       void on_btnHttpAdd_clicked();


       void on_btnAdMQTTPublishTopic_clicked();

       void on_btnMQTTPublishDataProfile_clicked();

       void on_btnMQTTPublishTimeProfile_clicked();

       void on_btnAdMQTTSubscribeTopic_clicked();

       void on_btnAddCoapTimeProfile_clicked();

       void on_btnAddCoapDataProfile_clicked();

       void on_btnAddHttpTimeProfile_clicked();

       void on_btnAddHttpDataProfile_clicked();


       //bool isLoadingDone = false;
       void on_cmbSelectTemplate_currentIndexChanged(int index);

private:
    Ui::frmnewDevice *ui;
    QString _FormType;
};

#endif // FRMNEWDEVICE_H
