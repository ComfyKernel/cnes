#include <cnes/log.hpp>
#include <cnes/video.hpp>

#include <SDL2/SDL.h>

bool cnes::initSDL2() {
  linfo<<"Initializing SDL2...\n";

  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    lerror<<"Failed to initialize SDL2!\n";
    lerror<<SDL_GetError()<<"\n";
    return false;
  }

  linfo<<"SDL2 Initialized\n";

  return true;
}

void cnes::quitSDL2() {
  linfo<<"Quitting SDL2...\n";
  SDL_Quit();
  linfo<<"SDL2 Quit\n";
}
