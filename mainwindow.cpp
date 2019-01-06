#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listModel = new QStandardItemModel();
    ui->messageListView->setModel(listModel);

    addMessage("Nie znaleziono grupy multicast. Upewnij się, że podany adres jest poprawny.");
    addMessage("Grupa multicast rozpoznana!");
    addMessage("Rozpoczęto wysyłanie pliku. Znaleziono odbiorców: 4");
    addMessage("Ponawianie pakietu dla 192.168.0.16...");
    addMessage("Odbiorca 192.168.0.16 nie odpowiada. Odbiorca może nie otrzymać pliku w całości.");
    addMessage("Pomyślnie wysłano plik do 3 odbiorców!");
    addMessage("Odebrano plik. Plik jest dostępny do pobrania.");
    addMessage("Odebrano plik. Plik jest dostępny do pobrania.");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addMessage(QString message){
    QStandardItem* messageItem = new QStandardItem(message);
    listModel->appendRow(messageItem);
}
