#include "utils.h"
#include "constants.h"

struct sockaddr_in generate_address_structure(const char *ip, const char *port)
{
    struct sockaddr_in address_structure;
    if(inet_pton(AF_INET, ip, & address_structure.sin_addr) <= 0)
        {
            perror("inet_pton() ERROR");
            exit(EXIT_FAILURE);
        }
    address_structure.sin_family = AF_INET;
    address_structure.sin_addr.s_addr = inet_addr(ip);
    address_structure.sin_port = htons(atoi(port));

    return address_structure;
}

bool validateAddress(QString address)
{
    if(!address.isEmpty())
    {
        if(INADDR_NONE == inet_addr(address.toLocal8Bit().data())) return false;
        else return true;
    }
    else return false;
}

int calculateActualDataSize(int sizeOfFile)
{
    int dataSize = payloadSize;

    while(sizeOfFile > dataSize){
        sizeOfFile /= 256;
        dataSize--;
    }

    return dataSize;
}

void writePacketNum(char *buffer, int packetNum, int packetNumberSize)
{
    while(packetNumberSize > 0){
        packetNumberSize--;
        buffer[packetNumberSize] = packetNum % 256;
        packetNum /= 256;
    }
}

long int pow(int base, int exp)
{
    long int result = 1;
    for(int i=1; i<=exp; i++)
    {
        result *= base;
    }
    return result;
}

void substr(char *str, int begin, int end, char *strResult)
{
    for(int i=begin; i<end; i++) strResult[i-begin] = str[i];
}

int charToInt(char digit)
{
    return digit - '0';
}

long int strToInt(char *str, int length)
{
    long int total = 0;
    for(int i=0; i<length; i++)
    {
        total += (pow(10, length-i-1) * charToInt(str[i]));
    }
    return total;
}
