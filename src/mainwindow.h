#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addnewdialog.h"
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

private:
    Ui::MainWindow *ui;
    addNewDialog *newDialog;

};

#endif // MAINWINDOW_H
