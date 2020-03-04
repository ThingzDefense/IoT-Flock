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
#ifndef FRMKEYVALUE_H
#define FRMKEYVALUE_H

#include <QDialog>
#include<QString>

namespace Ui {
class FrmKeyValue;
}

class FrmKeyValue : public QDialog
{
    Q_OBJECT

public:
    explicit FrmKeyValue(QWidget *parent = nullptr);
    ~FrmKeyValue();
    void SetLayout();
    void removeRow();
    void BindDataProfileValue();
 QString keyValue,keyValueWithID;
   Ui::FrmKeyValue *ui;
private slots:
    void on_btnAddFrmKey_clicked();

    void on_OK_clicked();

    void on_Cancel_clicked();

private:

};

#endif // FRMKEYVALUE_H
