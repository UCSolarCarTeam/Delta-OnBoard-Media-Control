#pragma once

#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include "I_song_loader_observer.h"
//#include "I_io_event_observer.h"
#include "Observable.h"
//#include "config.h"
#include <algorithm>
#include <vector>
#include <random>

class SongLoader : public Observable<I_SongLoaderObserver> 
{
public:
        SongLoader();
        bool song_exists();
        void next_song_name();
        void previous_song_name();
        void io_event(int io_command);
        void next_song();
        void previous_song();
        void shuffle_songs();
        void current_song();
        int libraryLoad();
        bool read_song_names(std::string dir, std::vector<std::string> &files);


private:
        std::vector<std::string> files = std::vector<std::string>();
        int current_song_index;
        bool check_library;
        void notify_listeners(std::string song_path);
};
