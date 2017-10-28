#include "addnewdialog.h"
#include "ui_addnewdialog.h"
#include <QFileDialog>
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

void addNewDialog::on_addBtn_clicked()
{
    QString address,fileLocation;
    address = ui->addressBox->text();
    fileLocation = ui->locationBox->text();
}

void addNewDialog::on_locationBtn_clicked()
{
    QString saveLocation = QFileDialog::getSaveFileName(this,
            tr("Save Location"), "",
            tr("All Files (*)"));
    ui->locationBox->setText(saveLocation);
}
