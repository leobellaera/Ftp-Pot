//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_PASSCOMMAND_H
#define TP_SERVER_PASSCOMMAND_H

#include <string>
#include <map>
#include "server_Login.h"
#include "server_Command.h"

class server_PassCommand : public server_Command {
private:
    std::map<std::string, std::string> cfg;
    std::string& pass;
    server_Login& login;
public:
    server_PassCommand(std::string& pass, std::map<std::string,std::string>& cfg, server_Login& login);
    std::string execute() override;
    ~server_PassCommand() override;

};

#endif //TP_SERVER_PASSCOMMAND_H
