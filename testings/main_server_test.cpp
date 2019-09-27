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
    std::string answer = "OK\n";
    char received_char = '\0';
    while (true) {
        peer.recvMessage(&received_char, 1);
        if (received_char == '\n') {
            if (command == "QUIT") {
                break;
            }
            std::cout<<command<<std::endl;
            command.clear();
            peer.sendMessage(answer.c_str(), 3);
        }
        command.append(1, received_char);
    }
    return 0;
}
