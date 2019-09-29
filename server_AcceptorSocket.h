//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SERVER_ACCEPTORSOCKET_H
#define TP_SERVER_ACCEPTORSOCKET_H

#include "common_Socket.h"

class server_AcceptorSocket {
private:
    int fd;
    int getAddressInfo(struct addrinfo **addrinfo_ptr, const char* service);
    int bindAndListen(int backlog, const char* service);
    int listen(int backlog);
    int bind(struct addrinfo* ptr);
public:
    server_AcceptorSocket(int backlog, const char* service);
    common_Socket accept();
    void close();
    ~server_AcceptorSocket();
};


#endif //TP_SERVER_ACCEPTORSOCKET_H
