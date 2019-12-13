//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_CLIENTFTP_H
#define TP_CLIENTFTP_H

#include "common_Socket.h"
#include "client_ClientProxy.h"

class ClientFtp {
private:
    ClientProxy proxy;
public:
    ClientFtp(const char* host, const char* service);
    void run();
    ~ClientFtp();
};

#endif //TP_CLIENTFTP_H
