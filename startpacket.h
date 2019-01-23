#ifndef STARTPACKET_H
#define STARTPACKET_H


class StartPacket
{
    private:
        char *startPacketString;
        int startPacketStringLength;
        int fileSize;
        int packetNumberSize;
        int howManyDataPackets;

    public:
        StartPacket(int fileSize, int charsAtOnce, int packetNumberSize);
        StartPacket(char *startPacketString, int length);
        void describe();
        char *getStartPacketString() const;
};

#endif // STARTPACKET_H
