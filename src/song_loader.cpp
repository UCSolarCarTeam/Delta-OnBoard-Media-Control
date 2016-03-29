#include "song_loader.h"

SongLoader::SongLoader()
{
    std::string dir = std::string(".");
}

void SongLoader::notify_listeners(std::string song_path)
{
    for(I_SongLoaderObserver*listener:listeners) 
    {
        listener->current_song(song_path);
    }
}

void SongLoader::next_song()
{
    current_song_index = (current_song_index + 1)%files.size();
    notify_listeners(files[current_song_index]);
}

void SongLoader::previous_song()
{
    current_song_index = (current_song_index - 1)%files.size();
    notify_listeners(files[current_song_index]);
}

void SongLoader::next_song_name()
{
    notify_listeners(files[(current_song_index + 1)%files.size()]);
}

void SongLoader::previous_song_name()
{
    notify_listeners(files[(current_song_index - 1)%files.size()]);
}

void SongLoader::io_event(std::string io_command)
{
    if(io_command == play_next_song)
    {
        next_song();
    }
    if(io_command == play_previous_song)
    {
        previous_song();
    }
    if(io_command == show_next_song_name)
    {
        next_song_name();
    }
    if(io_command == show_previous_song_name)
    {
        previous_song_name();
    }
}

bool has_suffix(const std::string& s, const std::string& suffix)
{
    return(s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

bool SongLoader::read_song_names(std::string dir, std::vector<std::string> &files)
{
   DIR *dp; 
   std::string filepath;
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
             files.push_back(std::string(filepath));
        }
   }
   closedir(dp);
   return true;
}
