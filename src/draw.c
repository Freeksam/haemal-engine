#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/draw.h"
#include "../include/sdl_base.h"
#include "../include/swap.h"
#include "../include/vector.h"

void draw_pixel(uint8_t *buffer, int x, int y, SDL_Color color) {
    buffer[(x*4) + (y*WINDOW_WIDTH*4) + 0] = color.r;
    buffer[(x*4) + (y*WINDOW_WIDTH*4) + 1] = color.g;
    buffer[(x*4) + (y*WINDOW_WIDTH*4) + 2] = color.b;
    buffer[(x*4) + (y*WINDOW_WIDTH*4) + 3] = color.a;
}

static void draw_linel(uint8_t *buffer, SDL_Color color, vector2i p0, vector2i p1) {
    
    vector2i d;

    d.x = p1.x - p0.x;
    d.y = p1.y - p0.y;

    int yi = 1;
    if (d.y < 0) {
        yi = -1;
        d.y = -d.y;
    }
    int D = (2 * d.y) - d.x;
    int y = p0.y;

    for (int x = p0.x; x <= p1.x; x++) {
        draw_pixel(buffer, x, y, color);
        if (D > 0) {
            y += yi;
            D += (2 * (d.y - d.x));
        } else {
            D += 2 * d.y;
        }
    }
}

static void draw_lineh(uint8_t *buffer, SDL_Color color, vector2i p0, vector2i p1) {
    
    vector2i d;

    d.x = p1.x - p0.x;
    d.y = p1.y - p0.y;
    
    int xi = 1;
    if (d.x < 0) {
        xi = -1;
        d.x = -d.x;
    }
    int D = (2 * d.x) - d.y;
    int x = p0.x;

    for (int y = p0.y; y <= p1.y; y++) {
        draw_pixel(buffer, x, y, color);
        if (D > 0) {
            x += xi;
            D += (2 * (d.x - d.y));
        } else {
            D += 2 * d.x;
        }
    }
}

void draw_line(uint8_t *buffer, SDL_Color color, vector2i p0, vector2i p1) {

    // Implementation of the Bresenham algorithm 
    if (abs(p1.y - p0.y) < abs(p1.x - p0.x)) {
        if (p0.x > p1.x) {
            draw_linel(buffer, color, p1, p0);
        } else {
            draw_linel(buffer, color, p0, p1);
        }
    } else {
       if (p0.y > p1.y) {

            draw_lineh(buffer, color, p1, p0);
       } else {
            draw_lineh(buffer, color, p0, p1);
       }
    }
}

void draw_triangle(uint8_t *buffer, SDL_Color color, vector2i p[3]) {
    draw_line(buffer, color, p[0], p[1]);
    draw_line(buffer, color, p[0], p[2]);
    draw_line(buffer, color, p[1], p[2]);
}
