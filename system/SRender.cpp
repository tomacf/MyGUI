#include "SRender.hh"

SRender::SRender() : win(0), renderer(0), env(false), event_catched(false), focused(NULL) {

}

SRender::~SRender() {
  if (win) {
    SDL_DestroyWindow(win);
  }
  if (renderer) {
    SDL_DestroyRenderer(renderer);
  }
  SDL_Quit();
}

bool SRender::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
    SDL_Quit();

    return false;
  }
  return true;
}

bool SRender::start(const std::string &title, int width, int height) {
  w = width;
  h = height;

  win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

  if (!win)
  {
    std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
    SDL_Quit();
    return false;
  }

  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)//gestion des erreurs
    {
      printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
      return EXIT_FAILURE;
    }
    return true;
  }

SDL_Event   &SRender::updateWait() {
  SDL_WaitEvent(&events);
  event_catched = true;
  return events;
}

SDL_Event   &SRender::updateWait(int i) {
  event_catched =  (SDL_WaitEventTimeout(&events, i) == 1) ? true : false;
  return events;
}

SDL_Event   &SRender::update() {
  event_catched = (SDL_PollEvent(&events) == 1) ? true : false;
  return events;
}

SDL_Event   &SRender::getEvent(){
  return events;
}

eVent       SRender::eEvent() {
  if (!event_catched) {
    // std::cout << "No event catched" << std::endl;
    return none;
  }
  switch(events.type)
  {
      case SDL_KEYUP:
        // std::cout << "SDL_KEYUP" << std::endl;
        return KeyReleased;
      case SDL_KEYDOWN:
        // std::cout << "SDL_KEYDOWN" << std::endl;
        return KeyPressed;
      case SDL_MOUSEMOTION:
        // std::cout << "SDL_MOUSEMOTION" << std::endl;
        return MouseMove;
      case SDL_MOUSEBUTTONUP:
        // std::cout << "SDL_MOUSEBUTTONUP" << std::endl;
        return MouseUp;
      case SDL_MOUSEBUTTONDOWN:
        // std::cout << "SDL_MOUSEBUTTONDOWN" << std::endl;
        return MouseDown;
      case SDL_MOUSEWHEEL:
        // std::cout << "SDL_MOUSEWHEEL" << std::endl;
        return MouseWheelUp;
      default:
        // std::cout << "Unknow event" << std::endl;
        return none;
  }
}

void        SRender::clear() {
  SDL_SetRenderDrawColor(renderer, 0,  0, 0, 1);
  SDL_RenderClear( renderer );
}

void        SRender::draw() {
  SDL_RenderPresent(renderer);
}

void        SRender::setRenderDrawColor(Uint8 r , Uint8 g, Uint8 b, Uint8 a) {
  SDL_SetRenderDrawColor(renderer, r,  g, b , a);
}

void        SRender::setRenderDrawRect(SDL_Rect *r) {
  SDL_RenderDrawRect( renderer, r );
}
void        SRender::setRenderDrawRect(int x, int y, int w, int h) {
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = h;

  SDL_RenderDrawRect( renderer, &r );
}

Entity  *SRender::focus(Entity *e) {
  if (e != NULL)
    focused = e;
  return focused;
}

int   SRender::getWidth() {
  return w;
}

int   SRender::getHeight() {
  return h;
}
