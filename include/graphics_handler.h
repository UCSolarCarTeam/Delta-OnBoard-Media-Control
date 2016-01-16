#pragma once

#include <SDL.h>


class GraphicsHandler {

public:
    void draw(SDL_Texture *texture, SDL_Rect location_rect); 
    void draw(SDL_Texture *texture, int x_pos, int y_pos);
};
