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
        Manager(const char *hostIp, const char *multicastIp);
        ~Manager();
        void sendFile();
        void receiveFile();
};

#endif // MANAGER_H
