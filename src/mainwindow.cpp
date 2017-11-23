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
      connect(dl_handle,&ariawarapper::downloadStatPerItem,this,&MainWindow::downloadStatPerItem,Qt::BlockingQueuedConnection);
      connect(dl_handle,&ariawarapper::finishAddNew,this,&MainWindow::finishAddNew);
      connect(this,&MainWindow::addNewDownload, dl_handle,&ariawarapper::addNewDownload);
      for(int i = 0; i<10; i++) {
          objectHolder * temp_objh = new objectHolder(this);
          ui->verticalLayout_4->addWidget(temp_objh->groupw,0,Qt::AlignTop);
          list_of_objholder.prepend(temp_objh);
      }

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionAddNew_triggered()
{
    newDialog = new addNewDialog(this);
    newDialog->show();

}
void MainWindow::globalDownloadStat(int inactive, int active, int gdl, int gup)
{
    QString message = QString("Inactive:%1 Active:%2 Speed down:%3KB/s up:%4KB/s").arg(inactive).arg(active).arg(gdl/1024).arg(gup/1024);
    statusBar()->showMessage(message);
}
void MainWindow::downloadStatPerItem(uint id, int completed, int total,int perDl, int perUp)
{
    objectHolder * temp_objh = dlList.value(id); //take out one item from list
    int percentage;
    if(total == 0 || total == -1) {
        std::cout<<"error"<<total;
        return;
    }
    else if(total == -2 ) {
        percentage = 100;
    } else {
        percentage = completed * 100 / total;
    }
    QString message = QString("ID %1 Downloaded:%2|%3[ %6% ] Speed D%4KB/s U%5KB/s").arg(id).arg(completed).arg(total).arg(perDl).arg(perUp).arg(percentage);
    temp_objh->info->setText(message);
}
void MainWindow::emitAddNewDownload(QString url,QString location)
{
    //        http://speed.hetzner.de/100MB.bin
    //QString url = "  http://ipv4.download.thinkbroadband.com/5MB.zip  ";

    timer->start(100);
    dl_handle->addNewDownload(url, location); //emit addNewDownload(url, location);
}
void MainWindow::finishAddNew(uint fid)
{

    if (fid == 0) {
        std::cout<<"error";
        return;
    }
    objectHolder * temp_objh;
    if(list_of_objholder.isEmpty()) {
        dlList.insert(fid, new objectHolder(this));
        temp_objh = dlList.value(fid);
        ui->verticalLayout_4->addWidget(temp_objh->groupw,0,Qt::AlignTop);
    } else {
        temp_objh = list_of_objholder.takeLast();
        dlList.insert(fid, temp_objh);
    }
    temp_objh->activate();

}
