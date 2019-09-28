//
// Created by leobellaera on 28/9/19.
//

#include "ListCommand.h"

#define UNLOGGED_KEY "clientNotLogged"
#define LIST_BEGIN_KEY "listBegin"
#define LIST_END_KEY "listEnd"

ListCommand::ListCommand(std::map<std::string, std::string> &cfg,
        Login& login, DirectoryOrganizer& dir_org) :
    cfg(cfg),
    login(login),
    dir_organizer(dir_org) {}

std::string ListCommand::execute() {
    login.resetIfNotLogged();
    std::string answer;
    if (login.userIsLogged()) {
        answer.append(cfg.find(LIST_BEGIN_KEY)->second);
        answer.append(dir_organizer.getDirectories());
        answer.append(cfg.find(LIST_END_KEY)->second);
        return std::move(answer);
    } else {
        return cfg.find(UNLOGGED_KEY)->second;
    }
}

ListCommand::~ListCommand() {}
