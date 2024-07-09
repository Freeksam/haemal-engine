#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "colors.h"
#include "draw.h"
#include "sdl_base.h"
#include "triangle.h"
#include "vector.h"
#include "render.h"

context main_context;
scene   main_scene;

int main() {

    initialize_sdl(&main_context);
    render_scene(&main_context, &main_scene);
        
    bool quit = false;
    SDL_Event ev;

    while(!quit) {

        while (SDL_PollEvent(&ev) != 0) {
            switch(ev.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
            }   
        }
    }

    cleanup_sdl(&main_context);
    SDL_Quit();

    return 0;
}
