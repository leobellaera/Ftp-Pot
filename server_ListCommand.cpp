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

#define DIR_PREFIX "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 "

server_ListCommand::server_ListCommand(std::map<std::string, std::string> &cfg,
                                       server_Login& login, server_DirectoryOrganizer& dir_org) :
    cfg(cfg),
    login(login),
    dir_organizer(dir_org) {}

std::string server_ListCommand::execute() {
    login.resetIfNotLogged();
    std::string answer;
    if (login.userIsLogged()) {
        answer.append(LIST_BEGIN_CODE + cfg.find(LIST_BEGIN_KEY)->second + '\n');
        answer.append(DIR_PREFIX + dir_organizer.getDirectories());
        answer.append(LIST_END_CODE + cfg.find(LIST_END_KEY)->second);
        return std::move(answer);
    } else {
        return UNLOGGED_CODE + cfg.find(UNLOGGED_KEY)->second;
    }
}

server_ListCommand::~server_ListCommand() {}
