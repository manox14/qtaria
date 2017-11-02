#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
      ui->setupUi(this);

      dl_handle = new ariawarapper;
      dl_handle->moveToThread(&worker);
      worker.start();

      timer = new QTimer(this);
      label = new QLabel(this);

      connect(timer, SIGNAL(timeout()), dl_handle, SLOT(update()));
      connect(dl_handle,&ariawarapper::globalDownloadStat,this,&MainWindow::globalDownloadStat);
      connect(dl_handle,&ariawarapper::downloadStatPerItem,this,&MainWindow::downloadStatPerItem);
      connect(this,&MainWindow::addNewDownload, dl_handle,&ariawarapper::addNewDownload);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionAddNew_triggered()
{
    newDialog = new addNewDialog(this);
    newDialog->exec();

}
void MainWindow::globalDownloadStat(int inactive, int active, int gdl, int gup)
{
    QString message = QString("Inactive:%1 Active:%2 Speed down:%3KB/s up:%4KB/s").arg(inactive).arg(active).arg(gdl/1024).arg(gup/1024);
    statusBar()->showMessage(message);
}
void MainWindow::downloadStatPerItem(int id, int completed, int total,int perDl, int perUp)
{
    int percentage = (completed * 100) /total;
    QString message = QString("ID Downloaded:%2|%3[ %6% ] Speed D%4KB/s U%5KB/s").arg(completed).arg(total).arg(perDl).arg(perUp).arg(percentage);
    label->setText(message);
    ui->verticalLayout_2->addWidget(label);
    std::cerr<<percentage;
}
void MainWindow::emitAddNewDownload(QString url,QString location)
{
    //QString url = "http://ipv4.download.thinkbroadband.com/5MB.zip";
    aria2::A2Gid id;
    emit addNewDownload(/*&id,*/url);
    timer->start(100);
}
