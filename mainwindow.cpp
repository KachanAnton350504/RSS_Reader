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
    ui->webView->load(QUrl(item->text(2)));
    ui->webView->show();
    ui->deleteButton->setEnabled(true);
}

void MainWindow::fetch()
{    
    QUrl url(ui->lineEdit->text());
    if (!url.isValid())
    {
        QMessageBox::information(this, "Warning!!!", "Вы не ввели адрес канала");
        return;
    }
    if(saver.isContain(url.toString()))
    {
        QMessageBox::information(this, "Warning!!!", "Канал уже существует в вашем списке");
    }
    else
    {
        d.doDownload(url);
        saver.addLink(url.toString());
        parseXml(url.toString());
    }
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
    QTreeWidgetItem *itm = ui->treeWidget->currentItem();
    itm->setHidden(true);
    ui->deleteButton->setEnabled(false);
    QString str = ui->treeWidget->currentItem()->text(1);
    saver.deleteFileFeed(str);
}

void MainWindow::viewFeeds()
{
    QUrl url;
    QStringList listUrl = saver.readLink();
    if(!listUrl.empty())
    {
        QStringList::iterator it = listUrl.begin();
        for(; it != listUrl.end(); ++it)
        {
            url = *it;
            if (!url.isValid())
            {
                QMessageBox::information(this, "Warning!!!", "Ошибка адреса канала");
                return;
            }
            d.doDownload(url);
            parseXml(url.toString());
        }
    }
}


void MainWindow::updateFeed()
{
    ui->treeWidget->clear();
    viewFeeds();
    ui->deleteButton->setEnabled(false);
    ui->webView->close();
}