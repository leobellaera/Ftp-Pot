//
// Created by leobellaera on 27/9/19.
//

#include <sstream>
#include "server_Command.h"
#include "server_UserCommand.h"
#include "server_PassCommand.h"
#include "server_SystCommand.h"
#include "server_QuitCommand.h"
#include "server_HelpCommand.h"
#include "server_PwdCommand.h"
#include "server_UnknownCommand.h"
#include "server_MkdCommand.h"
#include "server_RmdCommand.h"
#include "server_ListCommand.h"

#define USER_COMMAND "USER"
#define PASS_COMMAND "PASS"
#define SYST_COMMAND "SYST"
#define HELP_COMMAND "HELP"
#define PWD_COMMAND "PWD"
#define QUIT_COMMAND "QUIT"
#define LIST_COMMAND "LIST"
#define MKD_COMMAND "MKD"
#define RMD_COMMAND "RMD"

Command* Command::make_command(std::map<std::string, std::string>& cfg,
        std::string& command, Login& login, DirectoryOrganizer& dir_org) {
    std::string first_arg = command.substr(0, command.find(' '));
    std::string second_arg = command.substr(command.find(' ') + 1,
            command.length());
    if (first_arg == USER_COMMAND) {
        return new UserCommand(second_arg, cfg, login);

    } else if (first_arg == PASS_COMMAND) {
        return new PassCommand(second_arg, cfg, login);

    } else if (first_arg == SYST_COMMAND) {
        return new SystCommand(cfg, login);

    } else if (first_arg == QUIT_COMMAND) {
        return new QuitCommand(cfg);

    } else if (first_arg == HELP_COMMAND) {
        return new HelpCommand(cfg, login);

    } else if (first_arg == PWD_COMMAND) {
        return new PwdCommand(cfg, login);

    } else if (first_arg == MKD_COMMAND) {
        return new MkdCommand(second_arg, cfg, login, dir_org);

    } else if (first_arg == RMD_COMMAND){
        return new RmdCommand(second_arg, cfg, login, dir_org);

    } else if (first_arg == LIST_COMMAND) {
        return new ListCommand(cfg, login, dir_org);

    } else {
        return new UnknownCommand(cfg, login);
    }
}

Command::~Command() {}
