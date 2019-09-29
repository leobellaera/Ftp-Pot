//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_USERCOMMAND_H
#define TP_USERCOMMAND_H

#include "Command.h"
#include "Login.h"
#include <map>
#include <string>

class UserCommand : public Command {
private:
    std::string& user;
    std::map<std::string,std::string> &cfg;
    Login& login;
public:
    UserCommand(std::string &user, std::map<std::string,std::string> &cfg, Login& login);
    std::string execute() override;
    ~UserCommand() override;
};

#endif //TP_USERCOMMAND_H
