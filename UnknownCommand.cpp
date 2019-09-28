//
// Created by leobellaera on 27/9/19.
//

#include "UnknownCommand.h"

#define UNKNOWN_COMMAND_KEY "unknownCommand"
#define UNLOGGED_KEY "clientNotLogged"

UnknownCommand::UnknownCommand(std::map<std::string, std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}

std::string& UnknownCommand::execute() {
    if (login.logged()) {
       return cfg.find(UNKNOWN_COMMAND_KEY)->second;
    } else {
        return cfg.find(UNLOGGED_KEY)->second;
    }
}

UnknownCommand::~UnknownCommand() {}
