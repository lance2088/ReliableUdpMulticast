#include <cmath>
#include <QString>
#include <QStringList>

#include "startpacket.h"
#include "utils.h"

int StartPacket::getPacketNumberSize() const
{
    return packetNumberSize;
}

StartPacket::StartPacket(int fileSize, int charsAtOnce, int packetNumberSize)
{
    this->fileSize = fileSize;
    this->packetNumberSize = packetNumberSize;
    this->howManyDataPackets = ceil(1.0 * fileSize / charsAtOnce);

    QString message = QString::number(fileSize)
            + "." + QString::number(howManyDataPackets)
            + "." + QString::number(packetNumberSize);

    this->packetString = message;
    this->length = message.length();
}

StartPacket::StartPacket(QString packetString) : Packet(packetString)
{
    QStringList data = this->packetString.split(".");
    this->fileSize = data.at(0).toInt();
    this->howManyDataPackets = data.at(1).toInt();
    this->packetNumberSize = data.at(2).toInt();
}

void StartPacket::describe()
{
    std::cout<<"String: "<<this->packetString.toUtf8().data()<<std::endl;
    std::cout<<"FileSize: "<<this->fileSize<<std::endl;
    std::cout<<"HowManyDataPackets: "<<this->howManyDataPackets<<std::endl;
    std::cout<<"PacketNumberSize: "<<this->packetNumberSize<<std::endl;
}
