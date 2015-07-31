#include "Factory.hh"

Factory::Factory(SRender *_o) {
  o = _o;
  id = 0;
}

Factory::~Factory() {

}

Entity *Factory::buildPoint() {
  Entity *point = new Entity();

  point->setAttr<CIdentifier>()->setId(++id);
  point->setAttr<CLabel>();
  point->setAttr<CGeometry>()->set("x", 0)->set("y", 0)->set("w", 5);
  point->setAttr<CColor>()->setA(255);
  point->setAttr<CChildren>();
  point->setAttr<EVENT>(new CEvent(o, point));
  point->setAttr<DRAW>(new CDrawCircle(o, point));

  return point;
}

Entity *Factory::buildLine() {
  Entity *line = new Entity();

  line->setAttr<CIdentifier>()->setId(++id);
  line->setAttr<CLabel>();
  line->setAttr<CGeometry>()->set("x1", 0)->set("y1", 0)->set("x2", 0)->set("y2", 0);
  line->setAttr<CColor>()->setA(255);
  line->setAttr<CChildren>();
  line->setAttr<EVENT>(new CEvent(o, line));
  line->setAttr<DRAW>(new CDrawLine(o, line));

  return line;
}

Entity *Factory::buildRectangle() {
  Entity *rectangle = new Entity();

  rectangle->setAttr<CIdentifier>()->setId(++id);
  rectangle->setAttr<CLabel>();
  rectangle->setAttr<CGeometry>();
  rectangle->setAttr<CColor>()->setA(255);
  rectangle->setAttr<CChildren>();
  rectangle->setAttr<EVENT>(new CEvent(o, rectangle));
  rectangle->setAttr<DRAW>(new CDrawRectangle(o, rectangle));

  return rectangle;
}

Entity *Factory::buildTriangle() {
  Entity *triangle = new Entity();

  triangle->setAttr<CIdentifier>()->setId(++id);
  triangle->setAttr<CLabel>();
  triangle->setAttr<CGeometry>();
  triangle->setAttr<CColor>()->setA(255);
  triangle->setAttr<CChildren>();
  triangle->setAttr<EVENT>(new CEvent(o, triangle));
  triangle->setAttr<DRAW>(new CDrawTriangle(o, triangle));

  return triangle;
}

Entity *Factory::buildCircle() {
  Entity *circle = new Entity();

  circle->setAttr<CIdentifier>()->setId(++id);
  circle->setAttr<CLabel>();
  circle->setAttr<CGeometry>();
  circle->setAttr<CColor>()->setA(255);
  circle->setAttr<CChildren>();
  circle->setAttr<EVENT>(new CEvent(o, circle));
  circle->setAttr<DRAW>(new CDrawCircle(o, circle));

  return circle;
}

Entity *Factory::buildLabel() {
  Entity *label = new Entity();

  label->setAttr<CIdentifier>()->setId(++id);
  label->setAttr<CLabel>()->setLabel("Empty Label")->setFontSize(24);
  label->setAttr<CGeometry>();
  label->setAttr<CColor>()->setA(255);
  label->setAttr<CChildren>();
  label->setAttr<EVENT>(new CEvent(o, label));
  label->setAttr<DRAW>(new CDrawLabel(o, label));

  return label;
}

Entity *Factory::buildPage() {
  Entity *page = new Entity();

  page->setAttr<CIdentifier>()->setId(++id);
  page->setAttr<CChildren>();
  page->setAttr<CGeometry>()->set("x", 0)->set("y", 0)->set("w", o->getWidth())->set("h", o->getHeight());;
  page->setAttr<CColor>()->setA(255);
  page->setAttr<EVENT>(new CEvent(o, page));
  page->setAttr<DRAW>(new CDrawGhost(page));

  return page;
}

Entity *Factory::buildButton() {
  Entity *button = new Entity();

  button->setAttr<CIdentifier>()->setId(++id);
  button->setAttr<CLabel>()->setLabel("Empty Label")->setFontSize(24);
  button->setAttr<CGeometry>();
  button->setAttr<CColor>()->setA(255);
  button->setAttr<CChildren>();
  button->setAttr<EVENT>(new CEvent(o, button));
  button->setAttr<DRAW>(new CDrawButton(o, button));

  return button;
}

Entity *Factory::buildTextBox() {
  Entity *button = new Entity();

  button->setAttr<CIdentifier>()->setId(++id);
  button->setAttr<CLabel>()->setLabel("Empty Text")->setFontSize(24);
  button->setAttr<CGeometry>();
  button->setAttr<CColor>()->setA(255);
  button->setAttr<CChildren>();
  button->setAttr<EVENT>(new CEvent(o, button));
  button->setAttr<DRAW>(new CDrawTextBox(o, button));

  return button;
}

Entity *Factory::buildImage() {
  Entity *button = new Entity();

  button->setAttr<CIdentifier>()->setId(++id);
  button->setAttr<CLabel>()->setLabel("bg.png");
  button->setAttr<CGeometry>();
  button->setAttr<CColor>()->setA(255);
  button->setAttr<CChildren>();
  button->setAttr<EVENT>(new CEvent(o, button));
  button->setAttr<DRAW>(new CDrawImage(o, button));

  return button;
}