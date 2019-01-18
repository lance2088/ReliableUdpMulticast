#ifndef SENDWINDOW_H
#define SENDWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QStandardPaths>
#include <QPushButton>

namespace Ui {
class SendWindow;
}

class SendWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SendWindow(QWidget *parent = 0);
    ~SendWindow();
    QPushButton *acceptSendButton;
    QString fileName;

private slots:
    void on_fileSelectButton_clicked();
    void on_cancelSendButton_clicked();
    void on_acceptSendButton_clicked();

private:
    Ui::SendWindow *ui;
    QPushButton *fileSelectButton;
};

#endif // SENDWINDOW_H
