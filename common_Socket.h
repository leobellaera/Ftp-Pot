//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SOCKET_H
#define TP_SOCKET_H
#include <netdb.h>

class Socket {
private:
    int fd;
    void connect(const char* host, const char* service);
    void establishConnection(addrinfo* result);
    addrinfo* getAddressInfo(const char* host, const char* service);
public:
    Socket(const char* host, const char* service);
    explicit Socket(int fd);
    Socket(Socket &&other) noexcept;
    void sendMessage(const char* buffer, int size);
    void recvMessage(char* buffer, int size);
    void close();
    ~Socket();
};

#endif //TP_SOCKET_H
