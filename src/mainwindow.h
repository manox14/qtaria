#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addnewdialog.h"
#include <QtWebSockets/QtWebSockets>
#include <QUrl>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAddNew_triggered();
    void onConnected();
    void onEventRecived(QString event);

private:
    Ui::MainWindow *ui;
    addNewDialog *newDialog;
    QWebSocket myconnection;
    bool connected;
    //QString address = "wss://echo.websocket.org";

};

#endif // MAINWINDOW_H
