//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_SERVER_LISTCOMMAND_H
#define TP_SERVER_LISTCOMMAND_H

#include "server_Command.h"
#include "server_Login.h"
#include <map>
#include <string>
#include "server_DirectoryOrganizer.h"

class server_ListCommand : public server_Command {
private:
    std::map<std::string, std::string> &cfg;
    server_Login& login;
    server_DirectoryOrganizer& dir_organizer;
public:
    server_ListCommand(std::map<std::string, std::string> &cfg, server_Login& login, server_DirectoryOrganizer& d);
    std::string execute() override;
    ~server_ListCommand() override;
};

#endif //TP_SERVER_LISTCOMMAND_H
