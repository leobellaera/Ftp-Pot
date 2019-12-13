//
// Created by leobellaera on 26/9/19.
//

#include "client_ClientProxy.h"
#include "common_SocketException.h"
#include <vector>
#include <algorithm>
#include <iostream>

#define MSG_DELIM '\n'
#define HELP "214"
#define SYST "215"
#define QUIT "221"
#define LIST "226"
#define PASS_S "230"
#define RMD_S "250"
#define PWD "257"
#define USER "331"
#define COMMAND_ERR "530"
#define DIR_FAIL "550"

ClientProxy::ClientProxy(const char* host, const char* service) :
    skt(host, service) {}

bool ClientProxy::executeCommand(std::string &command, std::string &answer) {
    command.append(1, MSG_DELIM);
    try {
        skt.sendMessage(command.c_str(), command.length());
        this->recvSvAnswer(answer);
        command.pop_back();
    } catch (const SocketException &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

void ClientProxy::recvSvAnswer(std::string& answer) {
    answer.clear();
    bool ans_totally_received = false;
    std::string line;
    while (!ans_totally_received) {
        line.clear();
        ans_totally_received = this->recvSvMessage(line);
        answer.append(line + MSG_DELIM);
    }
}

bool ClientProxy::recvSvMessage(std::string &line) {
    const std::vector<std::string> tokens = {HELP, SYST, QUIT,
        LIST, PASS_S, RMD_S, PWD, USER, COMMAND_ERR, DIR_FAIL};
    bool ans_totally_received = false;
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
        ans_totally_received = true;
    }
    return ans_totally_received;
}

ClientProxy::~ClientProxy() {}
