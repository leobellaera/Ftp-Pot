//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_DIRECTORYORGANIZER_H
#define TP_DIRECTORYORGANIZER_H

#include <set>
#include <string>

class DirectoryOrganizer {
private:
    std::set<std::string> dirs;
public:
    DirectoryOrganizer();
    bool makeDir(std::string name);
    std::set<std::string> getDirectories();
};


#endif //TP_DIRECTORYORGANIZER_H
