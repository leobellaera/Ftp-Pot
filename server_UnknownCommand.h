//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_UNKNOWNCOMMAND_H
#define TP_SERVER_UNKNOWNCOMMAND_H

#include <string>
#include <map>
#include "server_Command.h"

class server_UnknownCommand : public server_Command {
private:
    std::map<std::string, std::string> &cfg;
    server_Login& login;
public:
    server_UnknownCommand(std::map<std::string, std::string> &cfg, server_Login& login);
    std::string execute() override;
    ~server_UnknownCommand() override;
};


#endif //TP_SERVER_UNKNOWNCOMMAND_H
