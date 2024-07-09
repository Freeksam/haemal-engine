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

context        main_context;
renderbuffer   main_renderbuffer;

int main() {

    initialize_context(&main_context);

    vector2i points[3] = {{300, 300}, {200, 200}, {200, 350}};

    draw_triangle(main_renderbuffer.buffer, B_YELLOW, points);

    render_buffer(&main_context, &main_renderbuffer);
        
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

    cleanup_context(&main_context);
    SDL_Quit();

    return 0;
}
