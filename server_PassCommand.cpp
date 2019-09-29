//
// Created by leobellaera on 27/9/19.
//

#include "server_PassCommand.h"

#define LOGIN_SUCCESS_KEY "loginSuccess"
#define LOGIN_FAIL_KEY "loginFailed"
#define LOGIN_FAIL_CODE "530 "
#define LOGIN_SUCCESS_CODE "230 "

server_PassCommand::server_PassCommand(std::string& pass, std::map<std::string,std::string>& cfg, server_Login& login) :
    cfg(cfg),
    pass(pass),
    login(login) {}

std::string server_PassCommand::execute() {
    login.enterPassword(pass);
    if (login.userIsLogged()) {
        return LOGIN_SUCCESS_CODE + cfg.find(LOGIN_SUCCESS_KEY)->second;
    } else {
        return LOGIN_FAIL_CODE + cfg.find(LOGIN_FAIL_KEY)->second;
    }
}

server_PassCommand::~server_PassCommand() {}
