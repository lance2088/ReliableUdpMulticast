#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    bool success = true; // TODO: próba dołączenia lub weryfikacji adresu

    if(success){
        ui->sendButton->setEnabled(true);
        addMessage(joinSuccess);
    }
    else{
        addMessage(joinFailure);
    }
}
