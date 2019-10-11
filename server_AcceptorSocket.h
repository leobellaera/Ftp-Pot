//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_ACCEPTORSOCKET_H
#define TP_ACCEPTORSOCKET_H

#include "common_Socket.h"

class AcceptorSocket {
private:
    int fd;
    addrinfo* getAddressInfo(const char* service);
    void bindAndListen(int backlog, const char* service);
    int listen(int backlog);
    int bind(addrinfo* ptr);
public:
    AcceptorSocket(int backlog, const char* service);
    Socket accept();
    void close();
    ~AcceptorSocket();
};


#endif //TP_ACCEPTORSOCKET_H
