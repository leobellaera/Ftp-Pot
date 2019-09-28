//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_COMMAND_H
#define TP_COMMAND_H

#include <map>
#include <string>
#include "Login.h"

class Command {
public:
    static Command* make_command(std::map<std::string,std::string>& cfg, std::string& command, Login& login);
    virtual std::string& execute() = 0;
    virtual ~Command();
};

#endif //TP_COMMAND_H
