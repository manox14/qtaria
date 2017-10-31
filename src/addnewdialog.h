#ifndef ADDNEWDIALOG_H
#define ADDNEWDIALOG_H

#include <QDialog>

namespace Ui {
class addNewDialog;
}

class addNewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addNewDialog(QWidget *parent = 0);
    ~addNewDialog();

private slots:
    void on_addBtn_clicked();

    void on_locationBtn_clicked();

private:
    Ui::addNewDialog *ui;
};

#endif // ADDNEWDIALOG_H
