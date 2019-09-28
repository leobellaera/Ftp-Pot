//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_LOGIN_H
#define TP_LOGIN_H

#include <cstdint>
#include <map>
#include <string>

class Login {
private:
    uint8_t stage;
    std::string user;
    std::string pass;
public:
    explicit Login(std::map<std::string, std::string> &cfg);
    bool logged();
    void updateStage(std::string& command);
    ~Login();
};


#endif //TP_LOGIN_H
