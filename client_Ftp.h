//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_CLIENT_FTP_H
#define TP_CLIENT_FTP_H

#include "common_Socket.h"
#include "client_Proxy.h"

class client_Ftp {
private:
    client_Proxy proxy;
public:
    client_Ftp(const char* host, const char* service);
    void run();
    ~client_Ftp();
};

#endif //TP_CLIENT_FTP_H
