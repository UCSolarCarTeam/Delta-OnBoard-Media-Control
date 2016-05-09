#include "ConfigFileReader.h"
#define TEST false

// To Compile:
// g++ -std=c++11 ConfigFileReader.cpp

#if TEST
// For Testing
int main (int argc, char *argv[])
{
    std::cout << "Testing ConfigFileReader" << std::endl;
    std::cout << "Loading File " << argv[1] << std::endl;
    ConfigFileReader reader(argv[1]);

    double a = reader.getDouble("DEFAULT", "GREET", 20);
    std::cout << a << std::endl;

    double b = reader.getDouble("SCREEN", "SCREEN_HEIGHT", 20);
    std::cout << b << std::endl;

    std::string c = reader.getString("SCREEN", "SCREEN_TITLE", "Title Screen");
    std::cout << c << std::endl;

    bool d = reader.getBoolean("SCREEN", "SCREEN_ENABLE", true);
    std::cout << d << std::endl;

    return 0;
}
#endif

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
            std::transform(line.begin(), line.end(),line.begin(), ::toupper);
            
            key = line.substr(0,pos);
            key.erase(std::remove(key.begin(), key.end(), ' '), key.end());  

            value = line.substr(pos+1);
            value = trim(value);

            if (isSection(line)) 
            {
                section = line.substr(1, section.length()-1);
            }
            else if (isValidKey(line))
            {
                key = makeKey(section, key);
                hashmap.insert({key, value});
            }
        }
        iniFile.close();
    }

    #if TEST
    for (auto& n : hashmap)
    {
        std::cout << "Key: [" << n.first << "] Value: [" << n.second << "]" << std::endl;
    }
    #endif
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
    std::cout << newKey << std::endl;

    if (hashmap.find(newKey) != hashmap.end())
    {
        if (hashmap[newKey] == "YES" || hashmap[newKey] == "TRUE" || hashmap[newKey] == "1" || hashmap[newKey] == "ON")
            return true;
        else if (hashmap[newKey] == "NO" || hashmap[newKey] == "FALSE" || hashmap[newKey] == "0" || hashmap[newKey] == "OFF")
            return false;
    }
        
    return default_value;
}

bool ConfigFileReader::isSection(std::string line)
{
    if (line[0] = '[' && line[line.length()-1] == ']')
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