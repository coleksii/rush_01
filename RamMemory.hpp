//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_RAMMEMORY_HPP
#define DAY07_RAMMEMORY_HPP

#include <stdio.h>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

class RamMemory {
private:
    long freeMemory;
    long usedMemory;
    unsigned long long physical_memory;
public:
    ~RamMemory();
    RamMemory();
    void PhysicalMemory();

    void reload();
    long getFreeMemory() const;
    long getUsedMemore() const;

    unsigned long long int getPhysical_memory() const;

};


#endif //DAY07_RAMMEMORY_HPP
