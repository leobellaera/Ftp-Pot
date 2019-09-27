//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_THCLIENT_H
#define TP_THCLIENT_H

#include "Socket.h"
#include <string>
#include <map>

#define UNLOGGED 0
#define USER_RECEIVED 1
#define LOGGED 2

class ThClient {
private:
    Socket skt;
    int login_state;
public:
    ThClient(Socket& skt, Directories d, std::map<std::string,std::string>& map);

};


#endif //TP_THCLIENT_H
