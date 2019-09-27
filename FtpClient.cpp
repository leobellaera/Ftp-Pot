//
// Created by leobellaera on 26/9/19.
//

#include "FtpClient.h"
#include <iostream>
#include <string>

#define QUIT_COMMAND 'QUIT'

FtpClient::FtpClient(const char* host, const char* service) :  //cuando creemos una instancia hacer try catch
    proxy(host, service) {}

void FtpClient::run() {
    bool keep_running = true;
    std::string command;
    std::string answer;
    while (true) {
        std::getline(std::cin, command);
        if (std::cin.eof()) break;
        if (!proxy.executeCommand(command, answer)) {
            return;
        }
        std::cout<<answer;
        if (command == QUIT_COMMAND) {
            return;
        }
    }
}

FtpClient::~FtpClient() {}
