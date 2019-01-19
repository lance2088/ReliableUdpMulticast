#include <stdio.h>
#include "qwidget.h"
#include <iostream>

#include "udp.h"
#include "unicastudp.h"
#include "multicastudplistener.h"
#include "poll.h"

Udp::~Udp()
{
    delete this->unicastUdp;
    delete this->multicastUdpListener;
}

Udp::Udp(const char *hostIp, const char *multicastIp, const char *multicastPort)
{
    this->unicastUdp = new UnicastUdp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->multicastUdpListener = new MulticastUdpListener(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp, multicastIp, multicastPort);
    this->hostIp = hostIp;
    this->multicastIp = multicastIp;
    this->multicastPort = multicastPort;
}

void Udp::sendFile()
{
    char *message = "wiadomostkakurczaki";
    this->unicastUdp->sendToIp(this->multicastIp, this->multicastPort, message);
    std::cout<<"Sent message: "<<message<<std::endl;
}

void Udp::receiveFile()
{
    char buf[256];
    this->multicastUdpListener->recvPacket(buf);
    std::cout<<"Received message: ";
    for(int i=0; i<this->multicastUdpListener->getNbytes(); i++)
    {
        std::cout<<buf[i];
    }
    std::cout<<std::endl;
}
