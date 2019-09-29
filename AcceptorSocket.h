//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_ACCEPTORSOCKET_H
#define TP_ACCEPTORSOCKET_H

#include "Socket.h"

class AcceptorSocket {
private:
    int fd;
    int getAddressInfo(struct addrinfo **addrinfo_ptr, const char* service);
    int bindAndListen(int backlog, const char* service);
    int listen(int backlog);
    int bind(struct addrinfo* ptr);
public:
    AcceptorSocket(int backlog, const char* service);
    Socket acceptClient();
    void close();
    ~AcceptorSocket();
};


#endif //TP_ACCEPTORSOCKET_H
