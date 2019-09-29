//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_SYSTCOMMAND_H
#define TP_SERVER_SYSTCOMMAND_H

#include "server_Command.h"
#include <map>
#include <string>

class server_SystCommand : public server_Command {
private:
    std::map<std::string, std::string> &cfg;
    server_Login& login;
public:
    server_SystCommand(std::map<std::string, std::string> &cfg, server_Login& login);
    std::string execute() override;
    ~server_SystCommand() override;
};


#endif //TP_SERVER_SYSTCOMMAND_H
