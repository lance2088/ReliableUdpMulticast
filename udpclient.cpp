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

UdpClient:: UdpClient()
{
    UdpClient(AF_INET, SOCK_DGRAM, 0, "127.0.0.1", "4000");
}

UdpClient::UdpClient(int domain, int type, int protocol, const char *client_ip, const char *port)
{
    this->domain = domain;
    this->type = type;
    this->protocol = protocol;

    this->sock = socket(domain, type, protocol);

    // own address structure
    this->myaddr = generate_address_structure(client_ip, port);

    bind(this->sock, (struct sockaddr*)&myaddr, sizeof(struct sockaddr));
}

void UdpClient::sendToIp(const char *ip_address, const char *port, char *buf)
{
    // server address structure
    struct sockaddr_in serv_addr = generate_address_structure(ip_address, port);

    socklen_t serv_addr_size = sizeof(struct sockaddr);
    sendto(sock, buf, strlen(buf+1), 0, (struct sockaddr*)&serv_addr, serv_addr_size);
}

void UdpClient::recvFromIp(const char *ip_address, const char *port, char *buf)
{
    // server address structure
    struct sockaddr_in serv_addr = generate_address_structure(ip_address, port);

    socklen_t serv_addr_size = sizeof(struct sockaddr);
    recvfrom(sock, buf, strlen(buf+1), 0, (struct sockaddr*)&serv_addr, &serv_addr_size);

}
