//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_SERVER_FTP_H
#define TP_SERVER_FTP_H

#include "server_DirectoryOrganizer.h"
#include "server_ThAcceptor.h"
#include "server_CfgMapBuilder.h"

class server_Ftp {
private:
   server_DirectoryOrganizer dir_organizer;
   server_CfgMapBuilder map_builder;
   server_ThAcceptor acceptor_thread;
public:
    server_Ftp(const char* config_path, const char* service, int backlog);
    void run();
    ~server_Ftp();
};

#endif //TP_SERVER_FTP_H
