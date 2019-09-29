//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_FTPSERVER_H
#define TP_FTPSERVER_H

#include "DirectoryOrganizer.h"
#include "ThAcceptor.h"
#include "CfgMapBuilder.h"

class FtpServer {
private:
   DirectoryOrganizer dir_organizer;
   CfgMapBuilder map_builder;
   ThAcceptor acceptor_thread;
public:
    FtpServer(const char* config_path, const char* service, int backlog);
    void run();
    ~FtpServer();
};

#endif //TP_FTPSERVER_H
