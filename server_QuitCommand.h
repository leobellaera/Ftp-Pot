//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_QUITCOMMAND_H
#define TP_SERVER_QUITCOMMAND_H

#include <string>
#include <map>
#include "server_Command.h"

class server_QuitCommand : public server_Command {
private:
    std::map<std::string, std::string> &cfg;
public:
    explicit server_QuitCommand(std::map<std::string,std::string> &cfg);
    std::string execute() override;
    ~server_QuitCommand() override;
};

#endif //TP_SERVER_QUITCOMMAND_H
