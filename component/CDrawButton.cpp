#include "CDrawButton.hh"

CDrawButton::CDrawButton(SRender *_o, Entity *_e) : CDraw(_o, _e)
{
  ready = false;
}

void        CDrawButton::init(){
  label.setFont(o->getFont());
  ready = true;
}

void        CDrawButton::draw() {

  if (!ready)
    init();

  if (e->getAttr<LABEL>()->hasChange()) {
    label.setString(e->getAttr<LABEL>()->getLabel());
    label.setCharacterSize(e->getAttr<LABEL>()->getFontSize());
  }
  if (e->getAttr<GEOMETRY>()->hasChange()) {
    data_map    coord = e->getAttr<GEOMETRY>()->getData();

    label.setPosition(coord["x"] + (coord["w"] - label.getGlobalBounds().width)/2, coord["y"] + (coord["h"] - label.getGlobalBounds().height)/2 - 10);
    button.setPosition(coord["x"], coord["y"]);
    button.setSize(sf::Vector2f(coord["w"], coord["h"]));
  }
  if (o->focus() == e) {
    int x, y, w, h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
    button.setFillColor(sf::Color(x, y, w, h));
    button.setOutlineColor(sf::Color::Red);
    button.setOutlineThickness(-5);
  }
  else
  {
    button.setFillColor(sf::Color::Blue);
    button.setOutlineColor(sf::Color::Green);
    button.setOutlineThickness(5);
  }

  o->getWin().draw(button);
  o->getWin().draw(label);
  propagateChildren();
}

bool        CDrawButton::contains(int _x, int _y) {
  data_map    coord = e->getAttr<GEOMETRY>()->getData();

  if ((_x >= coord["x"]) && (_x <= coord["x"] + coord["w"]) && (_y >= coord["y"]) && (_y <= coord["y"] + coord["h"]))
    return true;
  return false;
}