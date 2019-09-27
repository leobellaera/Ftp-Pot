//
// Created by leobellaera on 25/9/19.
//

#include "ConfigMapBuilder.h"
#include <iostream> //para debugging
#include <sstream>
#define DELIM_CHAR '='

ConfigMapBuilder::ConfigMapBuilder(char* file_path) {
    file.open(file_path, std::ifstream::in);
    this->buildMap();
    file.close();
}

void ConfigMapBuilder::buildMap() {
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

std::map<std::string,std::string>& ConfigMapBuilder::getMap(){
    return data;
}

ConfigMapBuilder::~ConfigMapBuilder() {}

void ConfigMapBuilder::printConfig() {
    std::map<std::string, std::string>::iterator it = data.begin();
    while (it != data.end()) {
        std::string key = it->first;
        std::string value = it->second;
        std::cout << key << " : " << value << std::endl;
        it++;
    }
}
