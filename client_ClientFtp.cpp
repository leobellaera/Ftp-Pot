//
// Created by leobellaera on 26/9/19.
//

#include "client_ClientFtp.h"
#include <iostream>
#include <string>

#define QUIT_COMMAND "QUIT"

ClientFtp::ClientFtp(const char* host, const char* service) :
    proxy(host, service) {}

void ClientFtp::run() {
    std::string command;
    std::string answer;
    while (true) {
        std::getline(std::cin, command);
        if (std::cin.eof()) break;
        if (!proxy.executeCommand(command, answer)) {
            return;
        }
        std::cout << answer;
        if (command == QUIT_COMMAND) {
            return;
        }
    }
}

ClientFtp::~ClientFtp() {}
