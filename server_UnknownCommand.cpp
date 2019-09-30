//
// Created by leobellaera on 27/9/19.
//

#include "server_UnknownCommand.h"

#define UNKNOWN_COMMAND_KEY "unknownCommand"
#define UNLOGGED_KEY "clientNotLogged"
#define CODE  "530 "

UnknownCommand::UnknownCommand(std::map<std::string,
        std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}

std::string UnknownCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return CODE + cfg.find(UNKNOWN_COMMAND_KEY)->second;
    } else {
        return CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

UnknownCommand::~UnknownCommand() {}
