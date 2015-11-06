#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QXmlStreamReader>
#include <QList>
#include <QTimer>
#include "downloader.h"
#include "saver.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void parseXml(QString urlString);
    void viewFeeds();
    QTimer *timer;


public slots:
     void fetch();
     void itemActivated(QTreeWidgetItem * item);
     void deleteFeed();
     void onDeleteButton();
     void updateFeed();
     void timer_overflow();

private:
    Ui::MainWindow *ui;
    QTreeWidgetItem *feed;
    QString currentTag;
    QString linkString;
    QString titleString;
    QString dateString;
    QUrl urlString;
    Downloader d;
    QXmlStreamReader xml;
    Saver saver;
};

#endif