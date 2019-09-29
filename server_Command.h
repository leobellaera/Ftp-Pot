//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_COMMAND_H
#define TP_SERVER_COMMAND_H

#include <map>
#include <string>
#include "server_Login.h"
#include "server_DirectoryOrganizer.h"

class server_Command {
public:
    static server_Command* make_command(std::map<std::string,std::string>& cfg,
                                        std::string& command,
                                        server_Login& login,
                                        server_DirectoryOrganizer& dir_org);
    virtual std::string execute() = 0;
    virtual ~server_Command();
};

#endif //TP_SERVER_COMMAND_H
