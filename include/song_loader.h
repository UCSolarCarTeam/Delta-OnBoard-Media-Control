#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include "I_song_loader_observer.h"
#include "I_io_event_observer.h"
#include "Observable.h"
#include "config.h"

#include <algorithm>
#include <vector>
#include <random>

class SongLoader : Observable<I_SongLoaderObserver> : public I_IoEventObserver
{
private:
    std::vector<std::string> files =std::vector<std::string>();
    int current_song_index;
    bool check_library;
    std::vector<std::string> songList;
    std::string current_song;
    bool read_song_names(std::string dir, std::vector<std::string> &files);
    void notify_listeners();

public:
    SongLoader();
    bool song_exists();
    std::string current_song();
    std::string next_song();
    std::string next_song_name();
    std::string previous_song();
    std::string previous_song_name();
    std::string shuffle_songs();
    void call_next_song(std::string io_command);
    void call_previous_song(std::string io_command);
    void show_next_song_name(std::string io_command);
    void show_previous_song_name(std::string io_command);
};
