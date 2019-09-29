//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_COMMON_SOCKETEXCEPTION_H
#define TP_COMMON_SOCKETEXCEPTION_H

#include <stdexcept>

class common_SocketException : public std::runtime_error {
public:
    explicit common_SocketException(const char* error) : runtime_error(error) {}
};

#endif //TP_COMMON_SOCKETEXCEPTION_H
