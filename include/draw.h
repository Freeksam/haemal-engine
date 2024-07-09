#pragma once

#include "vector.h"

void draw_pixel(uint8_t *buffer, int x, int y, SDL_Color color);
void draw_line(uint8_t *buffer, SDL_Color color, vector2i p0, vector2i p1);
void draw_triangle(uint8_t *buffer, SDL_Color color, vector2i p[3]);
