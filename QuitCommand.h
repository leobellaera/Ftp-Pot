//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_QUITCOMMAND_H
#define TP_QUITCOMMAND_H

#include <string>
#include <map>
#include "Command.h"

class QuitCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
public:
    explicit QuitCommand(std::map<std::string,std::string> &cfg);
    std::string execute() override;
    ~QuitCommand() override;
};

#endif //TP_QUITCOMMAND_H
