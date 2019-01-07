#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <settingswindow.h>
#include <constants.h>
#include <QStandardItemModel>
#include <QStandardItem>

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

    void joinMulticast();

private:
    QStandardItemModel* listModel;
    Ui::MainWindow *ui;
    SettingsWindow settingsWindow;
};

#endif // MAINWINDOW_H
