//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_CLIENT_PROXY_H
#define TP_CLIENT_PROXY_H

#include "common_Socket.h"
#include <string>

class client_Proxy {
private:
    common_Socket skt;
    void getServerAnswer(std::string& answer);
public:
    client_Proxy(const char* host, const char* service);
    bool executeCommand(std::string &command, std::string &answer);
    ~client_Proxy();
};

#endif //TP_CLIENT_PROXY_H
