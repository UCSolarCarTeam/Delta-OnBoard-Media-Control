#ifndef SONGPLAYER_H
#define SONGPLAYER_H

#include <ao/ao.h>
#include <mpg123.h>
//#include "config.h"
#include <string>
#include "song_loader.h"
#include "I_song_player_observer.h"
#include "Observable.h"
#include "I_threadable.h"
#include <cstring>
#include <unistd.h>

#define BITS 8

class SongPlayer : public Observable<I_SongPlayerObserver> 
{

public:
        void SongPLayer();
        int initSongPlayer();
        void closeSongPlayer();

        /*Song Control*/
        void playPause();
        void changeVolume(double change);

        /*For the time bar*/
        double getCurrentTime();
        double getSongLength();
        double getVolume();
        double getMaxVolume();
        std::string currentSong();

        void songQuit();

        void play();
        void next_song();
        void previous_song();
        void shuffle_song();
        void pause();

    protected:
        void ThreadFunction();

    private: 
        size_t done;
        double MAX_VOLUME;

        void freeMusic();
        int loadSong(char* songName);
        SongLoader loader;
        double volume;

        /*mpg123 specific variables*/ 
        unsigned char *buffer;
        size_t buffer_size;
        bool loaded;
        mpg123_handle *mh;
        ao_sample_format format;
        ao_device *dev;
        int channels, encoding;
        long rate;
        bool quitSong;

        /*Modes*/
        enum threadMode { PLAY, NEXT, PREVIOUS, SHUFFLE, PAUSE};
        threadMode mode;
};

#endif /* SONGPLAYER_H */
