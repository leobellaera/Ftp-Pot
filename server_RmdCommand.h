//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_RMDCOMMAND_H
#define TP_RMDCOMMAND_H

#include "server_Command.h"
#include "server_Login.h"
#include "server_DirectoryOrganizer.h"
#include <map>
#include <string>

class RmdCommand : public Command {
private:
    std::string& dir_name;
    std::map<std::string, std::string>& cfg;
    Login& login;
    DirectoryOrganizer& dir_organizer;
public:
    RmdCommand(std::string& dir_name,
               std::map<std::string, std::string> &cfg,
               Login& login, DirectoryOrganizer& d);
    std::string execute() override;
    ~RmdCommand() override;
};


#endif //TP_RMDCOMMAND_H
