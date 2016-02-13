#pragma once

#include <cv.h>
#include "opencv2/opencv.hpp"
//for the rasperry pi
#ifndef INT64_C
#define INT64_C(c) (c ## LL)
#define UINT64_C(c) (c ## ULL)
#endif
extern "C" {
    #include <SDL.h>
    #include <SDL_ttf.h>
}
#include <stdio.h>
#include <unistd.h>

#ifdef __amd64__
    #ifndef RUNNINGONINTEL
    #define RUNNINGONINTEL
    #endif
#else
    #ifndef RUNNINGONPI
    #define RUNNINGONPI
    #endif
    #include "WiringPiButtons.hpp"
#endif

#define SCREEN_HEIGHT 768
#define SCREEN_WIDTH 1232


#include "MusicBar.h"
#include "SongPlayer.h"
#include "graphics_handler.h"
#include "videoStream.hpp"




class BackupCamera {


public: 
    BackupCamera();
    bool init(SDL_Renderer **empty_renderer, SDL_Window **empty_window);
    bool init_graphics(SDL_Renderer *renderer);
    bool init_screen_settings(SDL_Window *window, int camera_device, int camera_height, int camera_width);
    bool process_events();
    bool update();
    void start_threads();

    void close();

private:
    bool init_SDL(SDL_Renderer **empty_renderer, SDL_Window **empty_window);
    void init_graphics_handler(SDL_Renderer *renderer);
    void processGPIO();
    void signalToQuit(); 

    //SDL_Renderer *renderer_;
    //SDL_Window *window_;
    GraphicsHandler *graphics_handler_;
    SongPlayer *song_player_one_;

    /** Displayable **/
    VideoStream *camera_one_; 
    MusicBar *music_bar_one_;


};
