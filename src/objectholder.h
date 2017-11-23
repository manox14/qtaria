#ifndef OBJECTHOLDER_H
#define OBJECTHOLDER_H
#include<QWidget>
#include<QLabel>
#include<QHBoxLayout>
#include<QPushButton>
#include<QString>
#include<iostream>
#include<QObject>
class objectHolder : public QObject
{
    Q_OBJECT
public:
    explicit objectHolder(QWidget * parent=nullptr);
    static int count;
    QHBoxLayout *holder;
    QWidget *groupw;
    QLabel *info;
    QPushButton *stop_btn;
    QPushButton *play_pause_btn;
    QString default_style;


    void activate();
    virtual ~objectHolder(){
        objectHolder::count--;
        //free all resource i guess
        /*
        delete holder;
        delete holder;
        delete groupw;
        delete info;
        delete stop_btn;
        delete play_pause_btn;
        */

    }
public slots:
    void btn_click_play_pause();
    void btn_click_stop();

};
#endif // OBJECTHOLDER_H
