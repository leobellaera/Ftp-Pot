//
// Created by leobellaera on 29/9/19.
//

#include <iostream>
#include "client_ClientFtp.h"
#include "common_SocketException.h"

#define INVALID_ARGS_AMOUNT_MSG "Invalid number of arguments"
#define HOST_POS 1
#define SERVICE_POS 2

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout<<INVALID_ARGS_AMOUNT_MSG<<std::endl;
    }
    try {
        ClientFtp client(argv[HOST_POS], argv[SERVICE_POS]);
        client.run();
    } catch (const SocketException& e) {
        std::cerr<< e.what() << std::endl;
    }
    return 0;
}
