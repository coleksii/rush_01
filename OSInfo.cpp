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

char *OSInfo::getSysname()
{
    return _sysname;
}

char *OSInfo::getNodename()
{
    return _nodename;
}

char *OSInfo::getRelease()
{
    return _release;
}

char *OSInfo::getVersion()
{
    return _version;
}

char *OSInfo::getMachine()
{
    return _machine;
}

char const *OSInfo::get_buff()
{
    return _buff.c_str();
}
