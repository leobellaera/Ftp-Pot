//
// Created by leobellaera on 27/9/19.
//

#include "QuitCommand.h"

#define ANSWER_KEY "quitSuccess"

QuitCommand::QuitCommand(std::map<std::string, std::string> &cfg) :
   cfg(cfg) {}

std::string QuitCommand::execute() {
    return cfg.find(ANSWER_KEY)->second;
}

QuitCommand::~QuitCommand() {}
