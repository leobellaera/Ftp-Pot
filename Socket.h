//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SOCKET_H
#define TP_SOCKET_H
#include <netdb.h>

class Socket {
private:
    int fd;
    int _connect(const char* host, const char* service);
    bool establishConnection(addrinfo* result);
    int getAddressInfo(struct addrinfo **addrinfo_ptr, const char* host, const char* service);
public:
    Socket(const char* host, const char* service);
    Socket(Socket &&other) noexcept;
    explicit Socket(int fd);
    int sendMessage(char* buffer, int size);
    int recvMessage(char* buffer, int size);
    void close();
    ~Socket();
};

#endif //TP_SOCKET_H
