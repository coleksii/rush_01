//
// Created by Chechuha Oleksii on 11/11/17.
//

#include <zconf.h>
#include "UserInfo.hpp"

char const *UserInfo::getHost() const{
    return host.c_str();
}

char const *UserInfo::getUser() const{
    return user.c_str();
}

UserInfo::UserInfo() {
    reload();
}

UserInfo::~UserInfo() {

}

void UserInfo::reload() {
    char hostname[100];
    char username[100];
    int l, i;
    l = gethostname(hostname, 100);
    i = getlogin_r(username, 100);
    user = &username[i];
    host = &hostname[l];
}

UserInfo& UserInfo::operator=(UserInfo const &rhs)
{
    this->user = rhs.getUser();
    this->host = rhs.getHost();

    return *this;
}

UserInfo::UserInfo(UserInfo &src)
{
    *this = src;
}