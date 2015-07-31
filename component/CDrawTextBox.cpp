#include "CDrawTextBox.hh"

CDrawTextBox::CDrawTextBox(SRender *_o, Entity *_e) : CDraw(_o, _e)
{
  ready = false;
}

void        CDrawTextBox::init(){
  texte.setFont(o->getFont());
  ready = true;
}

void        CDrawTextBox::draw() {
  data_map    geo = e->getAttr<GEOMETRY>()->getData();

  if (!ready)
    init();
  if (e->getAttr<GEOMETRY>()->hasChange()) {
    cadre.setPosition(geo["x"], geo["y"]);
    cadre.setSize(sf::Vector2f(geo["w"], geo["h"]));
    texte.setPosition(geo["x"] + 2, geo["y"] + 2);
  }
  wordwrap();
  if (e->getAttr<LABEL>()->hasChange()) {
    texte.setString(e->getAttr<LABEL>()->getLabel());
    texte.setCharacterSize(e->getAttr<LABEL>()->getFontSize());
  }
  if (e->getAttr<COLOR>()->hasChange()) {
    int x, y, w, h;
    e->getAttr<COLOR>()->getRGBA(&x, &y, &w, &h);
    cadre.setFillColor(sf::Color(x, y, w, h));
    cadre.setOutlineColor(sf::Color::Blue);
    cadre.setOutlineThickness(-2);
  }
  o->getWin().draw(cadre);
  o->getWin().draw(texte);
  propagateChildren();
}

bool        CDrawTextBox::contains(int _x, int _y) {
  data_map    geo = e->getAttr<GEOMETRY>()->getData();

  if ((_x >= geo["x"]) && (_x <= geo["x"] + geo["w"]) && (_y >= geo["y"]) && (_y <= geo["y"] + geo["h"]))
    return true;
  return false;
}

void       CDrawTextBox::wordwrap() {
  std::string inputed;
  char    c;

  if (!e->getAttr<LABEL>()->hasChange())
    return;

  inputed = e->getAttr<LABEL>()->getLabel();
  texte.setString(inputed);
  if ((texte.getGlobalBounds().width > cadre.getGlobalBounds().width - 10) && (inputed.length() > 1)) {
    c = inputed[inputed.length()  - 1];
    inputed.pop_back();
    if (texte.getGlobalBounds().height + 20 < cadre.getGlobalBounds().height) {
      inputed.push_back('\n');
      inputed.push_back(c);
    }
    e->getAttr<LABEL>()->setLabel(inputed);
  }
}