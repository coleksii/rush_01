//
// Created by Chechuha Oleksii on 11/12/17.
//

#ifndef GITRUSH_TEXT_HPP
#define GITRUSH_TEXT_HPP


#include "UserInfo.hpp"
#include "OSInfo.hpp"
#include "RamMemory.hpp"
#include "CPU.hpp"
#include "Time.hpp"

class Text {
private:
    UserInfo user;
    OSInfo os;
    CPU cpu;
    RamMemory ram;
    Time time;
    Text(Text &t);
    Text const &operator=(Text const&t);
public:
    Text();
    virtual ~Text();
    void printTextInfo();


};


#endif //GITRUSH_TEXT_HPP
