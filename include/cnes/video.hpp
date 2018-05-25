#pragma once

namespace cnes {
  bool initSDL2();
  void quitSDL2();
  
  class window {
    struct _sdlinfo;
    _sdlinfo* _sdl;
  public:
    int x() const;
    int y() const;

    int width () const;
    int height() const;

    bool open(const char* name, unsigned width = 0, unsigned height = 0);
    void close();

    void delay(unsigned ms = 0);

    window();
    window(const char* name, unsigned width = 0, unsigned height = 0);
    ~window();
  };
};
