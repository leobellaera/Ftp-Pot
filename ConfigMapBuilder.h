//
// Created by leobellaera on 25/9/19.
//

#ifndef TP_CONFIGMAPBUILDER_H
#define TP_CONFIGMAPBUILDER_H

#include <fstream>
#include <map>
#include <string>

class ConfigMapBuilder {
private:
    std::ifstream file;
    std::map<std::string,std::string> data;
    void buildMap();
public:
    ConfigMapBuilder(char* file_path);
    void printConfig();
    std::map<std::string,std::string>& getMap();
    ~ConfigMapBuilder();
};


#endif //TP_CONFIGMAPBUILDER_H
