#include "utils.h"

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
