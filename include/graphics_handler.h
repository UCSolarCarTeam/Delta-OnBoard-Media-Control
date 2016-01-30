#pragma once

#include <SDL.h>


class GraphicsHandler {

public:
    GraphicsHandler(SDL_Renderer *renderer);
    void draw(SDL_Texture *texture, SDL_Rect location_rect); 
    void draw(SDL_Texture *texture, int x_pos, int y_pos);
private:
    SDL_Renderer *renderer_;
};
