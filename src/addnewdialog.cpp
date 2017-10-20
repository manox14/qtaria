#include "addnewdialog.h"
#include "ui_addnewdialog.h"

addNewDialog::addNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewDialog)
{
    ui->setupUi(this);
}

addNewDialog::~addNewDialog()
{
    delete ui;
}
