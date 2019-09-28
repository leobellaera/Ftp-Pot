//
// Created by leobellaera on 27/9/19.
//

#include "SystCommand.h"

#define SYST_KEY "systemInfo"
#define UNLOGGED_KEY "clientNotLogged"

SystCommand::SystCommand(std::map<std::string, std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}

std::string& SystCommand::execute() {
    if (login.logged()) {
        return cfg.find(SYST_KEY)->second;
    } else {
        return cfg.find(UNLOGGED_KEY)->second;
    }
}

SystCommand::~SystCommand() {}
