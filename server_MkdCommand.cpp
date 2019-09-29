//
// Created by leobellaera on 28/9/19.
//

#include "server_MkdCommand.h"

#define MKD_SUCCESS_KEY "mkdSuccess"
#define MKD_FAIL_KEY "mkdFailed"
#define UNLOGGED_KEY "clientNotLogged"
#define UNLOGGED_CODE "530 "
#define MKD_SUCCESS_CODE "257 "
#define MKD_FAIL_CODE "550 "

MkdCommand::MkdCommand(std::string& dir_name, std::map<std::string, std::string> &cfg,
                       Login& login, DirectoryOrganizer& d) :
        dir_name(dir_name),
        cfg(cfg),
        login(login),
        dir_organizer(d) {}

std::string MkdCommand::execute() {
    login.resetIfNotLogged();
    if (!login.userIsLogged()) {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    } else {
        if (!dir_organizer.makeDir(dir_name)) {
            return MKD_FAIL_CODE + cfg.find(MKD_FAIL_KEY)->second;
        } else {
            return MKD_SUCCESS_CODE + cfg.find(MKD_SUCCESS_KEY)->second;
        }
    }
}

MkdCommand::~MkdCommand() {}
