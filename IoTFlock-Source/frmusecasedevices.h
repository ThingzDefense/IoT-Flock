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
#ifndef FRMUSECASEDEVICES_H
#define FRMUSECASEDEVICES_H
#include<QMessageBox>
#include <QDialog>
#include<threadmain.h>

namespace Ui {
class frmUsecaseDevices;
}

class frmUsecaseDevices : public QDialog
{
    Q_OBJECT

public:
    //explicit frmUsecaseDevices(QWidget *parent = nullptr);
    explicit frmUsecaseDevices(QWidget *parent = nullptr, int _useCaseId =0);
    ~frmUsecaseDevices();
    QMessageBox msgBox;
    QString formReply;
    int id;
    int colIP=4;
    QString useCaseName = "";
    ThreadMain threadMain;


    void bindData(int _useCaseId);
    void viewlog();
    void showData();
    void editDevice();
    void deleteDevice();

private slots:

    void on_btnAddNewdevice_clicked();

private:
    Ui::frmUsecaseDevices *ui;
};

#endif // FRMUSECASEDEVICES_H
