//
// Created by leobellaera on 29/9/19.
//

#ifndef TP_CFGMAPBUILDEREXCEPTION_H
#define TP_CFGMAPBUILDEREXCEPTION_H

#include <stdexcept>

class CfgMapBuilderException : public std::runtime_error {
public:
    explicit CfgMapBuilderException(const char* error) : runtime_error(error) {}
};

#endif //TP_CFGMAPBUILDEREXCEPTION_H
