#ifndef ARIAWARAPPER_H
#define ARIAWARAPPER_H
#include<aria2/aria2.h>
#include <QObject>
#include<iostream>

int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event, const aria2::A2Gid gid, void* userData);

class ariawarapper : public QObject
{
    Q_OBJECT
public:
    explicit ariawarapper(QObject *parent=0);
    aria2::Session* session;
    aria2::SessionConfig config;
    std::vector<std::string> url;
    aria2::KeyVals options;
    aria2::GlobalStat gstat;

signals:


public slots:
    void update();
};

#endif // ARIAWARAPPER_H
