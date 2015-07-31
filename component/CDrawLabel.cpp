#include "CDrawLabel.hh"

CDrawLabel::CDrawLabel(SRender *_o, Entity *_e) : CDraw(_o, _e) {
  ready = false;
}

bool CDrawLabel::contains(int _x, int _y) {
  data_map    coord = e->getAttr<GEOMETRY>()->getData();

  if ((_x >= coord["x"]) && (_x <= coord["x"] + coord["w"]) && (_y >= coord["y"]) && (_y <= coord["y"] + coord["h"]))
    return true;
  return false;
}


void        CDrawLabel::init() {
  text.setFont(o->getFont());
  ready = true;
}

void        CDrawLabel::draw() {
  if (!ready)
    init();
  if (e->getAttr<LABEL>()->hasChange()) {
    text.setString(e->getAttr<LABEL>()->getLabel());
    text.setCharacterSize(e->getAttr<LABEL>()->getFontSize());
  }
  if (e->getAttr<GEOMETRY>()->hasChange()) {
    data_map    coord = e->getAttr<GEOMETRY>()->getData();
    text.setPosition(coord["x"], coord["y"]);
  }
  if (e->getAttr<COLOR>()->hasChange()) {
    int x,y,w,h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
    text.setColor(sf::Color(x, y, w));
  }
  o->getWin().draw(text);
}