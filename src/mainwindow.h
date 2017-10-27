#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addnewdialog.h"
#include <QUrl>
#include <QDebug>
#include <aria2/aria2.h>


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

private:
    Ui::MainWindow *ui;
    addNewDialog *newDialog;
    aria2::Session* session;

};

#endif // MAINWINDOW_H
