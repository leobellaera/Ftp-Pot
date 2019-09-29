//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SOCKETEXCEPTION_H
#define TP_SOCKETEXCEPTION_H

#include <stdexcept>

class SocketException : public std::runtime_error {
public:
    explicit SocketException(const char* error) : runtime_error(error) {}
};

#endif //TP_SOCKETEXCEPTION_H
