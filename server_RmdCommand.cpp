//
// Created by leobellaera on 28/9/19.
//

#include "server_RmdCommand.h"

#define RMD_SUCCESS_KEY "rmdSuccess"
#define RMD_FAIL_KEY "rmdFailed"
#define UNLOGGED_KEY "clientNotLogged"
#define UNLOGGED_CODE "530 "
#define RMD_FAIL_CODE "550 "
#define RMD_SUCCESS_CODE "250 "

server_RmdCommand::server_RmdCommand(std::string& dir_name, std::map<std::string, std::string> &cfg,
                                     server_Login& login, server_DirectoryOrganizer& d) :
    dir_name(dir_name),
    cfg(cfg),
    login(login),
    dir_organizer(d) {}

std::string server_RmdCommand::execute() {
    login.resetIfNotLogged();
    if (!login.userIsLogged()) {
        return cfg.find(UNLOGGED_KEY)->second;
    } else {
        if (!dir_organizer.removeDir(dir_name)) {
            return RMD_FAIL_CODE + cfg.find(RMD_FAIL_KEY)->second;
        } else {
            return RMD_SUCCESS_CODE + cfg.find(RMD_SUCCESS_KEY)->second;
        }
    }
}

server_RmdCommand::~server_RmdCommand() {}
