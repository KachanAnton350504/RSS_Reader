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