//
// Created by leobellaera on 27/9/19.
//

#include "DirectoryOrganizer.h"

DirectoryOrganizer::DirectoryOrganizer() {}

bool DirectoryOrganizer::makeDir(std::string name) {
    return directories.emplace(name).second;
}

bool DirectoryOrganizer::removeDir(std::string name) {
    if (directories.find(name) == directories.end()) {
        return false;
    }
    directories.erase(name);
    return true;
}

std::string DirectoryOrganizer::getDirectories() {
    std::string ret;
    for (const auto & dir : directories) {
        ret.append(dir);
        ret.append("\n");
    }
    return std::move(ret);
}
