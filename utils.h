#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <qstring.h>

struct sockaddr_in generate_address_structure(const char *ip, const char *port="0");

long int pow(int base, int exp);

void substr(char *str, int begin, int end, char *strResult);

int charToInt(char digit);

long int strToInt(char *str, int length);

bool validateAddress(QString address);

int calculateActualDataSize(int sizeOfFile);

void writePacketNum(char *buffer, int packetNum, int packetNumberSize);

#endif // UTILS_H
