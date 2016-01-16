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
#include "videoStream.hpp"


class BackupCamera {




private:
    SDL_Renderer *renderer_;
    SDL_Window *window_;

    VideoStream *camera_one_; 








};
