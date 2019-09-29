//
// Created by leobellaera on 26/9/19.
//

#include "server_ServerFtp.h"
#include <iostream>

#define STOP_SV_KEY 'q'

ServerFtp::ServerFtp(const char* config_path, const char* service, int backlog) :
    map_builder(config_path),
    acceptor_thread(dir_organizer, map_builder.getMap(), service, backlog) {}

void ServerFtp::run() {
    acceptor_thread.start();
    char c = '\0';
    while (c != STOP_SV_KEY) {
        std::cin >> c;
    }
    acceptor_thread.stop();
    acceptor_thread.join();
}

ServerFtp::~ServerFtp() {}
