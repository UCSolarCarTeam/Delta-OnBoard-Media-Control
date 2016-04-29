#include "ConfigFileReader.h"

#if 1
int main() 
{
    std::cout << "Testing ConfigFileReader" << std::endl;
    ConfigFileReader reader("test.txt");

    std::string s = reader.find("Helo");
    std::cout << s << std::endl;

    return 0;
}
#endif

ConfigFileReader::ConfigFileReader(const char* file_name)
{
    iniFile.open(file_name);
    int lineCount = 0;

    std::string line;
    if (iniFile.is_open())
	{
		while (getline(iniFile, line))
		{
			lineCount++;
			std::transform(line.begin(), line.end(),line.begin(), ::toupper);
            std::size_t pos = line.find("=");
        	line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
            if (pos == std::string::npos) 
            {
                std::cout << "Line " << lineCount << ": Error found." << std::endl;
            }
            else 
            {
            	std::string key = line.substr(0, pos-1);
            	std::string value = line.substr(pos);
            	hashmap.insert({key, value});
            }
		}
		iniFile.close();
    }

    for (auto& n : hashmap) {
        std::cout << "Key: [" << n.first << "] Value: [" << n.second << "]" << std::endl;
    }
}

std::string ConfigFileReader::find(std::string key) 
{
	std::string value;
	std::transform(key.begin(), key.end(),key.begin(), ::toupper);
	if (hashmap.find(key) == hashmap.end())
	{
		value = "NOT FOUND";
	}
	else {
		value = hashmap[key];
	}
	return value;
}
