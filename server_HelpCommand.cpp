//
// Created by leobellaera on 27/9/19.
//

#include "server_HelpCommand.h"

#define HELP_KEY "help"
#define UNLOGGED_KEY "clientNotLogged"
#define UNLOGGED_CODE "530 "
#define HELP_CODE "214 "

HelpCommand::HelpCommand(std::map<std::string,std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}

std::string HelpCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return HELP_CODE + cfg.find(HELP_KEY)->second;
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

HelpCommand::~HelpCommand() {}
