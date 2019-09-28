//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_THCLIENT_H
#define TP_THCLIENT_H

#include "Socket.h"
#include "FtpServer.h"
#include "Thread.h"
#include "DirectoryOrganizer.h"
#include "Login.h"
#include <string>
#include <map>

class ThClient : public Thread {
private:
    std::map<std::string,std::string> &cfg;
    Login login;
    DirectoryOrganizer& dir_organizer;
    Socket& skt;
    //ServerProxy
public:
    ThClient(/*Socket& skt,*/std::map<std::string,std::string>& cfg, DirectoryOrganizer& dir_org);
    void run() override;
    ~ThClient();
};

#endif //TP_THCLIENT_H
