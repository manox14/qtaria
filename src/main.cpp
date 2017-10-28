#include "mainwindow.h"
#include "ariawarapper.h"
#include <QApplication>
#include <QThreadStorage>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

