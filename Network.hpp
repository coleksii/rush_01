//
// Created by Dmytrii Spyrydonov on 12/11/2017.
//

#ifndef RUSH01_NETWORK_HPP
#define RUSH01_NETWORK_HPP

#include <sys/sysctl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <net/route.h>


class Network
{
public:
    Network();
    virtual ~Network();
    void reload();
    char const  *getIn() const;
    char const  *getOut() const;
private:
    std::string in;
    std::string out;
};


#endif //RUSH01_NETWORK_HPP
