#ifndef DATAPACKET_H
#define DATAPACKET_H

#include <QString>

#include "packet.h"

class DataPacket : public Packet
{
    private:
        int packetNumberSize;
        int packetNumber;
        QString data;
        QString createNumberString(int packetNumber, int packetNumberSize);
        int getPacketNumber(QString packetString, int packetNumberSize);
    public:
        DataPacket(QString packetString, int packetNumberSize);
        DataPacket(QString packetString, int packetNumberSize, int packetNumber);
};

#endif // DATAPACKET_H
