#include "window.h"

Window::Window(int width, int height, const std::string title)
  : width(width), height(height), title(title) {
  // Video
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    std::cerr << "SDL_Init has failed: %s\n" << SDL_GetError() << std::endl;

  // Fonts
  if (TTF_Init() < 0)
    std::cerr << "TTF_Init has failed: %s\n" << TTF_GetError() << std::endl;

  // this->font = TTF_OpenFont("./assets/fonts/PixelifySans-VariableFont_wght.ttf", 24);
  // if (!font)
    // std::cerr << "Failed to open font: %s\n" << TTF_GetError() << std::endl;

  this->sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if (!this->sdl_window)
    std::cerr << "Failed to create window: %s\n" << SDL_GetError() << std::endl;

  this->renderer = SDL_CreateRenderer(this->sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
    std::cerr << "Failed to render window: %s\n" << SDL_GetError() << std::endl;

  SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
}

Window::~Window() {
  // TTF_CloseFont(this->font);
  TTF_Quit();

  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->sdl_window);

  SDL_Quit();
}
