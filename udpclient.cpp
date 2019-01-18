#include "udpclient.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include "utils.h"

UdpClient::~UdpClient()
{
    close(this->sock);
}

UdpClient::UdpClient(int domain, int type, int protocol, const char *client_ip, const char *port)
{
    this->domain = domain;
    this->type = type;
    this->protocol = protocol;

    if((this->sock = socket(domain, type, protocol)) < 0)
    {
        perror ("Cannot create the socket");
        exit (EXIT_FAILURE);
    }

    this->myaddr = generate_address_structure(client_ip, port);
    bind(sock, (struct sockaddr*)&myaddr, sizeof(struct sockaddr));
}

void UdpClient::sendToIp(const char *ip_address, const char *port, char *buf)
{
    struct sockaddr_in serv_addr = generate_address_structure(ip_address, port);

    socklen_t serv_addr_size = sizeof(struct sockaddr);

    if(sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&serv_addr, serv_addr_size) < 0 )
        {
            perror( "sendto() ERROR" );
            exit (EXIT_FAILURE);
        }
}

void UdpClient::recvFromIp(const char *ip_address, const char *port, char *buf)
{
    struct sockaddr_in serv_addr = generate_address_structure(ip_address, port);

    socklen_t serv_addr_size = sizeof(struct sockaddr);
    recvfrom(sock, buf, strlen(buf), 0, (struct sockaddr*)&serv_addr, &serv_addr_size);

}

