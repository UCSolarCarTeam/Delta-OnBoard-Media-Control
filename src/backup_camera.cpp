#include "backup_camera.h"


bool BackupCamera::init(SDL_Renderer *empty_renderer, SDL_Window *empty_window) {
    bool success = true;
    success = init_SDL(empty_renderer, empty_window) && success; 

    //empty_renderer shouldn't be empty after init_SDL()
    graphics_handler_ = new GraphicsHandler(empty_renderer); 

    return success;
}

bool BackupCamera::init_SDL(SDL_Renderer *empty_renderer, SDL_Window *empty_window) {
    bool success = true;
    if (SDL_Init(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        empty_window = SDL_CreateWindow("Video Application", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (empty_window == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            empty_renderer = SDL_CreateRenderer(empty_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (empty_renderer == NULL)
            {
                printf("Renderer could not be created. SDL_Error: %s \n", SDL_GetError());
                printf("Creating a software empty_renderer instead\n");
                empty_renderer = SDL_CreateRenderer(empty_window, -1, SDL_RENDERER_SOFTWARE);
                if (empty_renderer == NULL)
                {
                    printf("Renderer could not be created. SDL_Error: %s \n", SDL_GetError());
                    success = false;                    
                    //SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                }
            }
        }
    }
    return success;
}
void BackupCamera::init_screen_settings() {
    //music_bar_one_->init_setting();
    camera_one_->init_setting();

}
void BackupCamera::BackupCamera::update() {
    camera_one_->update(graphics_handler_);
    //music_bar_one_->update(graphics_handler_);
}
void BackupCamera::process_events() {
    SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    printf("SDL_QUIT was called\n");
                    signalToQuit();
                    close();
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            printf("Esc was Pressed!\n");
                            signalToQuit();
                            close();
                            break;
                        case SDLK_LEFT:
                            printf("Left arrow was Pressed!\n");
                            song_player_one_->previousSong();
                            break;
                        case SDLK_RIGHT:
                            printf("Right arrow was Pressed!\n");
                            song_player_one_->nextSong();
                            break;
                        case SDLK_UP: song_player_one_->changeVolume(0.02); break;
                        case SDLK_DOWN:
                            song_player_one_->changeVolume(-0.02);
                            break;
                        case SDLK_SPACE:
                            printf("Space was pressed!\n");
                            song_player_one_->playPause();
                    }
            }
        }

}
void BackupCamera::processGPIO() {

}

void signalToQuit() {

}

void BackupCamera::close() {

}
    

