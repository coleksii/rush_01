//
// Created by Dmytrii Spyrydonov on 12/11/2017.
//

#include <string>
#include "Network.hpp"

Network::Network()
{
    reload();
}

Network::~Network()
{
}

void Network::reload()
{
    std::string::size_type begin;
    std::string::size_type end;
    FILE *network;
    char buff[1024];
    network = popen("top -l 1 | grep \"Networks\"", "r");
    fgets(buff, sizeof(buff), network);
    std::string tmp(buff);
    begin = tmp.find("ts:");
    end = tmp.find("in");
    in = tmp.substr(begin + 4, end - (begin + 4));
    begin = tmp.find("in,");
    end = tmp.find("out");
    out = tmp.substr(begin + 4, end - (begin + 4));
    pclose(network);
}

char const *Network::getIn() const
{
    return in.c_str();
}

char const *Network::getOut() const
{
    return out.c_str();
}
