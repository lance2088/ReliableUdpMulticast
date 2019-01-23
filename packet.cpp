#include <qstring.h>

#include "packet.h"

Packet::Packet()
{

}

Packet::Packet(QString packetString)
{
    this->packetString = packetString;
    this->length = packetString.length();
}

QString Packet::getPacketString()
{
    return this->packetString;
}
