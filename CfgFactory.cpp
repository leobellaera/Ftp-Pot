//
// Created by leobellaera on 25/9/19.
//

#include "CfgFactory.h"
#include <iostream> //para debugging
#include <sstream>
#define DELIM_CHAR '='

CfgFactory::CfgFactory(char* file_path) {
    file.open(file_path, std::ifstream::in);
    this->buildMap();
    file.close();
}

void CfgFactory::buildMap() {
    while (!file.eof()) {
        std::string aux;
        std::string key;
        std::string value;

        std::getline(file, aux);
        std::istringstream line_stream(aux);

        std::getline(line_stream, key, DELIM_CHAR);
        std::getline(line_stream, value, DELIM_CHAR);
        data.emplace(key, value);
    }
}


void CfgFactory::printConfig(){ //Para debuggeo
    std::map<std::string, std::string>::iterator it = data.begin();
    while (it != data.end()) {
        std::string key = it->first;
        std::string value = it->second;
        std::cout << key << " : " << value << std::endl;
        it++;
    }
}

CfgFactory::~CfgFactory() {}

