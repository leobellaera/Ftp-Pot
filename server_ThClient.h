//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_THCLIENT_H
#define TP_THCLIENT_H

#include "common_Socket.h"
#include "server_Thread.h"
#include "server_ServerProxy.h"
#include "server_DirectoryOrganizer.h"
#include "server_Login.h"
#include <string>
#include <map>

class ThClient : public Thread {
private:
    std::map<std::string,std::string> &cfg;
    Login login;
    DirectoryOrganizer& dir_organizer;
    ServerProxy proxy;
    bool finished;
    void executeCommand(std::string& input);
    void sendWelcomeMsgToClient();
public:
    ThClient(Socket skt, std::map<std::string,std::string>& cfg, DirectoryOrganizer& dir_org);
    void run() override;
    void stop();
    bool isAlive();
    ~ThClient() override; //override??
};

#endif //TP_THCLIENT_H
