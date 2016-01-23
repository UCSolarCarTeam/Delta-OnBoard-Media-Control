#include "NewSongLoader.h"

using namespace std;

SongLoader::SongLoader()
{
    currentSongIndex = 0;
    checkLibrary = readSongNames(); 
    shuffleSongs();

    string dir = string(".");
    vector<string> files = vector<string>();

    readSongNames();

    for (unsigned int i = 0;i < files.size();i++)
    {
        cout << files[i] << endl;
    }
}

bool SongLoader::songExists()
{
    return checkLibrary;
}

int readSongNames(string dir, vector<string> &files)
{
   DIR *dp; 
   struct dirent *dirp;
   if((dp  = opendir("/home/Music")) == NULL)
   {
        return errno;
   }

   while ((dirp = readdir(dp)) != NULL)
   {
        files.push_back(string(dirp->d_name));
   }
   closedir(dp);
   return 0;
}
