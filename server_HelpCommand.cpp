//
// Created by leobellaera on 27/9/19.
//

#include "server_HelpCommand.h"

#define HELP_KEY "help"
#define UNLOGGED_KEY "clientNotLogged"
#define UNLOGGED_CODE "530 "
#define HELP_CODE "214 "

server_HelpCommand::server_HelpCommand(std::map<std::string,std::string> &cfg, server_Login& login) :
    cfg(cfg),
    login(login) {}

std::string server_HelpCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return HELP_CODE + cfg.find(HELP_KEY)->second;
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

server_HelpCommand::~server_HelpCommand() {}
