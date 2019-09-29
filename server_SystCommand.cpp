//
// Created by leobellaera on 27/9/19.
//

#include "SystCommand.h"

#define SYST_KEY "systemInfo"
#define UNLOGGED_KEY "clientNotLogged"
#define SYST_CODE "215 "
#define UNLOGGED_CODE "530 "

SystCommand::SystCommand(std::map<std::string, std::string> &cfg, Login& login) :
    cfg(cfg),
    login(login) {}

std::string SystCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return SYST_CODE + cfg.find(SYST_KEY)->second;
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }

}

SystCommand::~SystCommand() {}
