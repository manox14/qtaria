#include "ariawarapper.h"
ariawarapper::ariawarapper(QObject *parent)
    :QObject(parent)
{
    aria2::libraryInit();
    qDebug("INITIALIZING");
    config.downloadEventCallback = downloadEventCallback;
    session = aria2::sessionNew(aria2::KeyVals(), config);
    url = {"http://ipv4.download.thinkbroadband.com/5MB.zip"};
    int rv = aria2::addUri(session, nullptr, url, options);

      if(rv < 0) {
        qDebug("Failed to INITIALIZE");
      }
}
void ariawarapper::update()  {
    auto start = std::chrono::steady_clock::now();
      for (;;) {
        int rv = aria2::run(session, aria2::RUN_ONCE);
        if (rv != 1) {
          break;
        }
        // the application can call aria2 API to add URI or query progress
        // here
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
        // Print progress information once per 500ms
        if (count >= 500) {
          start = now;
          aria2::GlobalStat gstat = aria2::getGlobalStat(session);
          std::cerr << "Overall #Active:" << gstat.numActive
                    << " #waiting:" << gstat.numWaiting
                    << " D:" << gstat.downloadSpeed / 1024 << "KiB/s"
                    << " U:" << gstat.uploadSpeed / 1024 << "KiB/s " << std::endl;
          std::vector<aria2::A2Gid> gids = aria2::getActiveDownload(session);
          for (const auto& gid : gids) {
            aria2::DownloadHandle* dh = aria2::getDownloadHandle(session, gid);
            if (dh) {
              std::cerr << "    [" << aria2::gidToHex(gid) << "] "
                        << dh->getCompletedLength() << "/" << dh->getTotalLength()
                        << "(" << (dh->getTotalLength() > 0
                                       ? (100 * dh->getCompletedLength() /
                                          dh->getTotalLength())
                                       : 0)
                        << "%)"
                        << " D:" << dh->getDownloadSpeed() / 1024
                        << "KiB/s, U:" << dh->getUploadSpeed() / 1024 << "KiB/s"
                        << std::endl;
              aria2::deleteDownloadHandle(dh);
            }
          }
        }
      }
      int rv = aria2::sessionFinal(session);
      aria2::libraryDeinit();
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
