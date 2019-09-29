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
    std::string sv_msg;
    proxy.recvSvMessage(sv_msg);
    std::cout<<sv_msg<<std::endl; //welcome msg

    while (true) {
        std::getline(std::cin, command);
        if (std::cin.eof()) break;
        if (!proxy.executeCommand(command, sv_msg)) {
            return;
        }
        std::cout << sv_msg;
        if (command == QUIT_COMMAND) {
            return;
        }
    }
}

ClientFtp::~ClientFtp() {}
