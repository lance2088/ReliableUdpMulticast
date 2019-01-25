#include <cmath>
#include <QString>
#include <QStringList>

#include "startpacket.h"
#include "utils.h"

int StartPacket::getPacketNumberSize() const
{
    return packetNumberSize;
}

void StartPacket::setParameters(char *payload)
{
    QString payloadAsQstring = payload;
    QStringList parameters = payloadAsQstring.split('.');

    this->fileSize = parameters.at(0).toInt();
    this->howManyDataPackets = parameters.at(1).toInt();
    this->packetNumberSize = parameters.at(2).toInt();
}

StartPacket::StartPacket(int fileSize, int charsAtOnce, int packetNumberSize)
{
    this->fileSize = fileSize;
    this->packetNumberSize = packetNumberSize;
    this->howManyDataPackets = ceil(1.0 * fileSize / charsAtOnce);

    QString message = QString::number(fileSize)
            + "." + QString::number(howManyDataPackets)
            + "." + QString::number(packetNumberSize);

    this->payload = message.toUtf8().data();
    this->length = message.length();
}

StartPacket::StartPacket(char* payload, int length) : Packet(payload, length)
{
    setParameters(payload);
}
