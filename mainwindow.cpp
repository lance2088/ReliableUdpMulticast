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

    manager = nullptr;
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

void MainWindow::on_sendButton_clicked()
{
    sendWindow.show();
}

void MainWindow::sendFile() //Ciało tej funkcji powinno zostać przeniesione do zewnętrznej funkcji zajmującej się wysyłaniem
{
    addMessage(fileSendingStart);
//    QString fileName = sendWindow.fileName;

//    const int charsAtOnce = 10; //Parametr który powinien zostać przeniesiony w momencie, gdy będziemy znali wielkość pakietu
//    char buffer[charsAtOnce];
//    int charsRead = charsAtOnce;

//    QFile file(fileName);
//    QDataStream in(&file);

//    if (!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(this, tr("Nastąpił problem z otwarciem pliku"), file.errorString());
//        return;
//    }

//    while(charsRead == charsAtOnce){
//        charsRead = in.readRawData(buffer, charsAtOnce);
//        //Printowanie ilustrujace wyslanie pliku w pakietach
//        for(int j = 0; j < charsRead; j++) printf("%c", buffer[j]);
//    }

    if(manager == nullptr) manager = new Manager("127.0.0.1", "239.0.0.1", "6100");
    manager->sendFile();
    manager->receiveFile();
}

void MainWindow::joinMulticast()
{
//    QString multicastAddress = settingsWindow.multicastAddress;
//    QString hostAddress = settingsWindow.hostAddress;

    bool success = true; // TODO: próba dołączenia lub weryfikacji adresu

    if(success){
        ui->sendButton->setEnabled(true);
        addMessage(joinSuccess);
    }
    else{
        addMessage(joinFailure);
    }
}
