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
      connect(timer, SIGNAL(timeout()), dl_handle, SLOT(update()));
      timer->start(1000);


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionAddNew_triggered()
{
    newDialog = new addNewDialog;
    newDialog->show();
}
