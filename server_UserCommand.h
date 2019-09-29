//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_USERCOMMAND_H
#define TP_SERVER_USERCOMMAND_H

#include "server_Command.h"
#include "server_Login.h"
#include <map>
#include <string>

class server_UserCommand : public server_Command {
private:
    std::string& user;
    std::map<std::string,std::string> &cfg;
    server_Login& login;
public:
    server_UserCommand(std::string &user, std::map<std::string,std::string> &cfg, server_Login& login);
    std::string execute() override;
    ~server_UserCommand() override;
};

#endif //TP_SERVER_USERCOMMAND_H
