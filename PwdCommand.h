//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_PWDCOMMAND_H
#define TP_PWDCOMMAND_H

#include "Command.h"
#include <map>
#include <string>

class PwdCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
    Login& login;
public:
    explicit PwdCommand(std::map<std::string,std::string> &cfg, Login& login);
    std::string& execute() override;
    ~PwdCommand() override;

};

#endif //TP_PWDCOMMAND_H
