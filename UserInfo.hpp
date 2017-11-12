//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_USERINFO_HPP
#define DAY07_USERINFO_HPP
#include <iostream>
#include <sys/utsname.h>
#include "IMonitorModule.hpp"

int uname(struct utsname *);

class UserInfo : public IMonitorModule
{
public:
    UserInfo();
    ~UserInfo();
    void reload();
    char const *getHost();
    char const *getUser();

private:
    std::string host;
    std::string user;
    UserInfo &operator=(UserInfo &rhs);
    UserInfo(UserInfo &src);

};


#endif //DAY07_USERINFO_HPP
