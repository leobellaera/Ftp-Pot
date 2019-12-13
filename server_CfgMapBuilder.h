//
// Created by leobellaera on 25/9/19.
//

#ifndef TP_CFGMAPBUILDER_H
#define TP_CFGMAPBUILDER_H

#include <fstream>
#include <map>
#include <string>

class CfgMapBuilder {
private:
    std::ifstream file;
    std::map<std::string,std::string> data;
    void buildMap();
public:
    explicit CfgMapBuilder(const char* file_path);
    std::map<std::string,std::string>& getMap();
    ~CfgMapBuilder();
};

#endif //TP_CFGMAPBUILDER_H
