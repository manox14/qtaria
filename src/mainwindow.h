#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <iostream>
#include "addnewdialog.h"
#include "ariawarapper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread worker;
signals:
    void operate();
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAddNew_triggered();
private:
    Ui::MainWindow *ui;
    addNewDialog *newDialog;
    ariawarapper *dl_handle;
    QTimer *timer;


};

#endif // MAINWINDOW_H
