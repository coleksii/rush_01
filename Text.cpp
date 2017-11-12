//
// Created by Chechuha Oleksii on 11/12/17.
//

#include "Text.hpp"

Text::Text() {}

Text::~Text() {

}

void Text::printTextInfo() {
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

Text const& Text::operator=(Text const&t){
    this->user = t.user;
    this->cpu = t.cpu;
    this->os = t.os;
    this->ram = t.ram;
    this->time = t.time;
    return *this;
}

Text::Text(Text &t) {
    this->user = t.user;
    this->cpu = t.cpu;
    this->os = t.os;
    this->ram = t.ram;
    this->time = t.time;
}
