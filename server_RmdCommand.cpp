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
#define DIR_DELIM '"'

RmdCommand::RmdCommand(std::string dir_name, std::map<std::string, std::string> &cfg,
                       Login& login, DirectoryOrganizer& d) :
    dir_name(std::move(dir_name)),
    cfg(cfg),
    login(login),
    dir_organizer(d) {}

std::string RmdCommand::execute() {
    login.resetIfNotLogged();
    if (!login.userIsLogged()) {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    } else {
        if (!dir_organizer.removeDir(dir_name)) {
            return RMD_FAIL_CODE + cfg.find(RMD_FAIL_KEY)->second;
        } else {
            std::string ans = RMD_SUCCESS_CODE;
            ans.append(DIR_DELIM + dir_name + DIR_DELIM);
            ans.append(' ' + cfg.find(RMD_SUCCESS_KEY)->second);
            return ans;
        }
    }
}

RmdCommand::~RmdCommand() {}
