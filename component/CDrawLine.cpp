#include "CDrawLine.hh"

CDrawLine::CDrawLine(SRender *_o, Entity *_e) : CDraw(_o, _e) {

}

bool CDrawLine::contains(int x, int y) {
  data_map    coord = e->getAttr<GEOMETRY>()->getData();

  return false;
}


void        CDrawLine::draw() {
  if (e->getAttr<GEOMETRY>()->hasChange() || e->getAttr<COLOR>()->hasChange()) {
    int x,y,w,h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);

    data_map    coord = e->getAttr<GEOMETRY>()->getData();
    lines.clear();
    lines.setPrimitiveType(sf::LinesStrip);
    lines.append(sf::Vertex(sf::Vector2f(coord["x1"], coord["y1"]), sf::Color(x, y, w)));
    lines.append(sf::Vertex(sf::Vector2f(coord["x2"], coord["y2"]), sf::Color(x, y, w)));
  }
  o->getWin().draw(lines);
}