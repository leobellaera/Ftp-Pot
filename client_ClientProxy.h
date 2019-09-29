//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_CLIENTPROXY_H
#define TP_CLIENTPROXY_H

#include "Socket.h"
#include <string>

class ClientProxy {
private:
    Socket skt;
    void getServerAnswer(std::string& answer);
public:
    ClientProxy(const char* host, const char* service);
    bool executeCommand(std::string &command, std::string &answer);
    ~ClientProxy();
};

#endif //TP_CLIENTPROXY_H
