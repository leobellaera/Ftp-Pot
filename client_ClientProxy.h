//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_CLIENTPROXY_H
#define TP_CLIENTPROXY_H

#include "common_Socket.h"
#include <string>

class ClientProxy {
private:
    Socket skt;
    void getServerAnswer(std::string& answer);
    std::string getAnswerLine(bool* last_line);
public:
    ClientProxy(const char* host, const char* service);
    bool executeCommand(std::string &command, std::string &answer);
    ~ClientProxy();
};

#endif //TP_CLIENTPROXY_H
