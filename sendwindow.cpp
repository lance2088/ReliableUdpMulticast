#include "sendwindow.h"
#include "ui_sendwindow.h"

SendWindow::SendWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendWindow)
{
    ui->setupUi(this);
    fileSelectButton = ui->fileSelectButton;
    acceptSendButton = ui->acceptSendButton;
}

SendWindow::~SendWindow()
{
    delete ui;
}

void SendWindow::on_fileSelectButton_clicked()
{
    QString homeDir = QStandardPaths::standardLocations(QStandardPaths::HomeLocation).first();
    fileName = QFileDialog::getOpenFileName(this, tr("Wybierz plik"), homeDir, "");

    fileSelectButton->setText(fileName);
}

void SendWindow::on_acceptSendButton_clicked()
{
    this->hide();
}

void SendWindow::on_cancelSendButton_clicked()
{
    this->hide();
}
