//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_PASSCOMMAND_H
#define TP_PASSCOMMAND_H

#include <string>
#include <map>
#include "Login.h"
#include "Command.h"

class PassCommand : public Command {
private:
    std::map<std::string, std::string> cfg;
    Login& login;
public:
    PassCommand(std::string& command, std::map<std::string,std::string>& cfg, Login& login);
    std::string& execute() override;
    ~PassCommand();

};

#endif //TP_PASSCOMMAND_H
