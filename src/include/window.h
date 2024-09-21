#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Window {
private:
  SDL_Window *sdl_window;
  SDL_Renderer *renderer;
  TTF_Font *font;

  int width, height;
  std::string title;


public:
  Window(int width, int height, const std::string title);
  ~Window();


};
