//
// Created by leobellaera on 27/9/19.
//

#include "server_DirectoryOrganizer.h"
#define DIR_PREFIX "drwxrwxrwx 0 1000 1000 4096 Sep 24 12:34 "

DirectoryOrganizer::DirectoryOrganizer() {}

bool DirectoryOrganizer::makeDir(std::string name) {
    std::unique_lock<std::mutex> lock(m);
    return directories.emplace(name).second;
}

bool DirectoryOrganizer::removeDir(std::string name) {
    std::unique_lock<std::mutex> lock(m);
    if (directories.find(name) == directories.end()) {
        return false;
    }
    directories.erase(name);
    return true;
}

std::string DirectoryOrganizer::getDirectories() {
    std::unique_lock<std::mutex> lock(m);
    std::string ret;
    for (const auto & dir : directories) {
        ret.append(DIR_PREFIX + dir);
        ret.append("\n");
    }
    return std::move(ret);
}
