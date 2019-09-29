//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_COMMON_SOCKET_H
#define TP_COMMON_SOCKET_H
#include <netdb.h>

class common_Socket {
private:
    int fd;
    int connect(const char* host, const char* service);
    bool establishConnection(addrinfo* result);
    int getAddressInfo(struct addrinfo **addrinfo_ptr, const char* host, const char* service);
public:
    common_Socket(const char* host, const char* service);
    explicit common_Socket(int fd);
    common_Socket(common_Socket &&other) noexcept;
    void sendMessage(const char* buffer, int size);
    void recvMessage(char* buffer, int size);
    void close();
    ~common_Socket();
};

#endif //TP_COMMON_SOCKET_H
