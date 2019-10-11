//
// Created by leobellaera on 26/9/19.
//

#include "common_Socket.h"
#include "common_SocketException.h"
#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>
#include <cstdlib>

#define SEND_ERROR_MSG "Error occurred while trying to send message\n"
#define RECV_ERROR_MSG "Error occurred while trying to receive message\n"
#define CONNECT_ERROR_MSG "Error occurred while trying to\
 establish connection\n"

Socket::Socket(const char* host, const char* service) :
    fd(-1) {
    this->connect(host, service);
}

Socket::Socket(int fd) :
    fd(fd) {}

Socket::Socket(Socket &&other) noexcept {
    this->fd = other.fd;
    other.fd = -1;
}

void Socket::connect(const char* host, const char* service) {
    struct addrinfo *result = this->getAddressInfo(host, service);
    this->establishConnection(result);
}

void Socket::establishConnection(addrinfo* result) {
    struct addrinfo* ptr;
    bool success = false;
    for (ptr = result; ptr != nullptr && !success ; ptr = ptr->ai_next) {
        fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (fd == -1) {
            std::cerr << "Error: " << strerror(errno) << std::endl;
        } else {
            success = (::connect(fd, ptr->ai_addr, ptr->ai_addrlen) != -1);
            if (!success) {
                std::cerr << "Error: " << strerror(errno) << std::endl;
            }
        }
    }
    freeaddrinfo(result);
    if (!success) {
        this->close();
        throw SocketException(CONNECT_ERROR_MSG);
    }
}

addrinfo* Socket::getAddressInfo(const char* host, const char* service) {
    struct addrinfo* addr_info;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    int s = getaddrinfo(host, service, &hints, &addr_info);
    if (s != 0) {
        freeaddrinfo(addr_info);
        std::string err = std::string("Error in getaddrinfo: ")
                + gai_strerror(s) + '\n';
        throw SocketException(err);
    }
    return addr_info;
}

void Socket::sendMessage(const char* buffer, int size) {
    int sent = 0;
    int s = 0;
    while (sent < size) {
        s = send(fd, &buffer[sent], size - sent, MSG_NOSIGNAL);
        if (s == 0 || s == -1) {
            throw SocketException(SEND_ERROR_MSG);
        } else {
            sent += s;
        }
    }
}

void Socket::recvMessage(char* buffer, int size) {
    int received = 0;
    int s = 0;
    while (received < size) {
        s = recv(fd, &buffer[received], size-received, 0);
        if (s == 0 || s == -1) {
            throw SocketException(RECV_ERROR_MSG);
        } else {
            received += s;
        }
    }
}

void Socket::close() {
    if (fd != -1) {
        shutdown(fd, SHUT_RDWR);
        ::close(fd);
        fd = -1;
    }
}

Socket::~Socket() {
    this->close();
}
