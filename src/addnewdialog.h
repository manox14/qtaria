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

private:
    Ui::addNewDialog *ui;
};

#endif // ADDNEWDIALOG_H
