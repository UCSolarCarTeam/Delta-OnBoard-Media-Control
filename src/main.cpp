#include "SDL.h"

int main() {

    SDL SDLObject;

    if( !SDLObject.init_SDL() ) 
    {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        } 
        
        //Clear screen
        SDL_RenderClear(SDLObject.get_Renderer());

        //Update screen
        SDL_RenderPresent(SDLObject.get_Renderer());
    }

    //Free resources and close SDL
    SDLObject.close();

    return 0;
}
