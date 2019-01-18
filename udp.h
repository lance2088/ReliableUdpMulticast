#ifndef UDP_H
#define UDP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class Udp
{
    private:
        int sock;
        int domain;
        int type;
        int protocol;
        const char *ip;
        struct sockaddr_in myaddr;

    public:
        Udp(int domain, int type, int protocol, const char *client_ip);
        Udp(int domain, int type, int protocol, const char *client_ip, const char *port);
        ~Udp();
        void joinMulticastGroup(const char *multicastIp);
        void recvFromIp(const char *ip_address, const char *port, char *buf);
        void sendToIp(const char *ip_address, const char *port, char *buf);
        int getSock() const;
};

#endif // UDP_H
