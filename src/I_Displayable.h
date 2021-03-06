#pragma once
#include <SDL2/SDL.h>

// in main add every displayable object to an displayable_array
// for each object in displayable_array call the display() function
//      i) DESIGN CHOICE 1
//      display will return a texture where it will be RenderCopy() inside the loop (in main)

class I_Displayable 
{
public:
    virtual SDL_Texture* display(SDL_Renderer *renderer) = 0;
};
