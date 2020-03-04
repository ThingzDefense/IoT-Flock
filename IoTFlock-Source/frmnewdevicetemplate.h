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
#ifndef FRMNEWDEVICETEMPLATE_H
#define FRMNEWDEVICETEMPLATE_H
#include<constants.h>
#include <QDialog>
#include<objdevice.h>
#include<qmessagebox.h>
namespace Ui {
class frmNewDeviceTemplate;
}

class frmNewDeviceTemplate : public QDialog
{
    Q_OBJECT
QMessageBox msgBox;
public:
    //explicit frmNewDeviceTemplate(QWidget *parent = nullptr);
    explicit frmNewDeviceTemplate(QWidget *parent = nullptr,QString _FormType = "SAVE", int _id = -1);
    ~frmNewDeviceTemplate();
    Constants _constants;

    int id;
    QString FormType;
    objDevice _objDevice;
    QString parameterValueWithID;

    void FillFormData();
    void SetFormLayout();
    void ClearForm();

    void Save();
    void Edit();
    void Update();
    //void deleteChildData();

    void BindData();
    void BindTopicDropdown();
    void BindDataProfileDropdown();
    void BindTimeProfileDropdown();
    void BindTemplatesDropdown();

    void BindForm();
    void BindMQTTSubscribeGrid();
    void BindMQTTPublishGrid();
    void BindCoapGrid();
    void BindHttpGrid();

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

    void on_cmbTemplates_currentIndexChanged(int index);

    void on_cmbProtocol_currentIndexChanged(const QString &arg1);

    void on_cmbCoapCommand_currentIndexChanged(const QString &arg1);

    void on_cmbHttpCommand_currentIndexChanged(const QString &arg1);

    void on_gbBrookerAuthentication_clicked();

    void on_gbIsAttackingEntity_toggled(bool arg1);

    void on_gbIsAttackingEntity_clicked(bool checked);

    void on_cmbTemplates_activated(const QString &arg1);

    void on_cmbTemplates_currentIndexChanged(const QString &arg1);

    void on_cmbAttackType_currentIndexChanged(const QString &arg1);

private:
    Ui::frmNewDeviceTemplate *ui;
    QString _FormType;
   // int _id;
    int GetQoS(); 
    enum Colum
    {
        topic_List,
        QoS,
        dataFrame,
        timeFrame
    };

    QString topicList;
};

#endif // FRMNEWDEVICETEMPLATE_H
