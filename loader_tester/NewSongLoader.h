#ifndef SONG_LOADER_H
#define SONG_LOADER_H
#include <string>
#include <stdlib.h>
#include <dirent.h>
#include <unordered_map> 
#include <iosteam>
#include <cassert>

//headers for randomizing
#include <algorithm>
#include <vector>
#include <random>

class SongLoader
{
    int counter,song,checkLibrary;
    std::vector<std::string> container;
    std::string CurrentSong;
    int readSongNames();

}
