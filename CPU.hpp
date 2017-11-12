//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#ifndef RUSH01_CPU_HPP
#define RUSH01_CPU_HPP
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <iostream>


class CPU
{
public:
    CPU();
    virtual ~CPU();
    void reload();
    float get_cpu() const;
    float get_cpu_free() const;

private:
    float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
    float _cpu_used;
    float _cpu_free;

};


#endif //RUSH01_CPU_HPP
