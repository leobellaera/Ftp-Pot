//
// Created by leobellaera on 27/9/19.
//

#include "server_ThClient.h"
#include "server_Command.h"
#include "common_SocketException.h"

#define QUIT_COMMAND "QUIT"
#define NEW_CLIENT_CODE "220 "
#define NEW_CLIENT_KEY "newClient"

ThClient::ThClient(Socket skt,
        std::map<std::string,std::string> &cfg,
        DirectoryOrganizer& dir_org) :
    cfg(cfg),
    login(cfg),
    dir_organizer(dir_org),
    proxy(std::move(skt)),
    finished(false) {}

void ThClient::run() {
    std::string input;
    this->sendWelcomeMsgToClient();
    while (!finished) {
        input.clear();
        try {
            proxy.receiveClientCommand(input);
            this->executeCommand(input);
        } catch (const SocketException& e) {
            finished = true;
            return;
        }
        if (input == QUIT_COMMAND) {
            finished = true;
        }
    }
}

void ThClient::sendWelcomeMsgToClient() {
    try {
        std::string msg = NEW_CLIENT_CODE + cfg.find(NEW_CLIENT_KEY)->second;
        proxy.sendMsgToClient(msg);
    } catch (const SocketException& e) {
        finished = true;
    }
}

void ThClient::executeCommand(std::string& input) {
    Command* command = Command::make_command(cfg, input, login, dir_organizer);
    std::string answer = command->execute();
    proxy.sendMsgToClient(answer);
    delete command;
}

bool ThClient::isAlive() {
    return !finished;
}

void ThClient::stop() {
    proxy.stopCommunication();
}

ThClient::~ThClient() {}
