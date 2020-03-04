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
#ifndef VIEWTIMEPROFILE_H
#define VIEWTIMEPROFILE_H
#include<constants.h>
#include <QDialog>
#include<qmessagebox.h>
namespace Ui {
class ViewTimeProfile;
}

class ViewTimeProfile : public QDialog
{
    Q_OBJECT
QMessageBox msgBox;
public:
    explicit ViewTimeProfile(QWidget *parent = nullptr);
    ~ViewTimeProfile();
    Constants  _constants;

private slots:
    void on_btnNewTimeProfile_clicked();
    void editRow();
    void deleteRow();
    void bindData();

private:
    Ui::ViewTimeProfile *ui;
    enum Colum
    {
        ID,
        TIME_PROFILE_LIST
    };
};

#endif // VIEWTIMEPROFILE_H
