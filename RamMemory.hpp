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

class RamMemory {
private:
    long virt_freeMemory;
    long virt_Memory;
    unsigned long long _physical_memory;
    std::string used_memory;
    std::string unused_memory;
    std::string wired_memory;

public:
    ~RamMemory();
    RamMemory();
    void reload();
    const std::string &getPhys_Used_memory() const;
    const std::string &getPhys_Unused_memory() const;
    const std::string &getPhys_Wired_memory() const;
    long getVirt_freeMemory() const;
    long getVirt_UsedMemory() const;
    void PhysicalMemory();
    void loadvirtual_mem();
    unsigned long long int getPhysical_memory();

};


#endif //DAY07_RAMMEMORY_HPP
