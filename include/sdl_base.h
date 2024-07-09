#pragma once

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT 720

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
} context;

typedef struct {
    uint8_t buffer[WINDOW_WIDTH*WINDOW_HEIGHT*4];
    int pitch;
    void* texture_info;
} scene;

void initialize_sdl(context *c);
void cleanup_sdl(context *c);
