#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const float FRAME_INTERVAL = 16.667f;

static inline Uint32 getElapsedTime(Uint32 curr_time);
static inline void waitUntilNextFrame(Uint32 start_time);
