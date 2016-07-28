#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>

class ConfigFileReader 
{
    public:
    	// Construct ConfigFileReader and parse the given filename.
        ConfigFileReader(const char* file_name);

        // Return a double from "section", "key" from INI file, if not found return default_value.
        double getDouble(std::string section, std::string key, double default_value); 

        // Return a string from "section", "key" from INI file, if not found return default_value.
        std::string getString(std::string section, std::string key, std::string default_value);

        // Return a boolean from "section", "key" from INI file, if not found return default_value.
        // Returns true if key is: 'yes', '1', 'true', or 'on'
        // Returns false if key is: 'no', '0', 'false', or 'off'
        bool getBoolean(std::string section, std::string key, bool default_value); 

	private:
    	std::string makeKey(std::string section, std::string name);
    	bool isSection(std::string line);
    	bool isValidKey(std::string line);
        
        std::ifstream iniFile;
        std::unordered_map<std::string, std::string> hashmap;
};

static inline std::string &ltrim(std::string &s);

static inline std::string &rtrim(std::string &s);

static inline std::string &trim(std::string &s);