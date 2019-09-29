//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_HELPCOMMAND_H
#define TP_SERVER_HELPCOMMAND_H


#include "server_Command.h"
#include <string>
#include <map>

class server_HelpCommand : public server_Command {
private:
    std::map<std::string, std::string> &cfg;
    server_Login& login;
public:
    server_HelpCommand(std::map<std::string,std::string> &cfg, server_Login& login);
    std::string execute() override;
    ~server_HelpCommand() override;
};

#endif //TP_SERVER_HELPCOMMAND_H
