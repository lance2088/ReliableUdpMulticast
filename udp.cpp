#include <stdio.h>
#include "qwidget.h"
#include <iostream>

#include "udp.h"
#include "unicastudp.h"
#include "multicastudplistener.h"
#include "poll.h"
#include "constants.h"
#include "utils.h"

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

void Udp::sendFile(QFile *file)
{
    QDataStream in(file);

    char buffer[payloadSize];
    const int charsAtOnce = calculateActualDataSize(file->size());
    const int packetNumberSize = payloadSize - charsAtOnce;
    int charsRead = charsAtOnce;
    int packetNum = 0; // DLA TESTOWANIA O NC ZAMIENIC NA 1

    while(charsRead == charsAtOnce){
        charsRead = in.readRawData(buffer+packetNumberSize, charsAtOnce);
        writePacketNum(buffer, packetNum, packetNumberSize);
        sendPacket(buffer);
        packetNum++;
    }
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

void Udp::sendPacket(char * data)
{
    this->unicastUdp->sendToIp(this->multicastIp, this->multicastPort, data);
    std::cout<<"Sent message: "<<data<<std::endl;
}
