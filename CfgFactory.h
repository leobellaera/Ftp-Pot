//
// Created by leobellaera on 25/9/19.
//

#ifndef TP_CFGFACTORY_H
#define TP_CFGFACTORY_H

#include <fstream>
#include <map>
#include <string>

class CfgFactory {
    private:
        std::ifstream file;
        std::map<std::string,std::string> data;
        void buildMap();
    public:
        CfgFactory(char* file_path);
        void printConfig();
        //Log buildLog();
        //Mkd buildMkd();
        //List buildList();
        ~CfgFactory();
};


#endif //TP_CFGFACTORY_H
