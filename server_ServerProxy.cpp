//
// Created by leobellaera on 28/9/19.
//

#include "server_ServerProxy.h"

#define DELIM_CHAR '\n'

ServerProxy::ServerProxy(Socket skt) :
    skt(std::move(skt)) {}

void ServerProxy::receiveClientCommand(std::string& input) {
    char act;
    while (true) {
        skt.recvMessage(&act, 1);
        if (act == DELIM_CHAR) {
            return;
        }
        input.append(1, act);
    }
}

void ServerProxy::sendAnswerToClient(std::string& answer) {
    answer.append(1, '\n');
    skt.sendMessage(answer.c_str(), answer.length());
}

void ServerProxy::stopCommunication() {
    skt.close();
}

ServerProxy::~ServerProxy() {}
