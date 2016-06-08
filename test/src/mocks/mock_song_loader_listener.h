#pragma once 
#include "gmock/gmock.h"
#include "I_song_loader_observer.h"


class MockSongLoaderListener : public I_SongLoaderObserver {

public: 
    MOCK_METHOD1(current_song, void(std::string));
};




