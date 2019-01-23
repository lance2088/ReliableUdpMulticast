#include "startpacket.h"
#include "utils.h"

char *StartPacket::getStartPacketString() const
{
    return startPacketString;
}

StartPacket::StartPacket(int fileSize, int charsAtOnce, int packetNumberSize)
{
    this->fileSize = fileSize;
//    this->charsAtOnce = charsAtOnce;
    this->packetNumberSize = packetNumberSize;

    int howManyDataPackets = fileSize / charsAtOnce;
    if(fileSize % charsAtOnce != 0) howManyDataPackets++;

    this->howManyDataPackets = howManyDataPackets;

    QString message = QString::number(fileSize)
            + "." + QString::number(howManyDataPackets)
            + "." + QString::number(packetNumberSize);

    this->startPacketString = message.toLocal8Bit().data();
    this->startPacketStringLength = message.length();
}

StartPacket::StartPacket(char *startPacketString, int length)
{
    this->startPacketStringLength = length;

    int dotsIndexes[2];
    int j = 0;
    for(int i=0; i<length; i++)
    {
         if(startPacketString[i] == '.' && j<2)
         {
             dotsIndexes[j] = i;
             j++;
         }
    }

    char strFileSize[dotsIndexes[0]];
    char strCharsAtOnce[dotsIndexes[1]-dotsIndexes[0]-1];
    char strPacketNumerSize[length-dotsIndexes[1]-1];

    substr(startPacketString, 0, dotsIndexes[0], strFileSize);
    substr(startPacketString, dotsIndexes[0]+1, dotsIndexes[1], strCharsAtOnce);
    substr(startPacketString, dotsIndexes[1]+1, length, strPacketNumerSize);

    this->fileSize = strToInt(strFileSize, dotsIndexes[0]);
    this->howManyDataPackets = strToInt(strCharsAtOnce, dotsIndexes[1]-dotsIndexes[0]-1);
    this->packetNumberSize = strToInt(strPacketNumerSize, length-dotsIndexes[1]-1);
    this->startPacketString = startPacketString;
}

void StartPacket::describe()
{
//    std::cout<<"String: "<<this->startPacketString<<std::endl; - tutaj wystepuje jakis szum na koncu
    std::cout<<"String: ";
    for(int i=0; i<this->startPacketStringLength; i++) std::cout<<this->startPacketString[i];
    std::cout<<std::endl;
    std::cout<<"FileSize: "<<this->fileSize<<std::endl;
    std::cout<<"HowManyDataPackets: "<<this->howManyDataPackets<<std::endl;
    std::cout<<"PacketNumberSize: "<<this->packetNumberSize<<std::endl;
}
