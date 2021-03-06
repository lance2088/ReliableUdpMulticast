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
    delete this->startPacket;
}

Udp::Udp(const char *hostIp, const char *multicastIp, const char *multicastPort)
{
    this->unicastUdp = new UnicastUdp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->multicastUdpListener = new MulticastUdpListener(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp, multicastIp, multicastPort);
    this->hostIp = hostIp;
    this->multicastIp = multicastIp;
    this->multicastPort = multicastPort;
    this->startPacket = nullptr;
}

void Udp::sendFile(QFile *file)
{
    QDataStream in(file);

    char buffer[payloadSize];
    const int charsAtOnce = calculateActualDataSize(file->size());
    const int packetNumberSize = payloadSize - charsAtOnce;
    int charsRead = charsAtOnce;
    int packetNum = 0;

    if(this->startPacket != nullptr) delete this->startPacket;
    this->startPacket = new StartPacket(file->size(), charsAtOnce, packetNumberSize);

    this->sendPacket(this->startPacket);

    while(charsRead == charsAtOnce){
        charsRead = in.readRawData(buffer, charsAtOnce);
        DataPacket *packet = new DataPacket(buffer, charsRead, packetNumberSize, packetNum);
        sendPacket(packet);
        delete packet;
        packetNum++;
    }
}

void Udp::receiveFile(int fileSize, int howManyDataPackets, int packetNumberSize)
{
    Packet *receivedPacket = this->multicastUdpListener->recvPacket();
    DataPacket *dataPacket;
    dataPacket = new DataPacket(receivedPacket, packetNumberSize);
    delete dataPacket;
}

void Udp::sendPacket(Packet *packet)
{
    this->unicastUdp->sendToIp(this->multicastIp, this->multicastPort, packet->getPayload());
}
