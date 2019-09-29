//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_SERVERPROXY_H
#define TP_SERVERPROXY_H

#include "Socket.h"
#include <string>

class ServerProxy {
private:
    Socket skt;
public:
    explicit ServerProxy(Socket skt);
    void receiveClientCommand(std::string& input);
    void sendAnswerToClient(std::string& answer);
    ~ServerProxy();

};


#endif //TP_SERVERPROXY_H
