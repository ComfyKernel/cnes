#include <cnes/log.hpp>
#include <cnes/video.hpp>

int main(int argc, char *argv[]) {
  linfo<<"Starting CNES\n";

  if(!cnes::initSDL2()) {
    lcrit<<"SDL2 Has to be initialized for CNES to continue!\n";
    return 1;
  }

  cnes::window win;
  if(!win.open("CNES", 600, 400)) {
    lcrit<<"Cannot continue CNES without a window!\n";
    return 2;
  }

  cnes::quitSDL2();
  
  return 0;
}
