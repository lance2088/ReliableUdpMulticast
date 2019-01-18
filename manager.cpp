#include "manager.h"
#include "udp.h"
#include "poll.h"
#include <stdio.h>
#include "qwidget.h"
#include <iostream>

Manager::~Manager()
{
    delete this->sender;
    delete this->receiver;
}

Manager::Manager()
{
    this->sender = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, "127.0.0.1");
    this->receiver = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, "127.0.0.1");
}

Manager::Manager(QString hostInfo)
{
    const char *hostIp = hostInfo.toLocal8Bit().data();
    this->sender = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->receiver = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
}

Manager::Manager(const char *hostIp, const char *multicastIp)
{
    this->sender = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->receiver = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->receiver->joinMulticastGroup(multicastIp);

    // The structure for two events
    struct pollfd fds[2];

    fds[0].fd = this->sender->getSock();
    fds[0].events = POLLOUT;

    fds[1].fd = this->receiver->getSock();
    fds[1].events = POLLIN;

    // Wait infinitely for an event
    while(true) {
        int ret = poll(fds, 2, 10);

        std::cout<<"after poll"<<std::endl;

        // Check if poll actually succeed
        if(ret == -1)
        {
            // report error and abort
            perror ("ret == -1");
            exit (EXIT_FAILURE);
        }
        else if(ret != 0)
        {
            if (fds[0].revents & POLLIN)
            {
                fds[0].revents = 0;
                this->sender->sendToIp("239.0.0.1", "5555", "kurczakii");
            }

            if (fds[1].revents & POLLOUT)
            {
                fds[1].revents = 0;
                char buf[1000];
                this->receiver->recvFromIp("239.0.0.1", "5555", buf);
            }
        }
    }
}

void Manager::sendFile()
{
//    this->sender->sendToIp("235.0.0.0", "2500", "wiadomosc w butelce");
//    /*


    this->sender->sendToIp("239.0.0.1", "5555", "kurczakii");
//    */

}

void Manager::receiveFile()
{
    char buf[19];
    this->receiver->recvFromIp("239.0.0.1", "5555", buf);
    std::cout<<buf<<std::endl;
}
