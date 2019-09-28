//
// Created by leobellaera on 27/9/19.
//

#include <sstream>
#include "Command.h"
#include "UserCommand.h"
#include "PassCommand.h"
#include "SystCommand.h"
#include "QuitCommand.h"
#include "HelpCommand.h"
#include "PwdCommand.h"
#include "UnknownCommand.h"

#define USER_COMMAND "USER"
#define PASS_COMMAND "PASS"
#define SYST_COMMAND "SYST"
#define HELP_COMMAND "HELP"
#define PWD_COMMAND "PWD"
#define QUIT_COMMAND "QUIT"
#define LIST_COMMAND "LIST"
#define MKD_COMMAND "MKD"
#define RMD_COMMAND "RMD"

Command* Command::make_command(std::map<std::string,std::string>& cfg, std::string& command, Login& login) {
    std::string first_arg = command.substr(0, command.find(' '));
    if (first_arg == USER_COMMAND) {
        return new UserCommand(command, cfg, login);

    } else if (first_arg == PASS_COMMAND) {
        return new PassCommand(command, cfg, login);

    } else if (first_arg == SYST_COMMAND) {
        return new SystCommand(cfg, login);

    } else if (first_arg == QUIT_COMMAND ) {
        return new QuitCommand(cfg);

    } else if (first_arg == HELP_COMMAND) {
        return new HelpCommand(cfg, login);

    } else if (first_arg == PWD_COMMAND) {
        return new PwdCommand(cfg, login);

    /*} else if (first_arg == MKD_COMMAND) {
        return new MkdCommand(command, cfg, dir_organizer);

    } else if (first_arg == RMD_COMMAND){
        return new RmdCommand(command, cfg, dir_organizer);

    } else if (first_arg == LIST_COMMAND) {
        return new ListCommand(command, cfg, dir_organizer);*/

    } else {
        return new UnknownCommand(cfg, login);
    }
}
