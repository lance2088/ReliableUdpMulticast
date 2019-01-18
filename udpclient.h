#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class UdpClient
{
    private:
        int sock;
        int domain;
        int type;
        int protocol;
        struct sockaddr_in myaddr;

    public:
        UdpClient(int domain, int type, int protocol, const char *client_ip, const char *port);
        ~UdpClient();
        void sendToIp(const char *ip_address, const char *port, char *buf);
        void recvFromIp(const char *ip_address, const char *port, char *buf);
};

#endif // UDPCLIENT_H
