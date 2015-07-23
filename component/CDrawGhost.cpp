#include "CDrawGhost.hh"

CDrawGhost::CDrawGhost(Entity *_e) : CDraw(NULL, _e) {

}

CDrawGhost::~CDrawGhost() {

}

void        CDrawGhost::draw() {
  children_map children = e->getAttr<CHILDREN>()->getAll();

  for (children_map::iterator i = children.begin(); i != children.end(); ++i) {
    i->second->getAttr<DRAW>()->draw();
  }
}
