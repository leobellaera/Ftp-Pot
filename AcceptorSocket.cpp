//
// Created by leobellaera on 26/9/19.
//

#include "AcceptorSocket.h"
#include "SocketException.h"
#include <cerrno>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

#define INIT_ERROR_MSG "Error happened while trying to bind and listen"
#define ACCEPT_ERROR_MSG "Error happened while trying to accept client"

AcceptorSocket::AcceptorSocket(int backlog, char* service) :
    fd(-1) {
    if (this->bindAndListen(backlog, service) == 1) {
        throw SocketException(INIT_ERROR_MSG);
    }
}

Socket AcceptorSocket::acceptClient() {
    int peer_fd = accept(fd, nullptr, nullptr);
    if (peer_fd == -1){
        throw SocketException(ACCEPT_ERROR_MSG);
    }
    return std::move(Socket(peer_fd));
}

int AcceptorSocket::bindAndListen(int backlog, char* service) {
    struct addrinfo *ptr = nullptr;
    int s = this->getAddressInfo(&ptr, service);
    if (s != 0) {
        std::cerr << "Error in getaddrinfo: " << gai_strerror(s) << std::endl;
        return 1;
    }
    fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (fd == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        freeaddrinfo(ptr);
        return 1;
    }
    if (_bind(ptr) == 1) {
        freeaddrinfo(ptr);
        return 1;
    }
    freeaddrinfo(ptr);
    if (_listen(backlog) == 1) {
        return 1;
    }
    return 0;
}

int AcceptorSocket::_bind(struct addrinfo* ptr) {
    int s = bind(fd, ptr->ai_addr, ptr->ai_addrlen);
    if (s == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    return 0;
}

int AcceptorSocket::_listen(int listen_amount) {
    int s = listen(fd, listen_amount);
    if (s == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    return 0;
}

int AcceptorSocket::getAddressInfo(struct addrinfo **addrinfo_ptr, char* service) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    return getaddrinfo(nullptr, service, &hints, addrinfo_ptr);
}

AcceptorSocket::~AcceptorSocket() {
    if (fd != -1) {
        shutdown(fd, SHUT_RDWR);
        close(fd);
    }
}
