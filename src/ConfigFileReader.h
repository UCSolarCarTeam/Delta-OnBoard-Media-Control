#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>

class ConfigFileReader 
{
    public:
        ConfigFileReader(const char* file_name);
        std::string find(std::string key);
    private:
        std::ifstream iniFile;
        std::unordered_map<std::string, std::string> hashmap;
};