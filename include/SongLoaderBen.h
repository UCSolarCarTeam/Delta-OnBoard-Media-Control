#pragma once
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

class SongLoaderBen
{
private:
    std::vector<std::string> files =std::vector<std::string>();
    int currentSongIndex;
    bool checkLibrary;
    std::vector<std::string> songList;
    std::string CurrentSong;
    bool readSongNames(std::string dir, std::vector<std::string> &files);

public:
    SongLoaderBen();
    bool nextSong();
    bool previousSong();
    std::string currentSong();
    bool songExists();
    std::string gotoNextSong();
    std::string gotoPreviousSong();
    
    int shuffleSongs();
};
