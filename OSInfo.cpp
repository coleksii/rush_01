//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#include "OSInfo.hpp"


OSInfo::OSInfo()
{
    reload();
}

OSInfo::~OSInfo()
{
}

void OSInfo::reload()
{
    FILE *os;
    char buff[1024];
    std::string line;
    os = popen("system_profiler SPSoftwareDataType", "r");
    while (fgets(buff, sizeof(buff), os) != NULL)
        _buff = _buff + buff;
    pclose(os);
}

char const *OSInfo::get_buff() const
{
    return _buff.c_str();
}

OSInfo& OSInfo::operator=(OSInfo const &rhs)
{
    this->_buff = rhs.get_buff();
    return *this;
}

OSInfo::OSInfo(OSInfo &src)
{
    *this = src;
}


