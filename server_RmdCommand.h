//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_SERVER_RMDCOMMAND_H
#define TP_SERVER_RMDCOMMAND_H


#include "server_Command.h"
#include "server_Login.h"
#include "server_DirectoryOrganizer.h"
#include <map>
#include <string>

class server_RmdCommand : public server_Command {
private:
    std::string& dir_name;
    std::map<std::string, std::string>& cfg;
    server_Login& login;
    server_DirectoryOrganizer& dir_organizer;
public:
    server_RmdCommand(std::string& dir_name,
                      std::map<std::string, std::string> &cfg,
                      server_Login& login, server_DirectoryOrganizer& d);
    std::string execute() override;
    ~server_RmdCommand() override;
};


#endif //TP_SERVER_RMDCOMMAND_H
