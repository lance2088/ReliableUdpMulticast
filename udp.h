#ifndef MANAGER_H
#define MANAGER_H

#include <QFile>
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
        void sendPacket(char *data);

    public:
        Udp(const char *hostIp, const char *multicastIp, const char *multicastPort);
        ~Udp();
        void sendFile(QFile *file);
        void receiveFile();
};

#endif // MANAGER_H
