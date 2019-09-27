//
// Created by leobellaera on 27/9/19.
//

#include "UserCommand.h"

#define ANSWER_KEY "passRequired"
#define USER_KEY "user"

UserCommand::UserCommand(std::string& command, std::map<std::string,std::string>& cfg, Login) {
    answer = cfg.find(ANSWER_KEY)->second;
    std::string cfg_user = cfg.find(USER_KEY)->second;
    std::string command_user = command.substr(command.find(' ') + 1, command.length());
    if (command_user == cfg_user) {
        login.nextStage();
    }
}

std::string UserCommand::execute() {
    return answer;
}

UserCommand::~UserCommand() {}