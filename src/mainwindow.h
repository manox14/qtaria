#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <QLabel>
#include <QVBoxLayout>
#include <QMap>
#include <iostream>
#include "addnewdialog.h"
#include "ariawarapper.h"
#include <aria2/aria2.h>
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
    void addNewDownload(aria2::A2Gid *id, QString url, QString location);
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
    QMap<uint, QLabel> dlownloadList;
    QLabel *label;
public slots:
    void globalDownloadStat(int inactive, int active, int gdl, int gup);
    void downloadStatPerItem(int id, int completed, int total,int perDl, int perUp); //update download progress to ui


};

#endif // MAINWINDOW_H
