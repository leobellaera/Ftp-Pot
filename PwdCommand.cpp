//
// Created by leobellaera on 27/9/19.
//

#include "PwdCommand.h"

#define PWD_KEY "currentDirectoryMsg"
#define UNLOGGED_KEY "clientNotLogged"

PwdCommand::PwdCommand(std::map<std::string,std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}


std::string PwdCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return cfg.find(PWD_KEY)->second;
    } else {
        return cfg.find(UNLOGGED_KEY)->second;
    }
}

PwdCommand::~PwdCommand() {}
