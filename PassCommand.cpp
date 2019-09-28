//
// Created by leobellaera on 27/9/19.
//

#include "PassCommand.h"

#define LOGIN_SUCCESS_KEY "loginSuccess"
#define LOGIN_FAIL_KEY "loginFailed"

PassCommand::PassCommand(std::string& command, std::map<std::string,std::string>& cfg, Login& login) :
    cfg(cfg),
    login(login) {
}

std::string& PassCommand::execute() {
    if (login.logged()) {
        return cfg.find(LOGIN_SUCCESS_KEY)->second;
    } else {
        return cfg.find(LOGIN_FAIL_KEY)->second;
    }
}

PassCommand::~PassCommand() {}
