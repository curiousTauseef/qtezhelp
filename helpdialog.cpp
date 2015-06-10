/*
 *
 *  This program is Copyright (c) 2015 by Al Williams al.williams@awce.com
 *  All rights reserved.
 *
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */


#include "helpdialog.h"
#include "ui_helpdialog.h"
#include <QSettings>
#include <QFile>
#include <QMessageBox>
#include <QWebFrame>

HelpDialog::HelpDialog(const QString &homedir, const QString &home, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpDialog)
{
    QSettings set;
    topicload.clear();
    ui->setupUi(this);
    homed=homedir;
    homepage=home;
    this->setGeometry((QRect)set.value("Options/helpsize",QRect(0,0,640,480)).toRect());
    on_indexButton_clicked();
}

HelpDialog::~HelpDialog()
{
    QSettings set;
    set.setValue("Options/helpsize",this->geometry());
    delete ui;
}


void HelpDialog::on_indexButton_clicked()
{
    ui->webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);
    ui->webView->page()->settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    QString url=homepage;
    ui->webView->load(QUrl(url));
}

void HelpDialog::on_search_clicked()
{
    if (!ui->webView->findText(ui->searchText->text()))
    {
        QMessageBox dlg;
        dlg.setText("Not found");
        dlg.exec();
    }
}

void HelpDialog::showHelp(const QString &topic)
{
    show();
    on_indexButton_clicked();
    if (topic.isEmpty()) return;
    topicload=homed + "/" + topic + ".html";

}

void HelpDialog::on_webView_loadFinished(bool arg1)
{
    if (!topicload.isEmpty())
    {
        ui->webView->page()->mainFrame()->childFrames().at(1)->load(QUrl(topicload));
        topicload.clear();
    }
}
