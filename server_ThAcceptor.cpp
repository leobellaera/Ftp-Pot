//
// Created by leobellaera on 28/9/19.
//

#include "server_ThAcceptor.h"
#include "common_SocketException.h"
#include "server_ThClient.h"
#include <iostream>

ThAcceptor::ThAcceptor(DirectoryOrganizer& dir_organizer, std::map<std::string, std::string>& cfg, const char* service, int backlog) :
    acceptor_skt(backlog, service),
    dir_organizer(dir_organizer),
    cfg(cfg) {}


void ThAcceptor::run() {
    while (true) {
        try {
            Socket skt = acceptor_skt.accept();
            ThClient* thclient = new ThClient(std::move(skt), cfg, dir_organizer);
            thclient->start();
            clients.push_back(thclient);
        } catch (const SocketException &e) {
            std::cerr << e.what();
            return;
        }
        this->deleteDeadClients();
    }
}

void ThAcceptor::deleteDeadClients() {
    auto it = clients.begin();
    while (it != clients.end()) {
        if ((*it)->isAlive()) {
            ++it;
        } else {
            (*it)->join();
            delete (*it);
            it = clients.erase(it);
        }
    }
}

void ThAcceptor::stop() {
    int size = clients.size();
    for (int i = 0; i < size; i++) {
        clients[i]->stop();
        clients[i]->join();
        delete clients[i];
    }
    acceptor_skt.close();
}

ThAcceptor::~ThAcceptor() {}
