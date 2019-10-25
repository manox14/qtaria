#include "addnewdialog.h"
#include "ui_addnewdialog.h"
#include <QFileDialog>
addNewDialog::addNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewDialog)
{
    ui->setupUi(this);
    //p = parent;
    p = (MainWindow *)parent;
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
    p->emitAddNewDownload(address, fileLocation);
}

void addNewDialog::on_locationBtn_clicked()
{
    QString saveLocation = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                             "",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks
                                                             );
    ui->locationBox->setText(saveLocation);
}
