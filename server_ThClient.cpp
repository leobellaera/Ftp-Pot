//
// Created by leobellaera on 27/9/19.
//

#include "server_ThClient.h"
#include "server_Command.h"
#include "common_SocketException.h"
#include <iostream>

#define QUIT_COMMAND "QUIT"

server_ThClient::server_ThClient(common_Socket skt, std::map<std::string,std::string> &cfg, server_DirectoryOrganizer& dir_org) :
    cfg(cfg),
    login(cfg),
    dir_organizer(dir_org),
    proxy(std::move(skt)),
    finished(false) {}

void server_ThClient::run() {
    std::string input;
    while (!finished) {
        try {
            this->executeCommand(input);
        } catch (const common_SocketException& e) {
            finished = true;
            return;
        }
        if (input == QUIT_COMMAND) {
            finished = true;
        }
    }
}

void server_ThClient::executeCommand(std::string& input) {
    proxy.receiveClientCommand(input);
    server_Command* command = server_Command::make_command(cfg, input, login, dir_organizer);
    std::string answer = command->execute();
    proxy.sendAnswerToClient(answer);
    delete command;
}

bool server_ThClient::isAlive() {
    return !finished;
}

void server_ThClient::stop() {
    proxy.stopCommunication();
}

server_ThClient::~server_ThClient() {}
