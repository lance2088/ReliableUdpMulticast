#ifndef STARTPACKET_H
#define STARTPACKET_H

#include "packet.h"

class StartPacket : public Packet
{
    private:
        int fileSize;
        int packetNumberSize;
        int howManyDataPackets;
        void setParameters(char *payload);
public:
        StartPacket(int fileSize, int charsAtOnce, int packetNumberSize);
        StartPacket(char* payload, int length);
        int getPacketNumberSize() const;
};

#endif // STARTPACKET_H
