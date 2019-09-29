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
#include <iostream>

#define INIT_ERROR_MSG "Error occurred while trying to bind and listen"
#define ACCEPT_ERROR_MSG "Error occurred while trying to accept client"

server_AcceptorSocket::server_AcceptorSocket(int backlog, const char* service) :
    fd(-1) {
    if (this->bindAndListen(backlog, service) == 1) {
        throw common_SocketException(INIT_ERROR_MSG);
    }
}

common_Socket server_AcceptorSocket::accept() {
    int peer_fd = ::accept(fd, nullptr, nullptr);
    if (peer_fd == -1){
        throw common_SocketException(ACCEPT_ERROR_MSG);
    }
    return std::move(common_Socket(peer_fd));
}

int server_AcceptorSocket::bindAndListen(int backlog, const char* service) {
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
    if (bind(ptr) == 1) {
        freeaddrinfo(ptr);
        return 1;
    }
    freeaddrinfo(ptr);
    if (listen(backlog) == 1) {
        return 1;
    }
    return 0;
}

int server_AcceptorSocket::bind(struct addrinfo* ptr) {
    int s = ::bind(fd, ptr->ai_addr, ptr->ai_addrlen);
    if (s == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    return 0;
}

int server_AcceptorSocket::listen(int backlog) {
    int s = ::listen(fd, backlog);
    if (s == -1) {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return 1;
    }
    return 0;
}

int server_AcceptorSocket::getAddressInfo(struct addrinfo **addrinfo_ptr, const char* service) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    return getaddrinfo(nullptr, service, &hints, addrinfo_ptr);
}

void server_AcceptorSocket::close() {
    if (fd != -1) {
        shutdown(fd, SHUT_RDWR);
        ::close(fd);
    }
}

server_AcceptorSocket::~server_AcceptorSocket() {
    this->close();
}
