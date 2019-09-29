//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_MKDCOMMAND_H
#define TP_MKDCOMMAND_H

#include "server_Command.h"
#include "server_Login.h"
#include "server_DirectoryOrganizer.h"
#include <map>
#include <string>

class MkdCommand : public Command {
private:
    std::string dir_name;
    std::map<std::string, std::string>& cfg;
    Login& login;
    DirectoryOrganizer& dir_organizer;
public:
    MkdCommand(std::string dir_name,
               std::map<std::string, std::string> &cfg,
               Login& login, DirectoryOrganizer& d);
    std::string execute() override;
    ~MkdCommand() override;

};


#endif //TP_MKDCOMMAND_H
