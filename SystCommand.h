//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SYSTCOMMAND_H
#define TP_SYSTCOMMAND_H

#include "Command.h"
#include <map>
#include <string>

class SystCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
    Login& login;
public:
    explicit SystCommand(std::map<std::string, std::string> &cfg, Login& login);
    std::string& execute() override;
    ~SystCommand();
};


#endif //TP_SYSTCOMMAND_H
