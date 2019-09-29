//
// Created by leobellaera on 27/9/19.
//

#include "server_SystCommand.h"

#define SYST_KEY "systemInfo"
#define UNLOGGED_KEY "clientNotLogged"
#define SYST_CODE "215 "
#define UNLOGGED_CODE "530 "

server_SystCommand::server_SystCommand(std::map<std::string, std::string> &cfg, server_Login& login) :
    cfg(cfg),
    login(login) {}

std::string server_SystCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return SYST_CODE + cfg.find(SYST_KEY)->second;
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }

}

server_SystCommand::~server_SystCommand() {}
