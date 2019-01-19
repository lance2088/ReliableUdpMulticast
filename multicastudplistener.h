#ifndef MULTICASTUDPLISTENER_H
#define MULTICASTUDPLISTENER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class MulticastUdpListener
{
    private:
        int sock;
        int domain;
        int type;
        int protocol;
        int nbytes;
        socklen_t addrlen;
        const char *multicastPort;
        const char *multicastIp;
        struct sockaddr_in addr;
        struct ip_mreq mreq;

    public:
        MulticastUdpListener(int domain, int type, int protocol, const char *hostIp, const char *multicastAddress, const char *multicastPort);
        ~MulticastUdpListener();
        void recvPacket(char *buf);
        int getNbytes() const;
};

#endif // MULTICASTUDPLISTENER_H
