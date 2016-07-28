#include "ConfigFileReader.h"

ConfigFileReader::ConfigFileReader(const char* file_name)
{
    iniFile.open(file_name);
    int lineCount = 0;

    std::string line;
    std::string section = "DEFAULT";
    if (iniFile.is_open())
	{
		while (getline(iniFile, line))
		{
            std::string key;
            std::string value;

            lineCount++;

            size_t pos = line.find("=");
            //std::transform(line.begin(), line.end(),line.begin(), ::toupper);
            
            key = line.substr(0,pos); key.erase(std::remove(key.begin(), key.end(), ' '), key.end());  

            value = line.substr(pos+1);
            value = trim(value);

            if (isSection(line)) 
            {
                section = line.substr(1, line.length()-2);
            }
            else if (isValidKey(line))
            {
                key = makeKey(section, key);
                hashmap.insert({key, value});
            }
        }
        iniFile.close();
    }
}


double ConfigFileReader::getDouble(std::string section, std::string key, double default_value)
{
    std::string newKey = makeKey(section, key);
    std::cout << newKey << std::endl;

	if (hashmap.find(newKey) != hashmap.end())
	{
        return stod(hashmap[newKey]);
	}

    return default_value;
}

std::string ConfigFileReader::getString(std::string section, std::string key, std::string default_value)
{
    std::string newKey = makeKey(section, key);
    std::cout << newKey << std::endl;

    if (hashmap.find(newKey) != hashmap.end())
    {
        return hashmap[newKey];
    }

    return default_value;
}

bool ConfigFileReader::getBoolean(std::string section, std::string key, bool default_value)
{
    std::string newKey = makeKey(section, key);
    std::string hashValue;
    std::cout << newKey << std::endl;

    if (hashmap.find(newKey) != hashmap.end())
    {
        hashValue = hashmap[newKey];
        if (hashValue == "YES" || hashValue == "TRUE" || hashValue == "1" || hashValue == "ON" || 
                hashValue == "yes" || hashValue == "true" || hashValue == "on")
            return true;
        else if (hashValue == "NO" || hashValue == "FALSE" || hashValue == "0" || hashValue == "OFF" || 
                hashValue == "no" || hashValue == "false" || hashValue == "off")
            return false;
    }
        
    return default_value;
}

bool ConfigFileReader::isSection(std::string line)
{
    if ((line[0] = '[') && (line[line.length()-1] == ']'))
        return true;

    return false;
}

bool ConfigFileReader::isValidKey(std::string line)
{
    std::size_t pos = line.find("=");
    if (pos != std::string::npos) 
        return true;

    return false;
}

std::string ConfigFileReader::makeKey(std::string section, std::string key) 
{
    std::string newKey = section.append(':' + key);
    newKey.erase(std::remove(newKey.begin(), newKey.end(), ' '), newKey.end());
    std::transform(newKey.begin(), newKey.end(),newKey.begin(), ::toupper);

    return newKey;
}

// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}
