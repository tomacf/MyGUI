#ifndef CEVENT_HH_
#define CEVENT_HH_

#include <map>
#include "Entity.hh"
#include "Component.hh"
#include "SRender.hh"
#include "eVent.hh"
#include "CChildren.hh"
#include "CGeometry.hh"

class CEvent;
typedef CEvent* EVENT;

class CEvent : public Component
{
  SRender     *o;
  Entity      *e;

  std::map<eVent, void (*)(Entity *, SDL_Event &)> map_function;

public:
  CEvent(SRender *, Entity *);
  ~CEvent();

  CEvent *setEvent(eVent, void (*)(Entity *, SDL_Event &));
  CEvent *receiveEvent(eVent, SDL_Event &);
  CEvent *checkEvent();
  CEvent *checkEvent(eVent, SDL_Event &);
  void    propagateChildren(eVent, SDL_Event &);

};

#endif