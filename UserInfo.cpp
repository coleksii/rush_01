//
// Created by Chechuha Oleksii on 11/11/17.
//

#include <zconf.h>
#include "UserInfo.hpp"

char *UserInfo::getHost() const {
    return host;
}

char *UserInfo::getUser() const {
    return user;
}

UserInfo::UserInfo() {
    char hostname[100];
    char username[100];
    int l, i;
    l = gethostname(hostname, 100);
    i = getlogin_r(username, 100);
    user = &username[l];
    host = &hostname[i];
}

UserInfo::~UserInfo() {

}
