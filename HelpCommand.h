//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_HELPCOMMAND_H
#define TP_HELPCOMMAND_H


#include "Command.h"
#include <string>
#include <map>

class HelpCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
    Login& login;
public:
    explicit HelpCommand(std::map<std::string,std::string> &cfg, Login& login);
    std::string& execute() override;
    ~HelpCommand() override;
};

#endif //TP_HELPCOMMAND_H
