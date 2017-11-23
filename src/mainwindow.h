#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>
#include <QMap>
#include <QWidget>
#include <iostream>
#include "addnewdialog.h"
#include "ariawarapper.h"
#include <aria2/aria2.h>
#include "objectholder.h"
class addNewDialog;
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread worker;
signals:
    void operate();
    void opdate();
    void addNewDownload( QString url, QString location);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void emitAddNewDownload(QString url,QString location);

private slots:
    void on_actionAddNew_triggered();
private:
    Ui::MainWindow *ui;
    addNewDialog *newDialog;
    ariawarapper *dl_handle;
    QTimer *timer;
    QLabel *label;
    QMap<uint, objectHolder*> dlList;
public slots:
    void globalDownloadStat(int inactive, int active, int gdl, int gup);
    void downloadStatPerItem(uint id, int completed, int total,int perDl, int perUp); //update download progress to ui
    void finishAddNew(uint fid);
    //we are using uint because its closest to aria2::A2Gid and valid for Qmeta stuff
    //do't know it can hod A2Gid value without overflow

};

#endif // MAINWINDOW_H
