#include "multicastudplistener.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include "utils.h"

MulticastUdpListener::~MulticastUdpListener()
{
    close(this->sock);
}

MulticastUdpListener::MulticastUdpListener(int domain, int type, int protocol, const char *hostIp, const char *multicastAddress, const char *multicastPort)
{
    this->domain = domain;
    this->type = type;
    this->protocol = protocol;
    this->multicastIp = multicastAddress;

    u_int yes=1;

    if((this->sock = socket(domain, type, protocol)) < 0)
    {
        perror ("Cannot create the socket");
        exit (EXIT_FAILURE);
    }

    /* allow multiple sockets to use the same PORT number */
    if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0)
    {
        perror("Reusing ADDR failed");
        exit(EXIT_FAILURE);
    }

    /* set up destination address */
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY); /* N.B.: differs from sender */
    addr.sin_port=htons(atoi(multicastPort));

    if (bind(sock,(struct sockaddr *) &addr,sizeof(addr)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    this->multicastPort = multicastPort;

    mreq.imr_multiaddr.s_addr=inet_addr(multicastAddress);
    mreq.imr_interface.s_addr=inet_addr(hostIp);
    if (setsockopt(sock,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq)) < 0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
}

void MulticastUdpListener::recvPacket(char *buf)
{
    addrlen=sizeof(addr);
    if ((nbytes=recvfrom(sock,buf,256,0,(struct sockaddr *) &addr,&addrlen)) < 0)
    {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }
}

int MulticastUdpListener::getNbytes() const
{
    return nbytes;
}
