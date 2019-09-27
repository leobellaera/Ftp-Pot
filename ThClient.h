//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_THCLIENT_H
#define TP_THCLIENT_H

#include "Socket.h"
#include "FtpServer.h"
#include "Thread.h"
#include <string>
#include <map>

#define UNLOGGED 0
#define USER_RECEIVED 1
#define LOGGED 2

class ThClient : public Thread {
private:
    std::map<std::string,std::string>& cfg;
    //Socket& skt;
    //ServerProxy
public:
    explicit ThClient(/*Socket& skt,*/std::map<std::string,std::string>& cfg); // tambien recibe ' *Directories& d '
    void run() override;
    ~ThClient();
};


#endif //TP_THCLIENT_H


//LoginChecker ifnotcommandavailable(command) clientNotLogged
//LoginChecker log_checker; esto vivira adentro de la clase "Command"