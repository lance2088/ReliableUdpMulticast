#ifndef MANAGER_H
#define MANAGER_H

#include "udp.h"
#include "qwidget.h"

class Manager
{
    private:
        Udp *sender;
        Udp *receiver;

    public:
        Manager();
        Manager(QString hostInfo);
        Manager(QString hostInfo, QString multicastInfo);
        ~Manager();
        void sendFile();
        void receiveFile();
};

#endif // MANAGER_H
