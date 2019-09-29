//
// Created by leobellaera on 28/9/19.
//

#ifndef TP_THACCEPTOR_H
#define TP_THACCEPTOR_H

#include <string>
#include <map>
#include <vector>
#include "AcceptorSocket.h"
#include "DirectoryOrganizer.h"
#include "ThClient.h"
#include "Thread.h"

class ThAcceptor : public Thread {
private:
    AcceptorSocket acceptor_skt;
    DirectoryOrganizer& dir_organizer;
    std::map<std::string, std::string>& cfg;
    std::vector<ThClient*> clients;
    void deleteDeadClients();
public:
    ThAcceptor(DirectoryOrganizer& dir_organizer, std::map<std::string, std::string>& cfg, const char* service, int backlog);
    void run() override;
    void stop();
    ~ThAcceptor() override;
};

#endif //TP_THACCEPTOR_H
