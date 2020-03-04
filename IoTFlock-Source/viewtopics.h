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
#ifndef VIEWTOPICS_H
#define VIEWTOPICS_H
#include<constants.h>
#include <QDialog>
#include<qmessagebox.h>

namespace Ui {
class ViewTopics;
}

class ViewTopics : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTopics(QWidget *parent = nullptr);
    ~ViewTopics();
    Constants  _constants;
    QMessageBox msgBox;

private slots:
    void on_btnNewTopic_clicked();
    void deleteRow();
    void editRow();
    void bindData();

private:
    Ui::ViewTopics *ui;


    enum Colum
    {
        ID,
        TOPIC_LIST
    };
};

#endif // VIEWTOPICS_H
