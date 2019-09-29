//
// Created by leobellaera on 27/9/19.
//

#include "server_QuitCommand.h"

#define ANSWER_KEY "quitSuccess"
#define QUIT_CODE "221 "

server_QuitCommand::server_QuitCommand(std::map<std::string, std::string> &cfg) :
   cfg(cfg) {}

std::string server_QuitCommand::execute() {
    return QUIT_CODE + cfg.find(ANSWER_KEY)->second;
}

server_QuitCommand::~server_QuitCommand() {}
