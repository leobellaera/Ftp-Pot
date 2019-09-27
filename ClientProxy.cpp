//
// Created by leobellaera on 26/9/19.
//

#include "ClientProxy.h"
#include "SocketException.h"
#include <iostream>

#define MSG_DELIM '\n'

ClientProxy::ClientProxy(const char* host, const char* service) :
    skt(host, service) {}

bool ClientProxy::executeCommand(std::string &command, std::string &answer) {
    answer.clear(); //string content remove
    command.append(MSG_DELIM);
    char received_char = '\0';
    try {
        skt.sendMessage(command.c_str(), command.length());
        while (received_char != MSG_DELIM) {
            skt.recvMessage(&received_char, 1);
            answer.append(&received_char, 1);
        }
    } catch (const SocketException &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

ClientProxy::~ClientProxy() {}