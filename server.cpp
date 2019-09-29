//
// Created by leobellaera on 29/9/19.
//

#include "server_ServerFtp.h"
#include <iostream>

#define INVALID_ARGS_AMOUNT_MSG "Invalid number of arguments"
#define CONFIG_PATH_POS 2
#define PORT_POS 1
#define BACKLOG 50

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout<<INVALID_ARGS_AMOUNT_MSG<<std::endl;
    }
    ServerFtp sv(argv[CONFIG_PATH_POS], argv[PORT_POS], BACKLOG);
    sv.run();
    return 0;
}
