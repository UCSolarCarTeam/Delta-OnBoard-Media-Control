#ifndef SONG_LOADER_H
#define SONG_LOADER_H
#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>
#include <stdio.h>

//headers for randomizing
#include <algorithm>
#include <vector>
#include <random>

class SongLoader
{
private:
    int currentSongIndex;
    bool checkLibrary;
    std::vector<std::string> songList;
    std::string CurrentSong;
    int readSongNames();
    int shuffleSongs();

public:
    SongLoader();
    std::string nextSong();
    std::string previousSong();
    std::string crrentSong();
    bool songExists();
};
#endif
