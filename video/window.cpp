#include <cnes/log.hpp>
#include <cnes/video.hpp>

#include <SDL2/SDL.h>

struct cnes::window::_sdlinfo {
public:
  SDL_Window* window = nullptr;
  SDL_GLContext ctx;
  bool is_open = false;
};

const char* cnes::window::name() const {
  return _name;
}

bool cnes::window::open(const char* name, unsigned width, unsigned height) {
  linfo<<"Opening window '"<<name<<"'\n";

  _sdl->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

  if(!_sdl->window) {
    lerror<<"Failed to open an SDL2 Window!\n";
    lerror<<SDL_GetError();
    return false;
  }

  _name = name;

  return true;
}

void cnes::window::close() {
  linfo<<"Closing window '"<<_name<<"'\n";

  SDL_DestroyWindow(_sdl->window);
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
  close();
  delete _sdl;
}
