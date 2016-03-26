#include "song_loader.h"

SongLoader::SongLoader()
{
    std::string dir = std::string(".");
    check_library = read_song_names(dir, files);
    if(check_library != false)
    {
        shuffle_songs();
    }  
}

void SongLoader::notify_listeners()
{
    for(I_SongLoaderObserver*listener:listeners) 
    {
        listener->current_song(std::string song_path);
    }
}

std::string SongLoader::next_song()
{
    return files[(current_song_index+1)%files.size()];
}

std::strig SongLoader::previous_song()
{
    return files[(current_song_index-1)%files.size()];
}

std::string SongLoader::go_to_next_song()
{
   current_song_index = (current_song_index + 1)%files.size();
   return files[current_song_index];
}

std::string SongLoader::go_to_previous_song()
{
    current_song_index = (current_song_index - 1)%files.size();
    return files(current_song_index);
}

std::string SongLoader::current_song()
{
    return files[current_song_index];
    notify_listeners();
}

bool has_suffix(const string& s, const string& suffix)
{
    return(s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

bool SongLoader::readSongNames(string dir, std::vector<string> &files)
{
   DIR *dp; 
   string filepath;
   dir = "/home/Music";
   struct dirent *dirp;
   if((dp  = opendir("/home/Music")) == NULL)
   {
       return false;
   }

   while ((dirp = readdir(dp)) != NULL)
   {
        if(has_suffix(dirp->d_name, ".mp3"))
        {
             filepath = dir + "/" + dirp->d_name;
             files.push_back(string(filepath));
        }
   }
   closedir(dp);
   return true;
}
