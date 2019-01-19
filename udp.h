#ifndef MANAGER_H
#define MANAGER_H

#include "qwidget.h"

#include "unicastudp.h"
#include "multicastudplistener.h"

class Udp
{
    private:
        UnicastUdp *unicastUdp;
        MulticastUdpListener *multicastUdpListener;
        const char *hostIp;
        const char *multicastIp;
        const char *multicastPort;

    public:
        Udp(const char *hostIp, const char *multicastIp, const char *multicastPort);
        ~Udp();
        void sendFile();
        void receiveFile();
};

#endif // MANAGER_H
