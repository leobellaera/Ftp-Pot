//
// Created by leobellaera on 27/9/19.
//

#include "HelpCommand.h"

#define HELP_KEY "help"
#define UNLOGGED_KEY "clientNotLogged"

HelpCommand::HelpCommand(std::map<std::string,std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}

std::string& HelpCommand::execute() {
    if (login.logged()) {
        return cfg.find(HELP_KEY)->second;
    } else {
        return cfg.find(UNLOGGED_KEY)->second;
    }
}

HelpCommand::~HelpCommand() {}
