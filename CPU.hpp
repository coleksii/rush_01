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
#include <mach/mach.h>
#include <sys/sysctl.h>


class CPU
{
public:
    CPU();
    virtual ~CPU();
    void reload();
    float get_cpu() const;
    float get_cpu_free() const;
    char const *get_cpu_name();
    int get_cores() const;
    void cpu_load();
    void cpu_info();
private:
    float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
    float _cpu_used;
    float _cpu_free;
    std::string _cpu_name;
    int _cores;

};


#endif //RUSH01_CPU_HPP
