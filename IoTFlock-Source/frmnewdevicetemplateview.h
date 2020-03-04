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
#ifndef FRMNEWDEVICETEMPLATEVIEW_H
#define FRMNEWDEVICETEMPLATEVIEW_H
#include<constants.h>
#include <QDialog>
#include<qmessagebox.h>
namespace Ui {
class frmNewDeviceTemplateView;
}

class frmNewDeviceTemplateView : public QDialog
{
    Q_OBJECT
QMessageBox msgBox;
public:
    explicit frmNewDeviceTemplateView(QWidget *parent = nullptr);
    ~frmNewDeviceTemplateView();
     Constants  _constants;
    void fillTbWidgetViewDB();
    void layoutTbWidgetViewDB();



private slots:
    void on_pushButton_clicked();
    void editRecord();
    void deleteRecord();

private:
    Ui::frmNewDeviceTemplateView *ui;

    enum Colum
    {
        ID,
        DEVICENAME,
        DESCRIPTION
    };
};

#endif // FRMNEWDEVICETEMPLATEVIEW_H
