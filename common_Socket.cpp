//
// Created by leobellaera on 26/9/19.
//

#include "common_Socket.h"
#include "common_SocketException.h"
#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <cstdlib>

#define INIT_ERROR_MSG "Error occurred while trying to establish connection"
#define SEND_ERROR_MSG "Error occurred while trying to send message"
#define RECV_ERROR_MSG "Error occurred while trying to receive message"

common_Socket::common_Socket(const char* host, const char* service) :
    fd(-1) {
    if (this->connect(host, service) == 1) {
        throw common_SocketException(INIT_ERROR_MSG);
    }
}

common_Socket::common_Socket(int fd) :
    fd(fd) {}

common_Socket::common_Socket(common_Socket &&other) noexcept {
    this->fd = other.fd;
    other.fd = -1;
}

int common_Socket::connect(const char* host, const char* service) {
    struct addrinfo *result = nullptr;
    int s = this->getAddressInfo(&result, host, service);
    if (s != 0) {
        std::cerr << "Error in getaddrinfo: " << gai_strerror(s) << std::endl;;
        freeaddrinfo(result);
        return 1;
    }
    if (!this->establishConnection(result)) {
        std::cerr << "Error: connection couldn't been established\n";
        freeaddrinfo(result);
        return 1;
    }
    freeaddrinfo(result);
    return 0;
}

bool common_Socket::establishConnection(addrinfo* result) {
    struct addrinfo* ptr;
    int s;
    bool connection_established = false;
    for (ptr = result; ptr != nullptr && !connection_established ; ptr = ptr->ai_next) {
        fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (fd == -1) {
            std::cerr << "Error: " << strerror(errno) << std::endl;
        } else {
            s = ::connect(fd, ptr->ai_addr, ptr->ai_addrlen);
            if (s == -1) {
                std::cerr << "Error: " << strerror(errno) << std::endl;
            }
            connection_established = (s != -1);
        }
    }
    return connection_established;
}


int common_Socket::getAddressInfo(struct addrinfo **addrinfo_ptr, const char* host, const char* service) {
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    return getaddrinfo(host, service, &hints, addrinfo_ptr);
}

void common_Socket::sendMessage(const char* buffer, int size) { //quizas habria q lanzar error y cambiar la firma a void
    int sent = 0;
    int s = 0;
    while (sent < size) {
        s = send(fd, &buffer[sent], size - sent, MSG_NOSIGNAL);
        if (s == 0 || s == -1) {
            throw common_SocketException(SEND_ERROR_MSG);
        } else {
            sent += s;
        }
    }
}

void common_Socket::recvMessage(char* buffer, int size) {
    int received = 0;
    int s = 0;
    while (received < size) {
        s = recv(fd, &buffer[received], size-received, 0);
        if (s == 0 || s == -1) {
            throw common_SocketException(RECV_ERROR_MSG);
        } else {
            received += s;
        }
    }
}

void common_Socket::close() {
    if (fd != -1) {
        shutdown(fd, SHUT_RDWR);
        ::close(fd);
        fd = -1;
    }
}

common_Socket::~common_Socket() {
    this->close();
}
