//
// Created by leobellaera on 28/9/19.
//

#include "ThAcceptor.h"

ThAcceptor::ThAcceptor(DirectoryOrganizer& dir_organizer, std::map<std::string, std::string>& cfg, const char* service, int backlog) :
    acceptor_skt(backlog, service),
    dir_organizer(dir_organizer),
    cfg(cfg) {}


void ThAcceptor::run() {

}

void ThAcceptor::stop() {
    acceptor_skt.close();
}

ThAcceptor::~ThAcceptor() {}
