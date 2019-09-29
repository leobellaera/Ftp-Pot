//
// Created by leobellaera on 27/9/19.
//

#include "server_UserCommand.h"

#define USER_KEY "passRequired"
#define CODE "331 "

server_UserCommand::server_UserCommand(std::string &user, std::map<std::string,std::string> &cfg, server_Login& login) :
    user(user),
    cfg(cfg),
    login(login) {}

std::string server_UserCommand::execute() {
    login.enterUser(user);
    return  CODE + cfg.find(USER_KEY)->second;
}

server_UserCommand::~server_UserCommand() {}
