#include "CColor.hh"

CColor::CColor() {

}

CColor::~CColor() {

}

CColor    *CColor::setRGBA(int _r, int _g, int _b, int _a) {
  r = _r;
  g = _g;
  b = _b;
  a = _a;
  return this;
}

CColor    *CColor::setR(int _r) {
  r = _r;
  return this;
}

CColor    *CColor::setG(int _g) {
  g = _g;
  return this;
}

CColor    *CColor::setB(int _b) {
  b = _b;
  return this;
}

CColor    *CColor::setA(int _a) {
  a = _a;
  return this;
}

void      CColor::getRGBA(int *_r, int *_g, int *_b, int *_a) {
  *_r = r;
  *_g = g;
  *_b = b;
  *_a = a;
}

int       CColor::getR() {
  return (r);
}

int       CColor::getG() {
  return (g);
}

int       CColor::getB() {
  return (b);
}

int       CColor::getA() {
  return (a);
}