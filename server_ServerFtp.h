//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SERVERFTP_H
#define TP_SERVERFTP_H

#include "server_DirectoryOrganizer.h"
#include "server_ThAcceptor.h"
#include "server_CfgMapBuilder.h"

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
