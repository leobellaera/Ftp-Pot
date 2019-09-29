//
// Created by leobellaera on 26/9/19.
//

#include "ClientProxy.h"
#include "SocketException.h"
#include <vector>
#include <iostream>
#include <algorithm>

#define MSG_DELIM '\n'

ClientProxy::ClientProxy(const char* host, const char* service) :
    skt(host, service) {}

bool ClientProxy::executeCommand(std::string &command, std::string &answer) {
    command.append(1, MSG_DELIM);
    try {
        skt.sendMessage(command.c_str(), command.length());
        this->getServerAnswer(answer);

    } catch (const SocketException &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

void ClientProxy::getServerAnswer(std::string& answer) {
    const std::vector<std::string> tokens = {"331", "530", "230", "215", "214",
                                      "226", "257", "550", "250", "221"};
    char received_char = '\0';
    answer.clear();
    int i = 0;
    bool last_line = false;
    while (received_char != MSG_DELIM || !last_line) {
        skt.recvMessage(&received_char, 1);
        answer.append(1, received_char);
        if (i == 2 && std::find(tokens.begin(), tokens.end(), answer) != tokens.end()) {
            last_line = true;
        }
        i++;
    }
}

ClientProxy::~ClientProxy() {}