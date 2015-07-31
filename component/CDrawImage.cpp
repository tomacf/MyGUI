#include "CDrawImage.hh"

CDrawImage::CDrawImage(SRender *_o, Entity *_e) : CDraw(_o, _e)
{

}


void        CDrawImage::draw() {
  if (e->getAttr<LABEL>()->hasChange()) {
    texture.loadFromFile(e->getAttr<LABEL>()->getLabel());
    sprite.setTexture(texture);
  }
  if (e->getAttr<GEOMETRY>()->hasChange()) {
    data_map        coord = e->getAttr<GEOMETRY>()->getData();
    sprite.setPosition(coord["x"], coord["y"]);
  }
  o->getWin().draw(sprite);
  propagateChildren();
}

bool        CDrawImage::contains(int _x, int _y) {
  data_map    coord = e->getAttr<GEOMETRY>()->getData();

  if ((_x >= coord["x"]) && (_x <= coord["x"] + coord["w"]) && (_y >= coord["y"]) && (_y <= coord["y"] + coord["h"]))
    return true;
  return false;
}