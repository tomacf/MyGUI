#include "CDraw.hh"

CDraw::CDraw(SRender *_o, Entity *_e) {
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