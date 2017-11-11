//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#ifndef RUSH01_OSINFO_HPP
#define RUSH01_OSINFO_HPP

#include <sys/utsname.h>
#include <cstring>

class OSInfo
{
public:
    OSInfo();
    virtual ~OSInfo();
    void reload();

    char *getSysname();

    char *getNodename();

    char *getRelease();

    char *getVersion();

    char *getMachine();

private:
    char	_sysname[_SYS_NAMELEN]; 	/* [XSI] Name of OS */
    char	_nodename[_SYS_NAMELEN];	/* [XSI] Name of this network node */
    char	_release[_SYS_NAMELEN];	/* [XSI] Release level */
    char	_version[_SYS_NAMELEN];	/* [XSI] Version level */
    char	_machine[_SYS_NAMELEN];	/* [XSI] Hardware type */
};


#endif //RUSH01_OSINFO_HPP
