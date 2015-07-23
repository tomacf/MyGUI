#include "CLabel.hh"

CLabel::CLabel() {
}

CLabel::~CLabel() {
}


CLabel            *CLabel::setLabel(const std::string & _label) {
  label = _label;
  return this;
}

const std::string &CLabel::getLabel() {
  return label;
}