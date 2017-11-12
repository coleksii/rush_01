//
// Created by Chechuha Oleksii on 11/11/17.
//

#include "RamMemory.hpp"

long RamMemory::getFreeMemory() const {
    return freeMemory;
}

long RamMemory::getUsedMemore() const {
    return usedMemory;
}


RamMemory::RamMemory() {
    reload();
}

RamMemory::~RamMemory() {



}

void RamMemory::PhysicalMemory()
{
    size_t len = sizeof(physical_memory);
    sysctlbyname("hw.memsize", &physical_memory, &len, NULL, 0);
}

void RamMemory::reload()
{
    PhysicalMemory();
}

unsigned long long int RamMemory::getPhysical_memory() const
{
    return physical_memory;
}

//void RamMemory::reload() {
//
//    vm_size_t page_size;
//    mach_port_t mach_port;
//    mach_msg_type_number_t count;
//    vm_statistics64_data_t vm_stats;
//
//    mach_port = mach_host_self();
//    count = sizeof(vm_stats) / sizeof(natural_t);
//    if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
//        KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
//                                          (host_info64_t) &vm_stats, &count)) {
//        long long free_memory = (int64_t) vm_stats.free_count * (int64_t) page_size;
//
//        long long used_memory = ((int64_t) vm_stats.active_count +
//                                 (int64_t) vm_stats.inactive_count +
//                                 (int64_t) vm_stats.wire_count) * (int64_t) page_size;
//        freeMemory = free_memory;
//        usedMemory = used_memory;
//    }
//}