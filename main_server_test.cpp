//
// Created by leobellaera on 27/9/19.
//

#include <iostream>
#include "Socket.h"
#include "AcceptorSocket.h"

int main() {
    AcceptorSocket s(5, "7777");
    Socket peer = s.acceptClient();
    std::string command;
    char received_char = '\0';
    while (received_char != '\n') {
        peer.recvMessage(&received_char, 1);
        command.append(&received_char, 1);
    }
    std::cout<<command<<std::endl;
    return 0;
}
