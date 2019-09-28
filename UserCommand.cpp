//
// Created by leobellaera on 27/9/19.
//

#include "UserCommand.h"

#define USER_KEY "passRequired"

UserCommand::UserCommand(std::string &user, std::map<std::string,std::string> &cfg, Login& login) :
    user(user),
    cfg(cfg),
    login(login) {}

std::string UserCommand::execute() {
    login.enterUser(user);
    return cfg.find(USER_KEY)->second;
}

UserCommand::~UserCommand() {}
