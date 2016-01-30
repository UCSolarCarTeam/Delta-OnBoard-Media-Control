#include "backup_camera.h"
#include <SDL.h>

int main()
{
    BackupCamera *backup_camera = new BackupCamera();
    SDL_Renderer *renderer = NULL;
    SDL_Window *window = NULL; 

    if (!backup_camera->init(&renderer, &window))
    {
        fprintf(stderr, "Could not initialize!\n");
        return -1;
    }

    if (renderer == NULL) {
        printf("BRO IT WS NULL!!!!!!!!\n");
    }

    backup_camera->start_threads();

    while (1)
    {
        backup_camera->process_events();
        backup_camera->update();
        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
    }

    backup_camera->close();
}
