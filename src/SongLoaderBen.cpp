#include "SongLoaderBen.h"

using namespace std;

SongLoaderBen::SongLoaderBen()
{
    currentSongIndex; 
    string dir = string(".");
    checkLibrary = readSongNames(dir, files); 
    if (checkLibrary != false)
    {
        shuffleSongs();
    }
}

bool SongLoaderBen::nextSong()
{
//    cout << files[currentSongIndex++] << endl;
    return true;
}

bool SongLoaderBen::previousSong()
{
//    cout << files[currentSongIndex--] << endl;
    return true;
}  

std::string SongLoaderBen::gotoNextSong()
{

   // currentSongIndex = (currentSongIndex+1)%files.size();

    currentSongIndex = currentSongIndex++; 
    if(currentSongIndex-1 > files.size())
    {
        currentSongIndex = 0; 
    }
    return files[currentSongIndex];
}

std::string SongLoaderBen::gotoPreviousSong()
{
    currentSongIndex = currentSongIndex--;
    if(currentSongIndex < 0)
    {
        currentSongIndex = files.size()-1;
    }
    return files[currentSongIndex];
}


std::string SongLoaderBen::currentSong()
{
    return files[currentSongIndex];
}

int SongLoaderBen::shuffleSongs()
{
    currentSongIndex = rand() % files.size();
}
bool SongLoaderBen::songExists()
{
    return checkLibrary;
}

bool has_suffix(const string& s, const string& suffix)
{
    return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());    
}

bool SongLoaderBen::readSongNames(string dir, std::vector<string> &files)
{
   DIR *dp; 
   struct dirent *dirp;
   if((dp  = opendir("/home/Music")) == NULL)
   {
       printf("we can save it here\n");
       return false;
   }

   while ((dirp = readdir(dp)) != NULL)
   {
        if(has_suffix(dirp->d_name, ".mp3"))
        {
            files.push_back(string(dirp->d_name));
        }
   }
   closedir(dp);
   return true;
}
