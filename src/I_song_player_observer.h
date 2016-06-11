#include <vector>
#pragma once

class I_SongPlayerObserver
{
public:
    virtual void current_song(std::string song_path) = 0;
};
