#include <vector>
#pragma once

class I_SongLoaderObserver
{
public:
    virtual void current_song(std::string song_path) = 0;
};
