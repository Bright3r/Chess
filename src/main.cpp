#include "main.h"
#include "window.h"

int main(void) {
  Window win(400, 600, "Chess");

  bool is_running = true;
  SDL_Event event;
  while (is_running) {
    uint32_t start_time = SDL_GetTicks();

    // Event handling
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        is_running = false;
      else if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
          case SDLK_RETURN: is_running = false; break;
        }
      }
    }

    // Draw
    win.clear();
    win.update();

    // Cap framerate
    waitUntilNextFrame(start_time);
  }

  return 0;
}

static inline Uint32 getElapsedTime(Uint32 curr_time) {
  return SDL_GetTicks() - curr_time;
}

static inline void waitUntilNextFrame(Uint32 start_time) {
  Uint32 delay = (Uint32) std::floor(FRAME_INTERVAL - getElapsedTime(start_time));

  // If delay > frame time, there was overflow and we have already missed a frame
  if (delay > FRAME_INTERVAL)
    delay = 0;

  SDL_Delay(delay);
}
