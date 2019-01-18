#include "udp.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include "utils.h"

Udp::~Udp()
{
    close(this->sock);
}

void Udp::joinMulticastGroup(const char *multicastIp)
{
    struct ip_mreq multicastStructure;
    multicastStructure.imr_interface.s_addr = inet_addr(this->ip);
    multicastStructure.imr_multiaddr.s_addr = inet_addr(multicastIp);
    setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&multicastStructure, sizeof(multicastStructure));
}

Udp::Udp(int domain, int type, int protocol, const char *client_ip)
{
    this->domain = domain;
    this->type = type;
    this->protocol = protocol;
    this->ip = client_ip;

    if((this->sock = socket(domain, type, protocol)) < 0)
    {
        perror ("Cannot create the socket");
        exit (EXIT_FAILURE);
    }

    this->myaddr = generate_address_structure(client_ip);
    bind(sock, (struct sockaddr*)&myaddr, sizeof(struct sockaddr));
}

Udp::Udp(int domain, int type, int protocol, const char *client_ip, const char *port)
{
    this->domain = domain;
    this->type = type;
    this->protocol = protocol;
    this->ip = client_ip;

    if((this->sock = socket(domain, type, protocol)) < 0)
    {
        perror ("Cannot create the socket");
        exit (EXIT_FAILURE);
    }

    this->myaddr = generate_address_structure(client_ip, port);
    bind(sock, (struct sockaddr*)&myaddr, sizeof(struct sockaddr));
}

int Udp::getSock() const
{
    return sock;
}


void Udp::recvFromIp(const char *ip_address, const char *port, char *buf)
{
    struct sockaddr_in serv_addr = generate_address_structure(ip_address, port);

    socklen_t serv_addr_size = sizeof(struct sockaddr);
    recvfrom(sock, buf, strlen(buf), 0, (struct sockaddr*)&serv_addr, &serv_addr_size);

}

void Udp::sendToIp(const char *ip_address, const char *port, char *buf)
{
    struct sockaddr_in serv_addr = generate_address_structure(ip_address, port);

    socklen_t serv_addr_size = sizeof(struct sockaddr);

    if(sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&serv_addr, serv_addr_size) < 0 )
        {
            perror( "sendto() ERROR" );
            exit (EXIT_FAILURE);
        }
}
