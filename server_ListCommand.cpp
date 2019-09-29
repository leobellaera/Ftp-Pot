//
// Created by leobellaera on 28/9/19.
//

#include "server_ListCommand.h"

#define UNLOGGED_KEY "clientNotLogged"
#define LIST_BEGIN_KEY "listBegin"
#define LIST_END_KEY "listEnd"

#define UNLOGGED_CODE "530 "
#define LIST_BEGIN_CODE "150 "
#define LIST_END_CODE "226 "

#define DELIM_CHAR '\n'

ListCommand::ListCommand(std::map<std::string, std::string> &cfg,
                         Login& login, DirectoryOrganizer& dir_org) :
    cfg(cfg),
    login(login),
    dir_organizer(dir_org) {}

std::string ListCommand::execute() {
    login.resetIfNotLogged();
    std::string answer;
    if (login.userIsLogged()) {
        answer.append(LIST_BEGIN_CODE + cfg.find(LIST_BEGIN_KEY)->second + DELIM_CHAR);
        answer.append(dir_organizer.getDirectories());
        answer.append(LIST_END_CODE + cfg.find(LIST_END_KEY)->second);
        return std::move(answer);
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

ListCommand::~ListCommand() {}
