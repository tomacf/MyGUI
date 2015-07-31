#include "CEvent.hh"

CEvent::CEvent(SRender *_o, Entity *_e) : Component() {
  o = _o;
  e = _e;
}

CEvent::~CEvent() {
  map_function.clear();
}

CEvent *CEvent::setEvent(sf::Event::EventType ev, void (*fct)(Entity *, sf::Event &)) {
  map_function[ev] = fct;
  return this;
}

CEvent *CEvent::receiveEvent(sf::Event &event) {
  if (map_function.find(event.type) != map_function.end())
    map_function[event.type](e, event);
  propagateChildren(event);
  return this;
}

void    CEvent::propagateChildren(sf::Event &event) {
  children_map children = e->getAttr<CHILDREN>()->getAll();

  for (children_map::iterator i = children.begin(); i != children.end(); ++i) {
    i->second->getAttr<EVENT>()->checkEvent(event);
  }
}

CEvent *CEvent::checkEvent(sf::Event &event) {
  // If it's a click, change focus and check if focus is on children
  if (event.type == sf::Event::MouseButtonPressed) {
    if (e->getAttr<DRAW>()->contains(event.mouseButton.x, event.mouseButton.y))
    {
      o->focus(e);
      receiveEvent(event);
    }
  } // If we have a focus then receiveEvent and propagate children
  else if (o->focus() == e) {
    receiveEvent(event);
  } else { // If we don't have focus check if children have, propagate
    propagateChildren(event);
  }
  return this;
}