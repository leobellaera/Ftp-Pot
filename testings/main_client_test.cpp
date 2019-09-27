//
// Created by leobellaera on 27/9/19.
//

#include <iostream>
#include "FtpClient.h"

int main() {
    FtpClient c("localhost", "7777");
    c.run();
    return 0;
}

