//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_TIME_HPP
#define DAY07_TIME_HPP
#include <ctime>
#include "IMonitorModule.hpp"

class Time : public IMonitorModule
{
public:
    Time();
    ~Time();
    void reload();
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMin();
    int getSec();
    tm *getNow() const;
    Time &operator=(Time const &rhs);

private:
    struct tm * now;
    Time(Time &src);
};


#endif //DAY07_TIME_HPP
