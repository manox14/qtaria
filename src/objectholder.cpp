#include "objectholder.h"

objectHolder::objectHolder(QWidget * parent)
{
        if(!objectHolder::count){
            std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
            objectHolder::count++;
        }
        holder = new QHBoxLayout(parent);
        info = new QLabel(parent);
        play_btn = new QPushButton(parent);
        groupw = new QWidget(parent);
        groupw->setGeometry(0,0,10,40);
        groupw->setStyleSheet("background-color:black;");

        play_btn->setText(QString("Play bitch"));
        info->setText(QString("OK! i will download"));
        holder->setSpacing(0);
        //temp_objh->holder->setMargin(0);
        holder->addWidget(info);
        holder->addSpacerItem(new QSpacerItem(10,10,QSizePolicy::Expanding));
        holder->addWidget(play_btn);
        groupw->setLayout(holder);
}
int objectHolder::count = 0;
