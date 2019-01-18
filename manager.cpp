#include "manager.h"
#include "unicastudp.h"
#include "multicastudplistener.h"
#include "poll.h"
#include <stdio.h>
#include "qwidget.h"
#include <iostream>

Manager::~Manager()
{
    delete this->unicastUdp;
    delete this->multicastUdpListener;
}

Manager::Manager(const char *hostIp, const char *multicastIp, const char *multicastPort)
{
    this->unicastUdp = new UnicastUdp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->multicastUdpListener = new MulticastUdpListener(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp, multicastIp, multicastPort);
    this->hostIp = hostIp;
    this->multicastIp = multicastIp;
    this->multicastPort = multicastPort;
}

void Manager::sendFile()
{
    char *message = "wiadomostkakurczaki";
    this->unicastUdp->sendToIp(this->multicastIp, this->multicastPort, message);
    std::cout<<"Sent message: "<<message<<std::endl;
}

void Manager::receiveFile()
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
