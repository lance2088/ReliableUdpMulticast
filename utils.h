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

bool validateAddress(QString address);

#endif // UTILS_H
