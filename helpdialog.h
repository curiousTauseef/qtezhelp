#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(const QString &homedir, const QString &home, QWidget *parent = 0);
    ~HelpDialog();
    void showHelp(const QString &topic=QString());

private slots:

    void on_indexButton_clicked();

    void on_search_clicked();

    void on_webView_loadFinished(bool arg1);

private:
    Ui::HelpDialog *ui;
    QString topicload;
    QString homepage;
    QString homed;
};

#endif // HELPDIALOG_H
