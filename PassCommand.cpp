//
// Created by leobellaera on 27/9/19.
//

#include "PassCommand.h"

#define LOGIN_SUCCESS_KEY "loginSuccess"
#define LOGIN_FAIL_KEY "loginFailed"

PassCommand::PassCommand(std::string& pass, std::map<std::string,std::string>& cfg, Login& login) :
    cfg(cfg),
    pass(pass),
    login(login) {}

std::string PassCommand::execute() {
    login.enterPassword(pass);
    if (login.userIsLogged()) {
        return cfg.find(LOGIN_SUCCESS_KEY)->second;
    } else {
        return cfg.find(LOGIN_FAIL_KEY)->second;
    }
}

PassCommand::~PassCommand() {}
