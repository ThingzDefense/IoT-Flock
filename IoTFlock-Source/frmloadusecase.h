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
#ifndef FRMLOADUSECASE_H
#define FRMLOADUSECASE_H
#include<qmessagebox.h>
#include <QDialog>
#include<constants.h>
namespace Ui {
class frmLoadUseCase;
}

class frmLoadUseCase : public QDialog
{
    Q_OBJECT
QMessageBox msgBox;
public:
    explicit frmLoadUseCase(QWidget *parent = nullptr, QString useCases = "");
    ~frmLoadUseCase();
    Ui::frmLoadUseCase *ui;
    Constants _constants;
    QString formReply;

    int _useCaseId;


private slots:
    void bindData();
    void selectUseCase();
    void deleteUseCase();
    void saveUseCaseXML();
    void on_btnAdNewUseCase_clicked();

private:


    enum Colum
    {
        ID,
        USE_CASE_NAME
    };
};

#endif // FRMLOADUSECASE_H
