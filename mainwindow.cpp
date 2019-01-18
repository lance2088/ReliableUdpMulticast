#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "utils.h"
#include "manager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(settingsWindow.saveSettingsButton,SIGNAL(clicked()),this,SLOT(joinMulticast()));

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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
}

void MainWindow::addMessage(QString message){
    QStandardItem* messageItem = new QStandardItem(message);
    listModel->appendRow(messageItem);
}

void MainWindow::on_settingsButton_clicked()
{
    settingsWindow.show();
}

void MainWindow::joinMulticast()
{
    QString multicastAddress = settingsWindow.multicastAddress;
    QString hostAddress = settingsWindow.hostAddress;

    bool multicastSuccess = validateAddress(multicastAddress);
    bool hostSuccess = validateAddress(hostAddress);

    Manager *manager = nullptr;

    char *hostIp = "127.0.0.1";
    if(hostSuccess) hostIp = hostAddress.toLocal8Bit().data();
    if(multicastSuccess) manager = new Manager(hostIp, multicastAddress.toLocal8Bit().data());
    else manager = new Manager(hostIp);

    bool success = true; // TODO: próba dołączenia lub weryfikacji adresu


    if(success){
        ui->sendButton->setEnabled(true);
        addMessage(joinSuccess);
    }
    else{
        addMessage(joinFailure);
    }
}
