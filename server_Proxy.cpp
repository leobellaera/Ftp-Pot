//
// Created by leobellaera on 28/9/19.
//

#include "server_Proxy.h"

#define DELIM_CHAR '\n'

server_Proxy::server_Proxy(common_Socket skt) :
    skt(std::move(skt)) {}

void server_Proxy::receiveClientCommand(std::string& input) {
    char act = '\0';
    while (act != DELIM_CHAR) {
        skt.recvMessage(&act, 1);
        input.append(1, act);
    }
}

void server_Proxy::sendAnswerToClient(std::string& answer) {
    skt.sendMessage(answer.c_str(), answer.length());
}

void server_Proxy::stopCommunication() {
    skt.close();
}

server_Proxy::~server_Proxy() {}
