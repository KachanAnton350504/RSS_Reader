#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{   
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDeleteButton()
{
    ui->deleteButton->setEnabled(true);
}

void MainWindow::timer_overflow()
{
    updateFeed();
}

void MainWindow::itemActivated(QTreeWidgetItem * item)
{
   
}

void MainWindow::fetch()
{    
   
}

void MainWindow::parseXml(QString urlString)
{
   xml.clear();
   xml.addData(d.getBuff());
   d.clearBuff();
   while (!xml.atEnd())
   {
        xml.readNext();
        if (xml.isStartElement())
        {
            if (xml.name() == "item")
            {
                if (titleString!="")
                {
                    feed = new QTreeWidgetItem;
                    feed->setText(0, titleString);
                    feed->setText(1,urlString);
                    feed->setText(2, linkString);
                    ui->treeWidget->addTopLevelItem(feed);
                }
                linkString.clear();
                titleString.clear();
                dateString.clear();
           }
           currentTag = xml.name().toString();
        }
        else if (xml.isEndElement()) {
            if (xml.name() == "item") {
                QTreeWidgetItem *item = new QTreeWidgetItem(feed);
                item->setText(0, titleString);
                item->setText(1, dateString);
                item->setText(2, linkString);
                ui->treeWidget->addTopLevelItem(item);
                titleString.clear();
                linkString.clear();
                dateString.clear();
           }
       }
       else if (xml.isCharacters() && !xml.isWhitespace())
       {
            if (currentTag == "title")
            {
                titleString += xml.text().toString();
            }
            else if (currentTag == "link")
            {
                linkString += xml.text().toString();
            }
            else if (currentTag == "pubDate")
            {
                dateString += xml.text().toString();
            }
      }
    }
}

void MainWindow::deleteFeed()
{
    
}

void MainWindow::viewFeeds()
{
   
}


void MainWindow::updateFeed()
{
    
}