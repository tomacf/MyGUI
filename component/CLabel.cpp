#include "CLabel.hh"

CLabel::CLabel() : Component() {
}

CLabel::~CLabel() {
}


CLabel            *CLabel::setLabel(const std::string & _label) {
  label = _label;
  change = true;
  return this;
}

const std::string &CLabel::getLabel() {
  return label;
}

CLabel            *CLabel::setFontSize(int _fontSize) {
  fontSize = _fontSize;
  change = true;
  return this;
}

int               CLabel::getFontSize() {
  return fontSize;
}