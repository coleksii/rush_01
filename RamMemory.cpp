//
// Created by Chechuha Oleksii on 11/11/17.
//

#include "RamMemory.hpp"

long RamMemory::getVirt_freeMemory() const {
    return virt_freeMemory;
}

long RamMemory::getVirt_UsedMemory() const {
    return virt_Memory;
}


RamMemory::RamMemory() {
    reload();
}

RamMemory::~RamMemory()
{
}

void RamMemory::reload()
{
    loadvirtual_mem();
    PhysicalMemory();
}

void RamMemory::PhysicalMemory()
{
//    std::string used_memory:;
//    std::string unused_memory;
    std::string::size_type pos;
    size_t len = sizeof(_physical_memory);
    sysctlbyname("hw.memsize", &_physical_memory, &len, NULL, 0);
    FILE *ram;
    char buff[1024];
    ram = popen("top -l 1 | grep \"PhysMem:\"", "r");
    fgets(buff, sizeof(buff), ram);
    std::string tmp(buff);
    pos = tmp.find("PhysMem: ");
    used_memory = atol(tmp.substr(pos + 9, 5).c_str());
    pos = tmp.find('(');
    wired_memory = atol(tmp.substr(pos + 1, 5).c_str());
    pos = tmp.find("),");
    unused_memory = atol(tmp.substr(pos + 3, 5).c_str());
}

unsigned long long int RamMemory::getPhysical_memory()
{
    return _physical_memory;
}

void RamMemory::loadvirtual_mem()
{
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
                                          (host_info64_t) &vm_stats, &count))
    {
        long long free_memory = (int64_t) vm_stats.free_count * (int64_t) page_size;

        long long used_memory = ((int64_t) vm_stats.active_count +
                                 (int64_t) vm_stats.inactive_count +
                                 (int64_t) vm_stats.wire_count) * (int64_t) page_size;
        virt_freeMemory = free_memory;
        virt_Memory = used_memory;
    }
}

long RamMemory::getPhys_Used_memory()
{
    return used_memory;
}

long RamMemory::getPhys_Unused_memory()
{
    return unused_memory;
}

long RamMemory::getPhys_Wired_memory()
{
    return wired_memory;
}
