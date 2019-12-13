//
// Created by leobellaera on 27/9/19.
//

#include "server_Login.h"

#define USER_REQUIRED_STAGE 0
#define PASS_REQUIRED_STAGE 1
#define LOGGED_STAGE 2

#define USER_KEY "user"
#define PASS_KEY "password"

#define USER_COMMAND "USER"
#define PASS_COMMAND "PASS"

Login::Login(std::map<std::string,std::string> &cfg) :
    stage(0) {
    user = cfg.find(USER_KEY)->second;
    pass = cfg.find(PASS_KEY)->second;
}

bool Login::userIsLogged() {
    return (stage == LOGGED_STAGE);
}

void Login::resetIfNotLogged() {
    if (stage != LOGGED_STAGE) {
        stage = USER_REQUIRED_STAGE;
    }
}

void Login::enterUser(std::string& user) {
    if (this->user == user) {
        stage = PASS_REQUIRED_STAGE;
    }
}

void Login::enterPassword(std::string& pass) {
    if (this->pass == pass && stage == PASS_REQUIRED_STAGE) {
        stage = LOGGED_STAGE;
    }
}

Login::~Login() {}
