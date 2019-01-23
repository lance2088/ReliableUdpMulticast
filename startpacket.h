#ifndef STARTPACKET_H
#define STARTPACKET_H

#include "packet.h"

class StartPacket : public Packet
{
    private:
        int fileSize;
        int packetNumberSize;
        int howManyDataPackets;

    public:
        StartPacket(int fileSize, int charsAtOnce, int packetNumberSize);
        StartPacket(QString packetString);
        void describe();
};

#endif // STARTPACKET_H
