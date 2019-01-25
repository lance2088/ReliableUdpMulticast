#include <qstring.h>

#include "packet.h"

Packet::Packet()
{

}

Packet::Packet(char* payload, int length)
{
    this->payload = payload;
    this->length = length;
}

char* Packet::getPayload()
{
    return this->payload;
}

int Packet::getLength()
{
    return this->length;
}
