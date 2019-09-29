//
// Created by leobellaera on 25/9/19.
//

#ifndef TP_SERVER_CFGMAPBUILDER_H
#define TP_SERVER_CFGMAPBUILDER_H

#include <fstream>
#include <map>
#include <string>

class server_CfgMapBuilder {
private:
    std::ifstream file;
    std::map<std::string,std::string> data;
    void buildMap();
public:
    server_CfgMapBuilder(const char* file_path);
    std::map<std::string,std::string>& getMap();
    ~server_CfgMapBuilder();
};

#endif //TP_SERVER_CFGMAPBUILDER_H
