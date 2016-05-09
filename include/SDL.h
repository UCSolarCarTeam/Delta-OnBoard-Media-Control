#pragma once
#include <SDL2/SDL.h>

class SDL {
public:
    SDL();
    bool init_SDL();
    void close();
    SDL_Window *get_Window() { return window; };
    SDL_Renderer *get_Renderer() { return renderer; };

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
    

