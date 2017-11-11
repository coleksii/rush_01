//
// Created by Chechuha Oleksii on 11/11/17.
//

#include "Time.hpp"

int Time::getYear() {
    time_t t = time(0);
    now = localtime( & t );
    return now->tm_year;
}

int Time::getMonth(){
    time_t t = time(0);
    now = localtime( & t );
    return now->tm_mon;
}

int Time::getDay() {
    time_t t = time(0);
    now = localtime( & t );
    return now->tm_mday;
}

int Time::getHour() {
    time_t t = time(0);
    now = localtime( & t );
    return now->tm_hour;
}

int Time::getMin() {
    time_t t = time(0);
    now = localtime( & t );
    return now->tm_min;
}

int Time::getSec() {
    time_t t = time(0);
    now = localtime( & t );
    return now->tm_sec;
}
