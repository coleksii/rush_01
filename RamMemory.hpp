//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_RAMMEMORY_HPP
#define DAY07_RAMMEMORY_HPP

#include <cstdio>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <iostream>
#include <cstdlib>
#include "IMonitorModule.hpp"

class RamMemory : public IMonitorModule
{

public:
    ~RamMemory();
    RamMemory();
    void reload();
    long getPhys_Used_memory();
    long getPhys_Unused_memory();
    long getPhys_Wired_memory();
    long getVirt_freeMemory() const;
    long getVirt_UsedMemory() const;
    void PhysicalMemory();
    void loadvirtual_mem();
    unsigned long long int getPhysical_memory();

private:
    long virt_freeMemory;
    long virt_Memory;
    unsigned long long _physical_memory;
    long used_memory;
    long unused_memory;
    long wired_memory;
    RamMemory &operator=(RamMemory &rhs);
    RamMemory(RamMemory &src);

};


#endif //DAY07_RAMMEMORY_HPP
