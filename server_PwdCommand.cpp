//
// Created by leobellaera on 27/9/19.
//

#include "server_PwdCommand.h"

#define PWD_KEY "currentDirectoryMsg"
#define UNLOGGED_KEY "clientNotLogged"
#define UNLOGGED_CODE "530 "
#define PWD_CODE "257 "

server_PwdCommand::server_PwdCommand(std::map<std::string,std::string> &cfg, server_Login& login) :
    cfg(cfg),
    login(login) {}


std::string server_PwdCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return PWD_CODE + cfg.find(PWD_KEY)->second;
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

server_PwdCommand::~server_PwdCommand() {}
