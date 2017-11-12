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
#include <iostream>
#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
public:
    Network();
    ~Network();
    void reload();
    char const  *getIn() const;
    char const  *getOut() const;
    Network &operator=(Network const &rhs);

private:
    std::string in;
    std::string out;
    Network(Network const &src);

};


#endif //RUSH01_NETWORK_HPP
