#ifndef SAVER
#define SAVER

#include <QFile>
#include <QMessageBox>
#include <QUrl>
#include <QTextStream>

class Saver : public QObject
{
    Q_OBJECT

private:
    QFile file;

public:
    explicit Saver(QObject *parent = 0);
    void addLink(QString str);
    QStringList readLink();
    bool isContain(QString str);
    void deleteFileFeed(QString str);
};

#endif