#include "CDrawRectangle.hh"

CDrawRectangle::CDrawRectangle(SRender *_o, Entity *_e) : CDraw(_o, _e)
{

}

#include <iostream>

void        CDrawRectangle::draw() {

  int x,y,w,h;

  e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
  o->setRenderDrawColor(x, y, w, h);
  e->getAttr<GEOMETRY>()->getXYWH(&x, &y, &w, &h);
  o->setRenderDrawRect(x, y, w, h);
  propagateChildren();
}


void      CDrawRectangle::propagateChildren() {
  children_map children = e->getAttr<CHILDREN>()->getAll();

  for (children_map::iterator i = children.begin(); i != children.end(); ++i) {
    i->second->getAttr<DRAW>()->draw();
  }
}