#ifndef MANAGER_H
#define MANAGER_H

#include <QFile>
#include "qwidget.h"

#include "unicastudp.h"
#include "multicastudplistener.h"
#include "startpacket.h"

class Udp
{
    private:
        UnicastUdp *unicastUdp;
        MulticastUdpListener *multicastUdpListener;
        const char *hostIp;
        const char *multicastIp;
        const char *multicastPort;
        StartPacket *startPacket;
        void sendPacket(Packet *packet);

    public:
        Udp(const char *hostIp, const char *multicastIp, const char *multicastPort);
        ~Udp();
        void sendFile(QFile *file);
        void receiveFile();
};

#endif // MANAGER_H
