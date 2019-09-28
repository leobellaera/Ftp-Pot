//
// Created by leobellaera on 28/9/19.
//

#include "ThClient.h"
#include <iostream>
#include "DirectoryOrganizer.h"
#include "CfgMapBuilder.h"

int main() {
    CfgMapBuilder map_builder("config.cfg");
    Thread *thread;
    thread = new ThClient(map_builder.getMap());
    thread->start();
    thread->join();
    delete thread;

    DirectoryOrganizer d;
    d.makeDir("www.facebook.com");
    d.makeDir("z");
    d.makeDir("a");
    d.makeDir("x");
    d.makeDir("b");
    d.makeDir("www.google.com.ar");
    if (!d.makeDir("www.google.com.ar")) {
        std::cout<<"NO SE PUEDE, YA PUSISTE ESTO\n";
    }
    if (!d.removeDir("LEO")) {
        std::cout<<"NO ESTA\n";
    }
    d.removeDir("z");
    std::cout<<d.getDirectories();
    return 0;
}
