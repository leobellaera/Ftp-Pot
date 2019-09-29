//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_CLIENTFTP_H
#define TP_CLIENTFTP_H

#include "Socket.h"
#include "ClientProxy.h"

class ClientFtp {
private:
    ClientProxy proxy;
public:
    ClientFtp(const char* host, const char* service);
    void run();
    ~ClientFtp();
};

#endif //TP_CLIENTFTP_H
