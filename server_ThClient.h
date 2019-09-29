//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_THCLIENT_H
#define TP_SERVER_THCLIENT_H

#include "common_Socket.h"
#include "server_Thread.h"
#include "server_Proxy.h"
#include "server_DirectoryOrganizer.h"
#include "server_Login.h"
#include <string>
#include <map>

class server_ThClient : public server_Thread {
private:
    std::map<std::string,std::string> &cfg;
    server_Login login;
    server_DirectoryOrganizer& dir_organizer;
    server_Proxy proxy;
    bool finished;
    void executeCommand(std::string& input);
public:
    server_ThClient(common_Socket skt, std::map<std::string,std::string>& cfg, server_DirectoryOrganizer& dir_org);
    void run() override;
    void stop();
    bool isAlive();
    ~server_ThClient() override; //override??
};

#endif //TP_SERVER_THCLIENT_H
