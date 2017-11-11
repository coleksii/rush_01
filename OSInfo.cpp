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
    utsname uts;

    uname(&uts);
    strcpy(_sysname, uts.sysname);
    strcpy(_nodename, uts.nodename);
    strcpy(_release, uts.release);
    strncpy(_version, uts.version, 30);
    strcpy(_machine, uts.machine);
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
