//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SERVERFTP_H
#define TP_SERVERFTP_H

#include "DirectoryOrganizer.h"
#include "ThAcceptor.h"
#include "CfgMapBuilder.h"

class ServerFtp {
private:
   DirectoryOrganizer dir_organizer;
   CfgMapBuilder map_builder;
   ThAcceptor acceptor_thread;
public:
    ServerFtp(const char* config_path, const char* service, int backlog);
    void run();
    ~ServerFtp();
};

#endif //TP_SERVERFTP_H
