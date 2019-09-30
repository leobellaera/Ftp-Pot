//
// Created by leobellaera on 25/9/19.
//

#include "server_CfgMapBuilder.h"
#include "server_CfgMapBuilderException.h"
#include <sstream>
#define DELIM_CHAR '='
#define OPENING_ERROR_MSG "An error occurred while trying to open the config file.\n"
#define READING_ERROR_MSG "An error occurred while trying to read the config file.\n"

CfgMapBuilder::CfgMapBuilder(const char* file_path) {
    file.exceptions(std::ifstream::badbit);
    file.open(file_path);
    if (!file.is_open()) {
        throw CfgMapBuilderException(OPENING_ERROR_MSG);
    }
    try {
        this->buildMap();
    } catch (std::ios_base::failure& e) {
        throw CfgMapBuilderException(READING_ERROR_MSG);
    }
}

void CfgMapBuilder::buildMap() {
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

std::map<std::string,std::string>& CfgMapBuilder::getMap(){
    return data;
}

CfgMapBuilder::~CfgMapBuilder() {}
