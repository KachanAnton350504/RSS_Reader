#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    loop = new QEventLoop();
    connect (manager, SIGNAL(finished(QNetworkReply*)), loop, SLOT(quit()));
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    connect(this,SIGNAL(error()),this, SLOT(errorDownload()));
}

void Downloader::doDownload(QUrl url)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    manager->get(request);
    loop->exec();
}

void Downloader::replyFinished (QNetworkReply *reply)
{    
    if(reply->error() != QNetworkReply::NoError) {
        emit error();
    }
    else {
            buff = reply->readAll();
    }
    reply->deleteLater();
}

Downloader::~Downloader()
{
    manager->deleteLater();
}

QByteArray Downloader::getBuff()
{
    return buff;
}

void Downloader::clearBuff()
{
    buff.clear();
}

void Downloader::errorDownload()
{
    QMessageBox::information(0, "Error", "An error while download is occured");
}
