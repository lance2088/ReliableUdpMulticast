#ifndef DATAPACKET_H
#define DATAPACKET_H

#include <QString>

#include "packet.h"

class DataPacket : public Packet
{
    private:
        int packetNumberSize;
        int packetNumber;
        char* data;
        void writePacketNumber(char *payload, int packetNumber, int packetNumberSize);
        int getPacketNumber(char* payload, int packetNumberSize);
    public:
        DataPacket(Packet *packet, int packetNumberSize);
        DataPacket(char* payload, int length, int packetNumberSize, int packetNumber);
};

#endif // DATAPACKET_H
