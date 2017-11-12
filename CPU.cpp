//
// Created by Dmytrii Spyrydonov on 11/11/17.
//

#include "CPU.hpp"

CPU::CPU()
{
    reload();
}

CPU::~CPU()
{

}

static unsigned long long _previousTotalTicks = 0;
static unsigned long long _previousIdleTicks = 0;


float CPU::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
    unsigned long long totalTicksSinceLastTime = totalTicks-_previousTotalTicks;
    unsigned long long idleTicksSinceLastTime  = idleTicks-_previousIdleTicks;
    float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
    _previousTotalTicks = totalTicks;
    _previousIdleTicks  = idleTicks;
    return ret;
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.

void CPU::cpu_load()
{
    host_cpu_load_info_data_t cpuinfo;
    mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
    if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
    {
        unsigned long long totalTicks = 0;
        for(int i=0; i<CPU_STATE_MAX; i++) totalTicks += cpuinfo.cpu_ticks[i];
        _cpu_used = CalculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks);
        _cpu_free = 1 - _cpu_used;
    }
    else {
        _cpu_used = -1.0f;
        _cpu_free = 0;
    }
}

//void CPU::cpu_info()
//{
//    mach_port_t self = host_self();
//    kern_return_t rc;
//    char buf[1024]; // suffices. Better code would sizeof(..info)
//    host_basic_info_t hi;
//    int len = 1024;
//    // Getting the host info is simply a matter of calling host_info
//    // on the host_self(). We do not need the privileged host port for
//    // this..
//    rc = host_info (self, HOST_BASIC_INFO,(host_info_t) buf, &len); // mach_msg_type_number_t *host_info_outCnt
//    hi = (host_basic_info_t) buf; // type cast, so we can print fields
//    // and print fields..
//    printf ("CPUs:\t\t %d/%d\n", hi->avail_cpus, hi->max_cpus);
//    printf ("Physical CPUs:\t %d/%d\n", hi->physical_cpu, hi->physical_cpu_max);
//    printf ("Logical CPUs:\t %d/%d\n", hi->logical_cpu, hi->logical_cpu_max);
//    printf ("CPU type:\t %d/%d, Threadtype: %d\n", hi->cpu_type,
//            hi->cpu_subtype, hi->cpu_threadtype);
//    // Note memory_size is a signed 32-bit! Max value is 2GB, then it flips to negative
//    printf ("Memory size:\t %d/%ld\n", hi->memory_size, hi->max_mem);
//}

void CPU::reload()
{
    cpu_load();

}

float CPU::get_cpu() const
{
    return _cpu_used;
}

float CPU::get_cpu_free() const
{
    return _cpu_free;
}

//int main()
//{
//    std::cout << GetCPULoad() << std::endl;
//    return 0;
//}