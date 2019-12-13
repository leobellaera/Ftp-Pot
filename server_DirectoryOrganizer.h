//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_DIRECTORYORGANIZER_H
#define TP_DIRECTORYORGANIZER_H

#include <set>
#include <string>
#include <mutex>

class DirectoryOrganizer {
private:
    std::set<std::string> directories;
    std::mutex m;
public:
    DirectoryOrganizer();
    bool makeDir(std::string name);
    bool removeDir(std::string name);
    std::string getDirectories();
};


#endif //TP_DIRECTORYORGANIZER_H
