#include <bitset>

#include "datapacket.h"
#include <iostream>

QString DataPacket::createNumberString(int packetNumber, int packetNumberSize)
{
    // TODO: kodowanie
    QString result = "";
    while(packetNumberSize > 0){
        packetNumberSize--;
        result = QChar(packetNumber%256) + result;
        packetNumber /= 256;
    }
    return result;
}

int DataPacket::getPacketNumber(QString packetString, int packetNumberSize)
{
    // TODO: dekodowanie
    QString packetNumberString = packetString;
    packetNumberString.truncate(packetNumberSize);

    QString binaryRepresentation = "";
    const char *temp = packetString.toLatin1().data();
    int code;
    std::string binary;
    for(int i=0; i<packetNumberString.length(); i++)
    {
        code = temp[i];
        binary = std::bitset<8>(code).to_string(); //to binary
        binaryRepresentation += QString::fromStdString(binary);
    }

    return binaryRepresentation.toInt(nullptr, 2);
}

DataPacket::DataPacket(QString packetString, int packetNumberSize) : Packet(packetString)
{
    this->packetNumberSize = packetNumberSize;
    this->data = packetString.remove(0, packetNumberSize);
    this->packetNumber = getPacketNumber(packetString, packetNumberSize);
    std::cout<<this->packetNumber<<std::endl;
}

DataPacket::DataPacket(QString packetString, int packetNumberSize, int packetNumber)
{
    this->packetNumberSize = packetNumberSize;
    this->data = packetString;
    this->packetString = createNumberString(packetNumber, packetNumberSize) + packetString;
    this->packetNumber = packetNumber;
    this->length = this->packetString.length();
}
