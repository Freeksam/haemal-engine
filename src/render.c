#include <SDL2/SDL.h>

#include "sdl_base.h"
#include "render.h"

void render_scene(context *c, scene *s) {
    
    (*s).pitch = 0; 
    (*s).texture_info = NULL;

    if (SDL_LockTexture((*c).texture, NULL, &(*s).texture_info, &(*s).pitch) != 0) {
        printf("texture could not be locked: %s", SDL_GetError());
    } else {
        memcpy((*s).texture_info, (*s).buffer, (*s).pitch * WINDOW_HEIGHT);
        memset((*s).buffer, 0, sizeof((*s).buffer));
    }

    SDL_UnlockTexture((*c).texture);

    SDL_RenderClear((*c).renderer);
    SDL_RenderCopyEx((*c).renderer, (*c).texture, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent((*c).renderer);
}
