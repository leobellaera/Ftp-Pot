//
// Created by leobellaera on 28/9/19.
//

#include "RmdCommand.h"

#define RMD_SUCCESS_KEY "rmdSuccess"
#define RMD_FAIL_KEY "rmdFailed"
#define UNLOGGED_KEY "clientNotLogged"

RmdCommand::RmdCommand(std::string& dir_name, std::map<std::string, std::string> &cfg,
        Login& login, DirectoryOrganizer& d) :
    dir_name(dir_name),
    cfg(cfg),
    login(login),
    dir_organizer(d) {}

std::string RmdCommand::execute() {
    login.resetIfNotLogged();
    if (!login.userIsLogged()) {
        return cfg.find(UNLOGGED_KEY)->second;
    } else {
        if (!dir_organizer.removeDir(dir_name)) {
            return cfg.find(RMD_FAIL_KEY)->second;
        } else {
            return cfg.find(RMD_SUCCESS_KEY)->second;
        }
    }
}

RmdCommand::~RmdCommand() {}
