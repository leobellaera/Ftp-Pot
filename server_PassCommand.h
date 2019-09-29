//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_PASSCOMMAND_H
#define TP_PASSCOMMAND_H

#include <string>
#include <map>
#include "server_Login.h"
#include "server_Command.h"

class PassCommand : public Command {
private:
    std::map<std::string, std::string> cfg;
    std::string pass;
    Login& login;
public:
    PassCommand(std::string pass, std::map<std::string,std::string>& cfg, Login& login);
    std::string execute() override;
    ~PassCommand() override;

};

#endif //TP_PASSCOMMAND_H
