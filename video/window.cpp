#include <cnes/log.hpp>
#include <cnes/video.hpp>

#include <SDL2/SDL.h>

struct cnes::window::_sdlinfo {
public:
  SDL_Window* window = nullptr;
  SDL_GLContext ctx;
  bool is_open = false;
};

bool cnes::window::open(const char* name, unsigned width, unsigned height) {
  linfo<<"Opening window '"<<name<<"'\n";
  
  _sdl->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if(!_sdl->window) {
    lerror<<"Failed to open an SDL2 Window!\n";
    lerror<<SDL_GetError();
    return false;
  }
  
  return true;
}

void cnes::window::close() {

}

void cnes::window::delay(unsigned ms) {
  SDL_Delay(ms);
}

cnes::window::window()
  : _sdl{new _sdlinfo()} {
}

cnes::window::window(const char* name, unsigned width, unsigned height)
  : _sdl{new _sdlinfo()} {
  open(name ,width, height);
}

cnes::window::~window() {
  SDL_DestroyWindow(_sdl->window);
  delete _sdl;
}
