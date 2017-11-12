#include <iostream>
#include "Ncurses.hpp"
#include "RamMemory.hpp"
#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include <limits.h>
#include <string>

void printTextInfo(){
    UserInfo user;
    OSInfo os;
    CPU cpu;
    RamMemory ram;
    Time time;

    user.reload();
    ram.reload();
    cpu.reload();
    os.reload();
    std::cout << std::endl << "USER INFO" << std::endl;
    std::cout << "Username: " << user.getUser() << std::endl;
    std::cout << "Hostname:" << user.getHost() << std::endl;
    std::cout << "Data: " << time.getYear() + 1900 << " : " << time.getMonth() + 1 << " : " << time.getDay() << std::endl;
    std::cout << "Hours: " << time.getHour() << std::endl;
    std::cout << "Min:   " << time.getMin() << std::endl;
    std::cout << "Sec:   " << time.getSec() << std::endl;
    std::cout << std::endl << "MEMORY INFO" << std::endl;
    std::cout << "Virt Free memory: " << ram.getVirt_freeMemory() / 1024 << std::endl;
    std::cout << "Virt Used memory: " << ram.getVirt_UsedMemory() / 1024 << std::endl;
    std::cout << "Physical memory:  " <<  ram.getPhysical_memory() / 1024 << std::endl;
    std::cout << "Physical used memory:   " << ram.getPhys_Used_memory() << std::endl;
    std::cout << "Physical unused memory: " << ram.getPhys_Unused_memory() << std::endl;
    std::cout << "Physical wired memory:  " << ram.getPhys_Wired_memory() << std::endl;
    std::cout << std::endl << "CPU INFO"<< std::endl;
    std::cout << "CPU name: " << cpu.get_cpu_name() << std::endl;
    std::cout << "CPU cores:" << cpu.get_cores() << std::endl;
    std::cout << "CPU used: " << cpu.get_cpu() * 100 << std::endl;
    std::cout << "CPU free: " << cpu.get_cpu_free() * 100 << std::endl;
    std::cout<< std::endl << "OS INFO" << std::endl << os.get_buff() << std::endl;
}

int main(int gv, char **av)
{

    if (gv > 1 && !strcmp(av[1], "txt")) {
        printTextInfo();
        return (0);
    }

    Ncurses curses;
    curses.allplugins();

    return 0;
}