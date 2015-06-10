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


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    helpdlg=NULL;        // lazy initialize
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doHelp(const QString &topic)
{
    if (!helpdlg) helpdlg=new HelpDialog("qrc:/help","qrc:/help/help.html",this);
    if (helpdlg) helpdlg->showHelp(topic);  // by default this shows help.html, but if you pass, say, "topic" then it will look for qrc://help/topic.html
    else
    {
        // Feel free to pop up an Oh No message box here!
    }
}

void MainWindow::on_action_Help_triggered()
{
    doHelp();  // default help
}

void MainWindow::on_actionHelp_on_Waveforms_triggered()
{
    doHelp("waveform");  // specific help
}
