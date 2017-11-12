//
// Created by Chechuha Oleksii on 11/11/17.
//

#include "Time.hpp"

Time::Time()
{
    reload();
}

Time::~Time()
{}

void Time::reload()
{
    time_t t = time(0);
    now = localtime( & t );
}
int Time::getYear()
{
    return now->tm_year;
}

int Time::getMonth()
{
    return now->tm_mon;
}

int Time::getDay()
{
    return now->tm_mday;
}

int Time::getHour()
{
    return now->tm_hour;
}

int Time::getMin()
{
    return now->tm_min;
}

int Time::getSec()
{
    return now->tm_sec;
}

tm *Time::getNow() const
{
    return now;
}

Time& Time::operator=(Time &rhs)
{
    this->now = rhs.getNow();

    return *this;
}

Time::Time(Time &src)
{
    *this = src;
}
