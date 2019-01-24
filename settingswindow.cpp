#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    saveSettingsButton = ui->saveSettingsButton;
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_cancelSettingsButton_clicked()
{
    this->hide();
}

void SettingsWindow::on_saveSettingsButton_clicked()
{
    multicastAddress = ui->multicastAddressLineEdit->text();
    this->hide();
}
