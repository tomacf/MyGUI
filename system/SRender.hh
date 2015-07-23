#ifndef SRENDER_HH
#define SRENDER_HH

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "eVent.hh"
#include "Entity.hh"

class SRender
{
  bool            env;
  bool            event_catched;

  SDL_Window*     win;
  SDL_Renderer*   renderer;
  SDL_Event       events;

  Entity          *focused;
  int             w;
  int             h;

public:
  SRender();
  ~SRender();

  bool init();
  bool start(const std::string &title = "Engine", int width = 800, int height = 600);

  SDL_Event &updateWait();
  SDL_Event &updateWait(int);
  SDL_Event &update();
  SDL_Event &getEvent();

  eVent     eEvent();

  void  clear();
  void  draw();
  void  setRenderDrawColor(Uint8, Uint8, Uint8, Uint8);
  void  setRenderDrawRect(int, int, int ,int);
  void  setRenderDrawRect(SDL_Rect *);

  int   getWidth();
  int   getHeight();
  Entity  *focus(Entity * = NULL);
};


#endif