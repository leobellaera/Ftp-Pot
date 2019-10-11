//
// Created by leobellaera on 27/9/19.
//

#include "server_PassCommand.h"

#define LOGIN_SUCCESS_KEY "loginSuccess"
#define LOGIN_FAIL_KEY "loginFailed"
#define LOGIN_FAIL_CODE "530 "
#define LOGIN_SUCCESS_CODE "230 "

PassCommand::PassCommand(std::string& pass,
        std::map<std::string,std::string>& cfg, Login& login) :
    cfg(cfg),
    pass(std::move(pass)),
    login(login) {}

std::string PassCommand::execute() {
    login.enterPassword(pass);
    if (login.userIsLogged()) {
        return LOGIN_SUCCESS_CODE + cfg.find(LOGIN_SUCCESS_KEY)->second;
    } else {
        return LOGIN_FAIL_CODE + cfg.find(LOGIN_FAIL_KEY)->second;
    }
}

PassCommand::~PassCommand() {}
