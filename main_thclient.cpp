//
// Created by leobellaera on 28/9/19.
//

#include "ThClient.h"
#include "DirectoryOrganizer.h"
#include "CfgMapBuilder.h"

int main() {
    CfgMapBuilder map_builder("config.cfg");
    Thread *thread;
    thread = new ThClient(map_builder.getMap());
    thread->start();
    thread->join();
    delete thread;
    return 0;
}
