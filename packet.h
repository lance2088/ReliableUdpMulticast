#ifndef PACKET_H
#define PACKET_H


class Packet
{
protected:
    int length;
    char* payload;

public:
    Packet();
    Packet(char* payload, int length);
    char* getPayload();
    int getLength();
};

#endif // PACKET_H
