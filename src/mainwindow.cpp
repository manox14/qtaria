#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aria2::libraryInit();


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

