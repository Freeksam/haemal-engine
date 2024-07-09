#include <SDL2/SDL.h>
#include <stdio.h>

#include "../include/sdl_base.h"

void initialize_sdl(context *c) {

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        printf("SDL could not be initialized: %s", SDL_GetError());

    (*c).window = SDL_CreateWindow("Ethan Loves Gambling",
                         SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED,
                         WINDOW_WIDTH, WINDOW_HEIGHT,
                         SDL_WINDOW_UTILITY);
    if(!(*c).window) printf("window could not be created: %s", SDL_GetError());

    (*c).renderer = SDL_CreateRenderer((*c).window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!(*c).renderer) printf("renderer could not be created: %s", SDL_GetError());
     
    SDL_RenderSetLogicalSize((*c).renderer, WINDOW_WIDTH/4, WINDOW_HEIGHT/4);

    (*c).texture = SDL_CreateTexture(
            (*c).renderer, 
            SDL_PIXELFORMAT_RGBA32,    
            SDL_TEXTUREACCESS_STREAMING,            
            WINDOW_WIDTH, WINDOW_HEIGHT);
    if(!(*c).texture) printf("texture could not be created: %s", SDL_GetError());
}

void cleanup_sdl(context *c) {
    SDL_DestroyTexture((*c).texture);
    SDL_DestroyRenderer((*c).renderer);
    SDL_DestroyWindow((*c).window);
}
