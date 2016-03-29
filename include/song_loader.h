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

class SongLoader: public Observable<I_SongLoaderObserver>//,public I_IoEventObserver 
{
private:
    std::string play_next_song;
    std::string play_previous_song;
    std::string show_next_song_name;
    std::string show_previous_song_name;
    std::vector<std::string> files =std::vector<std::string>();
    int current_song_index;
    bool check_library;
    std::vector<std::string> songList;
    bool read_song_names(std::string dir, std::vector<std::string> &files);
    void notify_listeners(std::string song_path);

public:
    SongLoader();
    bool song_exists();
    void next_song_name();
    void previous_song_name();
    void io_event(std::string io_command);
    void next_song();
    void previous_song();
    void shuffle_songs();
};
