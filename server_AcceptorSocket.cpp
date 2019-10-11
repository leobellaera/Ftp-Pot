//
// Created by leobellaera on 26/9/19.
//

#include "server_AcceptorSocket.h"
#include "common_SocketException.h"
#include <cerrno>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <iostream>

#define ACCEPT_ERROR_MSG "Error occurred while trying to accept client\n"
#define BIND_AND_LISTEN_ERR_MSG "Error occurred while trying to bind and listen\n"

AcceptorSocket::AcceptorSocket(int backlog, const char* service) :
    fd(-1) {
    this->bindAndListen(backlog, service);
}

Socket AcceptorSocket::accept() {
    int peer_fd = ::accept(fd, nullptr, nullptr);
    if (peer_fd == -1){
        throw SocketException(ACCEPT_ERROR_MSG);
    }
    return std::move(Socket(peer_fd));
}

void AcceptorSocket::bindAndListen(int backlog, const char* service) {
    addrinfo* result = this->getAddressInfo(service);
    bool done = false;
    struct addrinfo *ptr = nullptr;
    for (ptr = result; ptr != nullptr && !done ; ptr = ptr->ai_next) {
        fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (fd == -1) {
            std::cerr << "Error: " << strerror(errno) << std::endl;
        }
        if (bind(ptr) == 0 && listen(backlog) == 0) {
            done = true;
        }
    }
    freeaddrinfo(result);
    if (!done) {
        this->close();
        throw SocketException(BIND_AND_LISTEN_ERR_MSG);
    }
}

int AcceptorSocket::bind(addrinfo* ptr) {
    int s = ::bind(fd, ptr->ai_addr, ptr->ai_addrlen);
    if (s == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return -1;
    }
    return 0;
}

int AcceptorSocket::listen(int backlog) {
    int s = ::listen(fd, backlog);
    if (s == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return -1;
    }
    return 0;
}

addrinfo* AcceptorSocket::getAddressInfo(const char* service) {
    struct addrinfo* addr_info;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int s = getaddrinfo(nullptr, service, &hints, &addr_info);
    if (s != 0) {
        freeaddrinfo(addr_info);
        std::string err = std::string("Error in getaddrinfo: ")
                + gai_strerror(s) + '\n';
        throw SocketException(err);
    }
    return addr_info;
}

void AcceptorSocket::close() {
    if (fd != -1) {
        shutdown(fd, SHUT_RDWR);
        ::close(fd);
    }
}

AcceptorSocket::~AcceptorSocket() {
    this->close();
}
