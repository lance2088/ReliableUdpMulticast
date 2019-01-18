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

Manager::Manager(QString hostInfo, QString multicastInfo)
{
    const char *hostIp = hostInfo.toLocal8Bit().data();
    this->sender = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);
    this->receiver = new Udp(AF_INET, SOCK_DGRAM, IPPROTO_UDP, hostIp);

    const char *multicastIp = multicastInfo.toLocal8Bit().data();
    this->receiver->joinMulticastGroup(multicastIp);
}

void Manager::sendFile()
{
    this->sender->sendToIp("235.0.0.0", "2500", "wiadomosc w butelce");
    /*
    // The structure for two events
    struct pollfd fds[2];

    fds[0].fd = this->sender->getSock();
    fds[0].events = POLLOUT;

    fds[1].fd = this->receiver->getSock();
    fds[1].events = POLLIN;

    // Wait infinitely for an event
    int ret = poll(fds, 2, -1);

    // Check if poll actually succeed
    if (ret == -1)
    {
        // report error and abort
        perror ("ret == -1");
        exit (EXIT_FAILURE);
    }
    else
    {
        // If we detect the event, zero it out so we can reuse the structure
        if (fds[0].revents & POLLOUT)
        {
            fds[0].revents = 0;
            this->sender->sendToIp("127.0.0.1", "5555", "kurczakii");
        }

        if (fds[1].revents & POLLIN) {
            fds[1].revents = 0;
            char buf[1000];
            this->receiver->recvFromIp("127.0.0.1", "4500", buf);
        }
    }
    */

}

void Manager::receiveFile()
{
    char buf[19];
    this->receiver->recvFromIp("235.0.0.0", "2500", buf);
    std::cout<<buf<<std::endl;
}
