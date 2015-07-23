#include "Factory.hh"

Factory::Factory(SRender *_o) {
  o = _o;
  id = 0;
}

Factory::~Factory() {

}

Entity *Factory::buildButton() {
  Entity *button = new Entity();

  button->setAttr<CIdentifier>();
  button->getAttr<ID>()->setId(++id);
  button->setAttr<CLabel>();
  button->setAttr<CGeometry>();
  button->setAttr<CColor>();
  button->setAttr<CChildren>();
  button->setAttr<EVENT>(new CEvent(o, button));
  button->setAttr<DRAW>(new CDrawRectangle(o, button));

  //setter le fonctionnement du draw ICI

  return button;
}

Entity *Factory::buildPage() {
  Entity *page = new Entity();

  page->setAttr<CIdentifier>();
  page->getAttr<ID>()->setId(++id);
  page->setAttr<CChildren>();

  page->setAttr<CGeometry>();
  page->setAttr<CColor>();
  page->getAttr<GEOMETRY>()->setX(0)->setY(0)->setW(o->getWidth())->setH(o->getHeight());;

  page->setAttr<EVENT>(new CEvent(o, page));
  page->setAttr<DRAW>(new CDrawGhost(page));

  return page;
}