//
// Created by Dmytrii Spyrydonov on 12/11/2017.
//

#ifndef RUSH01_IMONITORMODULE_HPP
#define RUSH01_IMONITORMODULE_HPP

class IMonitorModule
{
public:
    IMonitorModule();
    virtual ~IMonitorModule();
    virtual void reload() = 0;
    IMonitorModule &operator=(IMonitorModule const &rhs);
    IMonitorModule(IMonitorModule const &src);
};

#endif //RUSH01_IMONITORMODULE_HPP
