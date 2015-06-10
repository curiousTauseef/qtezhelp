#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "helpdialog.h"    // INCLUDE THIS FILE FOR HELP

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Help_triggered();

    void on_actionHelp_on_Waveforms_triggered();

private:
    Ui::MainWindow *ui;
    HelpDialog *helpdlg;
    void doHelp(const QString &topic=QString());

};

#endif // MAINWINDOW_H
