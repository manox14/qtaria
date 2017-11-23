#ifndef OBJECTHOLDER_H
#define OBJECTHOLDER_H
#include<QWidget>
#include<QLabel>
#include<QHBoxLayout>
#include<QPushButton>
#include<iostream>
class objectHolder
{
public:
    static int count;
    QHBoxLayout *holder;
    QWidget *groupw;
    QLabel *info;
    QPushButton *play_btn;
    objectHolder(QWidget * parent);
};
#endif // OBJECTHOLDER_H
