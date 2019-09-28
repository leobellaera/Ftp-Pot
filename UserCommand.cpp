//
// Created by leobellaera on 27/9/19.
//

#include "UserCommand.h"

#define USER_KEY "passRequired"

UserCommand::UserCommand(std::string& command, std::map<std::string,std::string>& cfg, Login& login) :
    answer(cfg.find(USER_KEY)->second) {
}

std::string& UserCommand::execute() {
    return answer;
}

UserCommand::~UserCommand() {}
