//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_UNKNOWNCOMMAND_H
#define TP_UNKNOWNCOMMAND_H

#include <string>
#include <map>
#include "Command.h"

class UnknownCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
    Login& login;
public:
    explicit UnknownCommand(std::map<std::string, std::string> &cfg, Login& login);
    std::string& execute() override;
    ~UnknownCommand() override;
};


#endif //TP_UNKNOWNCOMMAND_H
