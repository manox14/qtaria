#include "mainwindow.h"
#include <QApplication>
#include <aria2/aria2.h>

int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event, const aria2::A2Gid gid, void* userData);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //setup libaria2
    aria2::libraryInit();
    aria2::Session* session;
    aria2::SessionConfig config;
    config.downloadEventCallback = downloadEventCallback;
    session = aria2::sessionNew(aria2::KeyVals(), config);
    std::vector<std::string> url = {"http://ipv4.download.thinkbroadband.com/5MB.zip"};
    std::cout<<"starting"<<endl;
    aria2::KeyVals options;
      int rv = aria2::addUri(session, nullptr, url, options);
      if(rv < 0) {
        std::cerr << "Failed to add download " << url[0] << std::endl;
      }


    w.show();

    return a.exec();
}

int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event,
                          const aria2::A2Gid gid, void* userData)
{
  switch(event) {
  case aria2::EVENT_ON_DOWNLOAD_COMPLETE:
    std::cerr << "COMPLETE";
    break;
  case aria2::EVENT_ON_DOWNLOAD_ERROR:
    std::cerr << "ERROR";
    break;
  default:
    return 0;
  }
  std::cerr << " [" << aria2::gidToHex(gid) << "] ";
}
