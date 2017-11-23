#include "objectholder.h"

objectHolder::objectHolder(QWidget * parent ):

    QObject(parent)
{
        holder = new QHBoxLayout(parent);
        info = new QLabel(parent);
        play_pause_btn = new QPushButton(parent);
        stop_btn = new QPushButton(parent);
        groupw = new QWidget(parent);
        //groupw->setGeometry(0,0,10,40);

        play_pause_btn->setText(QString("pause"));
        stop_btn->setText(QString("stop"));
#ifdef QT_DEBUG
        info->setText(QString("ID %1").arg(count));
#endif
        holder->setSpacing(0);
        //temp_objh->holder->setMargin(0);
        holder->addWidget(info);
        holder->addSpacerItem(new QSpacerItem(10,10,QSizePolicy::Expanding));
        holder->addWidget(play_pause_btn);
        holder->addWidget(stop_btn);
        groupw->setLayout(holder);

        play_pause_btn->hide();
        stop_btn->hide();

        if(!objectHolder::count){
            default_style = QString("background-color:rgb(171, 194, 233);");
            groupw->setStyleSheet(default_style);
            objectHolder::count++;
            return;
        }
        if(objectHolder::count%2){
            default_style = QString("background-color: rgb(214, 206, 255);");
            groupw->setStyleSheet(default_style);
        } else {
            default_style = QString("background-color:rgb(171, 194, 233);");
            groupw->setStyleSheet(default_style);
        }
        objectHolder::count++;
}

void objectHolder::activate() {
    play_pause_btn->show();
    connect(play_pause_btn,&QPushButton::clicked,this,&objectHolder::btn_click_play_pause);
    stop_btn->show();
    connect(stop_btn,&QPushButton::clicked,this,&objectHolder::btn_click_stop);

}
void objectHolder::btn_click_play_pause() {
  std::cout<<"play pause";
  //play btn changes from n to pause
}
void objectHolder::btn_click_stop() {
    std::cout<<"stop";
    //stop btn changes from n to del
}

int objectHolder::count = 0;
