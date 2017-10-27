#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connected = false;
    //setup websocket
    connect(&myconnection,&QWebSocket::connected,this,&MainWindow::onConnected);
    myconnection.open(QUrl(QStringLiteral("ws://localhost:6800/jsonrpc")));
    qDebug("DEBUG:1");

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

void MainWindow::onConnected() {
    qDebug("connected");
    connect(&myconnection, &QWebSocket::textMessageReceived,
                this, &MainWindow::onEventRecived);
    myconnection.sendTextMessage(QStringLiteral("Hello, world!"));

}

void MainWindow::onEventRecived(QString event) {
    qDebug(event.toLatin1());

}
