//
// Created by leobellaera on 29/9/19.
//

#include "server_ServerFtp.h"
#include "server_CfgMapBuilderException.h"
#include "common_SocketException.h"
#include <iostream>

#define INVALID_ARGS_AMOUNT_MSG "Invalid number of arguments"
#define UNKNOWN_ERROR_MSG "An unknown error occurred in the execution"
#define CONFIG_PATH_POS 2
#define PORT_POS 1
#define BACKLOG 50

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr<<INVALID_ARGS_AMOUNT_MSG<<std::endl;
        return 1;
    }
    try {
        ServerFtp sv(argv[CONFIG_PATH_POS], argv[PORT_POS], BACKLOG);
        sv.run();
    } catch (const CfgMapBuilderException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (const SocketException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << UNKNOWN_ERROR_MSG << std::endl;
        return 1;
    }
    return 0;
}
