#include "CDrawRectangle.hh"

CDrawRectangle::CDrawRectangle(SRender *_o, Entity *_e) : CDraw(_o, _e)
{

}


void        CDrawRectangle::draw() {
  if (e->getAttr<GEOMETRY>()->hasChange()) {
    data_map    coord = e->getAttr<GEOMETRY>()->getData();
    rectangle.setPosition(coord["x"], coord["y"]);
    rectangle.setSize(sf::Vector2f(coord["w"], coord["h"]));
  }
  if (e->getAttr<COLOR>()->hasChange()) {
    int x, y, w, h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
    rectangle.setFillColor(sf::Color(x, y, w, h));
  }
  o->getWin().draw(rectangle);
  propagateChildren();
}

bool        CDrawRectangle::contains(int _x, int _y) {
  data_map    coord = e->getAttr<GEOMETRY>()->getData();

  if ((_x >= coord["x"]) && (_x <= coord["x"] + coord["w"]) && (_y >= coord["y"]) && (_y <= coord["y"] + coord["h"]))
    return true;
  return false;
}