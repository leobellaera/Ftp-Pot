//
// Created by leobellaera on 27/9/19.
//

#include "QuitCommand.h"

#define ANSWER_KEY "quitSuccess"

QuitCommand::QuitCommand(std::map<std::string, std::string> &cfg) :
   answer(cfg.find(ANSWER_KEY)->second) {}

std::string& QuitCommand::execute() {
    return answer;
}

QuitCommand::~QuitCommand() {}
