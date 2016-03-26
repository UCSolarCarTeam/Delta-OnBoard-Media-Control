#include <SDL2/SDL.h>

class SDL {
public:
    SDL();
    bool init_SDL();
    void close();
    SDL_Window *get_Window() const { return window; };
    SDL_Renderer* get_Renderer() const { return renderer; };

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
    

