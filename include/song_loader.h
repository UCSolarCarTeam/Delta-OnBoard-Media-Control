#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include "I_song_loader_observer.h"
#include "Observable.h"
#include "config.h"

#include <algorithm>
#include <vector>
#include <random>

class SongLoader : Observable<I_SongLoaderObserver>
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
    std::string next_song();
    std::string previous_song();
    bool song_exists();
    std::string current_song();
    std::string go_to_next_song();
    std::string go_to_previous_song();
    std::string shuffle_songs();
};
