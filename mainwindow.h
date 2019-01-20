#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>

#include <settingswindow.h>
#include <sendwindow.h>
#include <constants.h>
#include "udp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addMessage(QString message);

private slots:
    void on_settingsButton_clicked();
    void on_sendButton_clicked();
    void joinMulticast();
    void sendFile();

private:
    QStandardItemModel* listModel;
    Ui::MainWindow *ui;
    SettingsWindow settingsWindow;
    SendWindow sendWindow;
    Udp *udp;
};

#endif // MAINWINDOW_H
