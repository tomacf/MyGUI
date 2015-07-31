#include "CDrawTriangle.hh"

CDrawTriangle::CDrawTriangle(SRender *_o, Entity *_e) : CDraw(_o, _e)
{
  triangle.setPointCount(3);
}


void        CDrawTriangle::draw() {
  if (e->getAttr<GEOMETRY>()->hasChange()) {
    data_map    coord = e->getAttr<GEOMETRY>()->getData();
    triangle.setPosition(coord["x"], coord["y"]);
    triangle.setRadius(coord["w"]);
  }
  if (e->getAttr<COLOR>()->hasChange()) {
    int x,y,w,h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
    triangle.setFillColor(sf::Color(x, y, w, h));
    triangle.setOutlineColor(sf::Color::Red);
  }
  o->getWin().draw(triangle);
  propagateChildren();
}

float       CDrawTriangle::sign(sf::Vector2f &p1, sf::Vector2f &p2, sf::Vector2f &p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool        CDrawTriangle::contains(int _x, int _y) {
  data_map    coord = e->getAttr<GEOMETRY>()->getData();

  sf::Vector2f      origin(coord["x"], coord["y"]);
  sf::Vector2f      v1 = origin + triangle.getPoint(0);
  sf::Vector2f      v2 = origin + triangle.getPoint(1);
  sf::Vector2f      v3 = origin + triangle.getPoint(2);
  sf::Vector2f      pt(_x, _y);

  bool b1, b2, b3;
  b1 = sign(pt, v1, v2) < 0.0f;
  b2 = sign(pt, v2, v3) < 0.0f;
  b3 = sign(pt, v3, v1) < 0.0f;

  return ((b1 == b2) && (b2 == b3));
}