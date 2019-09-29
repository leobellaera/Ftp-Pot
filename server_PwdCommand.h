//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_PWDCOMMAND_H
#define TP_SERVER_PWDCOMMAND_H

#include "server_Command.h"
#include <map>
#include <string>

class server_PwdCommand : public server_Command {
private:
    std::map<std::string, std::string> &cfg;
    server_Login& login;
public:
    server_PwdCommand(std::map<std::string,std::string> &cfg, server_Login& login);
    std::string execute() override;
    ~server_PwdCommand() override;

};

#endif //TP_SERVER_PWDCOMMAND_H
