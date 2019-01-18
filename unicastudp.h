#ifndef UDP_H
#define UDP_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class UnicastUdp
{
    private:
        int sock;
        int domain;
        int type;
        int protocol;
        const char *ip;
        struct sockaddr_in myaddr;

    public:
        UnicastUdp(int domain, int type, int protocol, const char *client_ip);
        ~UnicastUdp();
        void recvFromIp(const char *ip_address, const char *port, char *buf);
        void sendToIp(const char *ip_address, const char *port, char *buf);
};

#endif // UDP_H
