#ifndef PACKET_H
#define PACKET_H


class Packet
{
    protected:
        int length;
        QString packetString;

    public:
        Packet();
        Packet(QString packetString);
        QString getPacketString();
};

#endif // PACKET_H
