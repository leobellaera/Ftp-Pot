//
// Created by leobellaera on 27/9/19.
//

#include "QuitCommand.h"

#define ANSWER_KEY "quitSuccess"
#define QUIT_CODE "221 "

QuitCommand::QuitCommand(std::map<std::string, std::string> &cfg) :
   cfg(cfg) {}

std::string QuitCommand::execute() {
    return QUIT_CODE + cfg.find(ANSWER_KEY)->second;
}

QuitCommand::~QuitCommand() {}
