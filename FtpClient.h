//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_FTPCLIENT_H
#define TP_FTPCLIENT_H

#include "Socket.h"
#include "ClientProxy.h"

class FtpClient {
private:
    ClientProxy proxy;
public:
    FtpClient(const char* host, const char* service);
    void run();
    ~FtpClient();
};

#endif //TP_FTPCLIENT_H
