#include "CDrawCircle.hh"

CDrawCircle::CDrawCircle(SRender *_o, Entity *_e) : CDraw(_o, _e)
{

}


void        CDrawCircle::draw() {

  if (e->getAttr<GEOMETRY>()->hasChange()) {
    data_map coord = e->getAttr<GEOMETRY>()->getData();
    circle.setPosition(coord["x"], coord["y"]);
    circle.setRadius(coord["w"]);
  }
  if (e->getAttr<COLOR>()->hasChange()) {
    int x,y,w,h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
    circle.setFillColor(sf::Color(x, y, w, h));
  }
  o->getWin().draw(circle);
  propagateChildren();
}


bool        CDrawCircle::contains(int _x, int _y) {
  data_map    geo = e->getAttr<GEOMETRY>()->getData();

  if ((_x - (geo["x"] + geo["w"]/2))*(_x - (geo["x"] + geo["w"]/2)) + (_y - (geo["y"] + geo["w"]/2))*(_y - (geo["y"] + geo["w"]/2)) < (geo["w"] * geo["w"]))
    return true;
  return false;
}