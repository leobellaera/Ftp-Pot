//
// Created by leobellaera on 26/9/19.
//

#include "client_ClientProxy.h"
#include "common_SocketException.h"
#include <vector>
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
        return false;
    }
    return true;
}

void ClientProxy::getServerAnswer(std::string& answer) {
    answer.clear();
    bool last_line = false;
    while (!last_line) {
        answer.append(this->getAnswerLine(&last_line) + MSG_DELIM);
    }
}

std::string ClientProxy::getAnswerLine(bool* last_line) {
    const std::vector<std::string> tokens = {"331", "530", "230", "215", "214",
        "226", "257", "550", "250", "221", "500"};
    std::string line;
    char received_char = '\0';
    while (true) {
        skt.recvMessage(&received_char, 1);
        if (received_char == MSG_DELIM) {
            break;
        }
        line.append(1, received_char);
    }
    std::string code = line.substr(0, 3);
    if (std::find(tokens.begin(), tokens.end(), code) != tokens.end()) {
        *last_line = true;
    }
    return std::move(line);
}

ClientProxy::~ClientProxy() {}