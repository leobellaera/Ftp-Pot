//
// Created by leobellaera on 26/9/19.
//

#include "FtpClient.h"
#include <iostream>
#include <string>

#define QUIT_COMMAND "QUIT"

FtpClient::FtpClient(const char* host, const char* service) : //puede lanzar excepcion!!
    proxy(host, service) {}

void FtpClient::run() {
    std::string command;
    std::string answer;
    while (true) {
        std::getline(std::cin, command);
        if (std::cin.eof()) break;
        if (!proxy.executeCommand(command, answer)) { //podria imprimir x pantalla algo como "error inesperado o algo asi"
            return;
        }
        std::cout << answer << std::endl;
        if (command == QUIT_COMMAND) {
            return;
        }
    }
}

FtpClient::~FtpClient() {}
