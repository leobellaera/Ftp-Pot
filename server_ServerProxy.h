//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_SERVERPROXY_H
#define TP_SERVERPROXY_H

#include "common_Socket.h"
#include <string>

class ServerProxy {
private:
    Socket skt;
public:
    explicit ServerProxy(Socket skt);
    void receiveClientCommand(std::string& input);
    void sendMsgToClient(std::string& answer);
    void stopCommunication();
    ~ServerProxy();
};

#endif //TP_SERVERPROXY_H
