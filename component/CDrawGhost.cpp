#include "CDrawGhost.hh"

CDrawGhost::CDrawGhost(Entity *_e) : CDraw(NULL, _e) {

}

CDrawGhost::~CDrawGhost() {

}

bool CDrawGhost::contains(int x, int y) {
  return true;
}


void        CDrawGhost::draw() {
  propagateChildren();
}