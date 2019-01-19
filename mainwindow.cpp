#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include "udp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(settingsWindow.saveSettingsButton,SIGNAL(clicked()),this,SLOT(joinMulticast()));
    connect(sendWindow.acceptSendButton,SIGNAL(clicked()),this,SLOT(sendFile()));

    listModel = new QStandardItemModel();
    ui->messageListView->setModel(listModel);

    addMessage(joinFailure);
    addMessage(joinSuccess);
    addMessage(fileSendingStart);
    addMessage(receiversFound.arg(4));
    addMessage(resending.arg("192.168.0.16"));
    addMessage(receiverInactive.arg("192.168.0.16"));
    addMessage(fileSendingSuccess.arg(3));
    addMessage(fileReceived);
    addMessage(fileReceived);

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

void MainWindow::sendFile() //Ciało tej funkcji powinno zostać przeniesione do zewnętrznej funkcji zajmującej się wysyłaniem
{
    addMessage(fileSendingStart);

    if(udp == nullptr) udp = new Udp("127.0.0.1", "239.0.0.1", "6100");
    udp->sendFile();
    udp->receiveFile();
}

void MainWindow::joinMulticast()
{
    bool success = true; // TODO: próba dołączenia lub weryfikacji adresu

    if(success){
        ui->sendButton->setEnabled(true);
        addMessage(joinSuccess);
    }
    else{
        addMessage(joinFailure);
    }
}
