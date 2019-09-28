//
// Created by leobellaera on 27/9/19.
//

#include "Login.h"

#define USER_REQUIRED_STAGE 0
#define PASS_REQUIRED_STAGE 1
#define LOGGED_STAGE 2

#define USER_KEY "user"
#define PASS_KEY "pass"

#define USER_COMMAND "COMMAND"
#define PASS_COMMAND "PASS"

Login::Login(std::map<std::string,std::string> &cfg) :
    stage(0) {
    user = cfg.find(USER_KEY)->second;
    pass = cfg.find(PASS_KEY)->second;
}

bool Login::logged() {
    return (stage == LOGGED_STAGE);
}

void Login::updateStage(std::string& command) {
    std::string first_arg = command.substr(0, command.find(' '));
    std::string second_arg = command.substr(command.find(' ') + 1, command.length());
    if (first_arg == USER_COMMAND) {
        stage = USER_REQUIRED_STAGE;
        if (second_arg == user) {
            stage = PASS_REQUIRED_STAGE;
            return;
        }
    } else if (first_arg == PASS_COMMAND){
        if (stage == PASS_REQUIRED_STAGE && second_arg == pass) {
            stage++;
            return;
        }
    } else if (stage == LOGGED_STAGE) return;
    stage = 0;
}

Login::~Login() {}
