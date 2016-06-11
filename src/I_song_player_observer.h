#include <vector>
#pragma once

class I_SongPlayerObserver
{
public:
    virtual void current_song(std::string song_path) = 0;

    virtual void current_volume(double volume) = 0; 

    virtual void current_time(double time) = 0;
};
