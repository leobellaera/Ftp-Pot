//
// Created by leobellaera on 28/9/19.
//

#include "MkdCommand.h"

#define MKD_SUCCESS_KEY "mkdSuccess"
#define MKD_FAIL_KEY "mkdFailed"
#define UNLOGGED_KEY "clientNotLogged"

MkdCommand::MkdCommand(std::string& dir_name, std::map<std::string, std::string> &cfg,
        Login& login, DirectoryOrganizer& d) :
        dir_name(dir_name),
        cfg(cfg),
        login(login),
        dir_organizer(d) {}

std::string MkdCommand::execute() {
    login.resetIfNotLogged();
    if (!login.userIsLogged()) {
        return cfg.find(UNLOGGED_KEY)->second;
    } else {
        if (!dir_organizer.makeDir(dir_name)) {
            return cfg.find(MKD_FAIL_KEY)->second;
        } else {
            return cfg.find(MKD_SUCCESS_KEY)->second;
        }
    }
}

MkdCommand::~MkdCommand() {}
