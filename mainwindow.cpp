#include <iostream>
#include <qmessagebox.h>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include "udp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(sendWindow.acceptSendButton,SIGNAL(clicked()),this,SLOT(sendFile()));

    listModel = new QStandardItemModel();
    ui->messageListView->setModel(listModel);

    udp = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete udp;
}

void MainWindow::addMessage(QString message){
    QStandardItem* messageItem = new QStandardItem(message);
    listModel->appendRow(messageItem);
}

void MainWindow::on_settingsButton_clicked()
{
    settingsWindow.show();
}

void MainWindow::on_sendButton_clicked()
{
    sendWindow.show();
}

void MainWindow::sendFile()
{
    QString fileName = sendWindow.fileName;
    QFile *file = new QFile(fileName);

    if (!file->open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, "Nastąpił problem z otwarciem pliku", file->errorString());
        return;
    }

    addMessage(fileSendingStart);

    if(udp == nullptr) udp = new Udp("127.0.0.1", "239.0.0.1", "6100");
    udp->sendFile(file);
}
