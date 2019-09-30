//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_LISTCOMMAND_H
#define TP_LISTCOMMAND_H

#include "server_Command.h"
#include "server_Login.h"
#include <map>
#include <string>
#include "server_DirectoryOrganizer.h"

class ListCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
    Login& login;
    DirectoryOrganizer& dir_organizer;
public:
    ListCommand(std::map<std::string, std::string> &cfg,
                Login& login,
                DirectoryOrganizer& d);
    std::string execute() override;
    ~ListCommand() override;
};

#endif //TP_LISTCOMMAND_H
