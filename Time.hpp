//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_TIME_HPP
#define DAY07_TIME_HPP
#include <ctime>

class Time{
private:
    struct tm * now;
public:

    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMin();
    int getSec();

};


#endif //DAY07_TIME_HPP
