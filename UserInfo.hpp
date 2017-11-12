//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_USERINFO_HPP
#define DAY07_USERINFO_HPP
#include <iostream>
#include <sys/utsname.h>

int uname(struct utsname *);

class UserInfo {
private:
    std::string host;
    std::string user;


public:

    UserInfo();
    void reload();

    char const *getHost();

    char const *getUser();

    virtual ~UserInfo();

};


#endif //DAY07_USERINFO_HPP
