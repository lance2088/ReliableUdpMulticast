#include "utils.h"

struct sockaddr_in generate_address_structure(const char *ip)
{
    struct sockaddr_in address_structure;
    if(inet_pton(AF_INET, ip, & address_structure.sin_addr) <= 0)
        {
            perror("inet_pton() ERROR");
            exit(EXIT_FAILURE);
        }
    address_structure.sin_family = AF_INET;
    address_structure.sin_addr.s_addr = inet_addr(ip);
    address_structure.sin_port = 0;

    return address_structure;
}

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
    /*
    if(!address.isEmpty())
    {
        if(address.contains(":"))
        {
            QStringList addressInfo = address.split(":");
            try
            {
                if(INADDR_NONE == inet_addr(addressInfo.at(0).toLocal8Bit().data())) return false;
                else
                {
                    int portNumber = addressInfo.at(1).toInt();
                    if(portNumber>1024) return true;
                    else return false;
                }
            }
            catch(const std::exception& ex)
            {
                std::cout<<ex.what()<<std::endl;
                return false;
            }
        }
        else
        {
            if(INADDR_NONE == inet_addr(address.toLocal8Bit().data())) return false;
            else return true;
        }
    }
    return false;
    */
}
