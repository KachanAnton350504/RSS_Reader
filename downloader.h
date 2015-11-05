#ifndef DOWNLOADER
#define DOWNLOADER

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QEventLoop>
#include <QMessageBox>

class Downloader : public QObject{

    Q_OBJECT

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QEventLoop *loop;
    QByteArray buff;

public:
    virtual  ~Downloader();
    explicit Downloader(QObject *parent = 0);
    void doDownload(QUrl url);
    QByteArray getBuff();
    void clearBuff();

signals:
    void error();

public slots:
    void replyFinished(QNetworkReply *reply);
    void errorDownload();
};

#endif // DOWNLOADER