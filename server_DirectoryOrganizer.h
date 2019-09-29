//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SERVER_DIRECTORYORGANIZER_H
#define TP_SERVER_DIRECTORYORGANIZER_H

#include <set>
#include <string>

class server_DirectoryOrganizer {
private:
    std::set<std::string> directories;
public:
    server_DirectoryOrganizer();
    bool makeDir(std::string name);
    bool removeDir(std::string name);
    std::string getDirectories();
};


#endif //TP_SERVER_DIRECTORYORGANIZER_H
