#include "CEvent.hh"

CEvent::CEvent(SRender *_o, Entity *_e) {
  o = _o;
  e = _e;
}

CEvent::~CEvent() {
  map_function.clear();
}

CEvent *CEvent::setEvent(eVent ev, void (*fct)(Entity *, SDL_Event &)) {
  map_function[ev] = fct;
  return this;
}

CEvent *CEvent::receiveEvent(eVent ev, SDL_Event &event) {
  if (map_function.find(ev) != map_function.end())
    map_function[ev](e, event);
  propagateChildren(ev, event);
  return this;
}

void    CEvent::propagateChildren(eVent ev, SDL_Event &event) {
  children_map children = e->getAttr<CHILDREN>()->getAll();

  for (children_map::iterator i = children.begin(); i != children.end(); ++i) {
    i->second->getAttr<EVENT>()->checkEvent(ev, event);
  }
}
//fct p propagate children

CEvent *CEvent::checkEvent() {
  eVent ev = o->eEvent();
  SDL_Event &event = o->getEvent();

  if (ev == MouseDown || ev == MouseUp || ev == MouseMove) {
    if (e->getAttr<GEOMETRY>()->checkPos(event.button.x, event.button.y))
    {
      o->focus(e);
      receiveEvent(o->eEvent(), o->getEvent());
    }
  }
  return this;
}

CEvent *CEvent::checkEvent(eVent ev, SDL_Event &event) {
  if (ev == MouseDown || ev == MouseUp || ev == MouseMove) {
    if (e->getAttr<GEOMETRY>()->checkPos(event.button.x, event.button.y))
    {
      o->focus(e);
      receiveEvent(o->eEvent(), o->getEvent());
    }
  } // remove else if we have main container
  else if (o->focus() == e) {
    receiveEvent(ev, event);
  }
  else {
    propagateChildren(ev, event);
  }

  return this;
}