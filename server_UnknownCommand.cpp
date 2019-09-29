//
// Created by leobellaera on 27/9/19.
//

#include "server_UnknownCommand.h"

#define UNKNOWN_COMMAND_KEY "unknownCommand"
#define UNLOGGED_KEY "clientNotLogged"
#define UNKNOWN_CODE  "500 "
#define UNLOGGED_CODE "530 "

server_UnknownCommand::server_UnknownCommand(std::map<std::string, std::string> &cfg, server_Login& login) :
    cfg(cfg),
    login(login) {}

std::string server_UnknownCommand::execute() {
    login.resetIfNotLogged();
    if (login.userIsLogged()) {
        return UNKNOWN_CODE + cfg.find(UNKNOWN_COMMAND_KEY)->second;
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

server_UnknownCommand::~server_UnknownCommand() {}
