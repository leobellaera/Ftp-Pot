//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_SERVER_THACCEPTOR_H
#define TP_SERVER_THACCEPTOR_H

#include <string>
#include <map>
#include <vector>
#include "server_AcceptorSocket.h"
#include "server_DirectoryOrganizer.h"
#include "server_ThClient.h"
#include "server_Thread.h"

class server_ThAcceptor : public server_Thread {
private:
    server_AcceptorSocket acceptor_skt;
    server_DirectoryOrganizer& dir_organizer;
    std::map<std::string, std::string>& cfg;
    std::vector<server_ThClient*> clients;
    void deleteDeadClients();
public:
    server_ThAcceptor(server_DirectoryOrganizer& dir_organizer, std::map<std::string, std::string>& cfg, const char* service, int backlog);
    void run() override;
    void stop();
    ~server_ThAcceptor() override;
};

#endif //TP_SERVER_THACCEPTOR_H
