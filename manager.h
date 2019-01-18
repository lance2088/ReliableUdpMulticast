#ifndef MANAGER_H
#define MANAGER_H

#include "unicastudp.h"
#include "multicastudplistener.h"
#include "qwidget.h"

class Manager
{
    private:
        UnicastUdp *unicastUdp;
        MulticastUdpListener *multicastUdpListener;
        const char *hostIp;
        const char *multicastIp;
        const char *multicastPort;

    public:
        Manager(const char *hostIp, const char *multicastIp, const char *multicastPort);
        ~Manager();
        void sendFile();
        void receiveFile();
};

#endif // MANAGER_H
