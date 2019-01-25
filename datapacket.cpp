#include <bitset>

#include "datapacket.h"
#include <iostream>

void DataPacket::writePacketNumber(char* payload, int packetNumber, int packetNumberSize)
{
    while(packetNumberSize > 0){
        packetNumberSize--;
        payload[packetNumberSize] = ((char)(packetNumber % 256));
        packetNumber /= 256;
    }
}

int DataPacket::getPacketNumber(char* payload, int packetNumberSize)
{
    int result = 0;

    for(int i = 0; i < packetNumberSize; i++){
        result *= 256;
        result += payload[i];
    }

    return result;
}

DataPacket::DataPacket(Packet *packet, int packetNumberSize) : Packet(packet->getPayload(), packet->getLength())
{
    this->packetNumberSize = packetNumberSize;
    this->data = payload + packetNumberSize;
    this->packetNumber = getPacketNumber(payload, packetNumberSize);
}

DataPacket::DataPacket(char* payload, int length, int packetNumberSize, int packetNumber) : Packet(payload, length)
{
    this->packetNumberSize = packetNumberSize;
    this->packetNumber = packetNumber;
    writePacketNumber(payload, packetNumber, packetNumberSize);
}
