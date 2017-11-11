//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_USERINFO_HPP
#define DAY07_USERINFO_HPP
#include <iostream>

class UserInfo {
private:
    char *host;
    char *user;

public:

    UserInfo();
    void reload();

    char *getHost() const;

    char *getUser() const;

    virtual ~UserInfo();

};


#endif //DAY07_USERINFO_HPP
