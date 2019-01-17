#include "utils.h"

struct sockaddr_in generate_address_structure(const char *ip, const char *port)
{
    struct sockaddr_in address_structure;
    memset(&address_structure, 0, sizeof(struct sockaddr));
    address_structure.sin_family = AF_INET;
    address_structure.sin_addr.s_addr = inet_addr(ip);
    address_structure.sin_port = htons(atoi(port));

    return address_structure;
}
