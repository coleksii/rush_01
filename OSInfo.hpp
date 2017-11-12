//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#ifndef RUSH01_OSINFO_HPP
#define RUSH01_OSINFO_HPP

#include "IMonitorModule.hpp"
#include <sys/utsname.h>
#include <cstring>
#include <fstream>
#include <istream>
#include <iostream>
#include <stdio.h>

class OSInfo : public IMonitorModule
{
public:
    OSInfo();
    ~OSInfo();
    void reload();
    char const *get_buff() const;
    OSInfo &operator=(OSInfo const &rhs);

private:
    std::string    _buff;
    OSInfo(OSInfo &src);
};


#endif //RUSH01_OSINFO_HPP
