//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_SERVER_PROXY_H
#define TP_SERVER_PROXY_H

#include "common_Socket.h"
#include <string>

class server_Proxy {
private:
    common_Socket skt;
public:
    explicit server_Proxy(common_Socket skt);
    void receiveClientCommand(std::string& input);
    void sendAnswerToClient(std::string& answer);
    void stopCommunication();
    ~server_Proxy();

};

#endif //TP_SERVER_PROXY_H
