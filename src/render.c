#include <SDL2/SDL.h>

#include "sdl_base.h"
#include "render.h"

void render_buffer(context *c, renderbuffer *rb) {
    
    (*rb).pitch = 0;
    void *texture_info = NULL;

    if (SDL_LockTexture((*c).texture, NULL, &texture_info, &(*rb).pitch) != 0) {
        printf("texture could not be locked: %s", SDL_GetError());
    } else {
        memcpy(texture_info, (*rb).buffer, (*rb).pitch * WINDOW_HEIGHT);
        memset((*rb).buffer, 0, sizeof((*rb).buffer));
    }

    SDL_UnlockTexture((*c).texture);

    SDL_RenderClear((*c).renderer);
    SDL_RenderCopyEx((*c).renderer, (*c).texture, NULL, NULL, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderPresent((*c).renderer);
}
