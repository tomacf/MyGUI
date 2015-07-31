#include "CDraw.hh"

CDraw::CDraw(SRender *_o, Entity *_e) : Component() {
  o = _o;
  e = _e;
}

CDraw::~CDraw() {
  delete o;
  delete e;
}

CDraw *CDraw::setRender(SRender *_o) {
  o = _o;
  return this;
}

SRender *CDraw::getRender() {
  return o;
}

void      CDraw::propagateChildren() {
  if (e->getAttr<CHILDREN>()->hasChange())
    children = e->getAttr<CHILDREN>()->getAll();

  for (children_map::iterator i = children.begin(); i != children.end(); ++i) {
    i->second->getAttr<DRAW>()->draw();
  }
}