//
// Created by leobellaera on 27/9/19.
//

#include "ThClient.h"
#include "Command.h"
#include <iostream>

#define QUIT_COMMAND "QUIT"

ThClient::ThClient(/*Socket& skt,*/ std::map<std::string,std::string>& cfg) :
    cfg(cfg),
    login(cfg) {}

void ThClient::run() {
    /* esto despues se realizara mediante socket*/
    std::string input;
    std::getline(std::cin, input);
    //***********************************

    Command*  command = Command::make_command(cfg, input, login);
    std::string& answer = command->execute();
    std::cout << answer << std::endl; //esto despues sera un svproxy.sendAnswer

    if (input == QUIT_COMMAND) {
        return;
    }
}

ThClient::~ThClient() {}
