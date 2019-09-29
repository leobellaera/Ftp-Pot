//
// Created by leobellaera on 28/9/19.
//

#include "ServerProxy.h"

#define DELIM_CHAR '\n'

ServerProxy::ServerProxy(Socket skt) :
    skt(std::move(skt)) {}

void ServerProxy::receiveClientCommand(std::string& input) {
    char act = '\0';
    while (act != DELIM_CHAR) {
        skt.recvMessage(&act, 1);
        input.append(1, act);
    }
}

void ServerProxy::sendAnswerToClient(std::string& answer) {
    skt.sendMessage(answer.c_str(), answer.length());
}

void ServerProxy::stopCommunication() {
    skt.close();
}

ServerProxy::~ServerProxy() {}
