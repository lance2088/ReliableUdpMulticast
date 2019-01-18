#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <settingswindow.h>
#include <sendwindow.h>
#include <constants.h>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>

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
};

#endif // MAINWINDOW_H
