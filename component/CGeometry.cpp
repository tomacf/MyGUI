#include "CGeometry.hh"

CGeometry::CGeometry(){
}
CGeometry::~CGeometry(){
}

void  CGeometry::getXYWH(int *_x, int *_y, int *_w, int *_h) {
  *_x = x;
  *_y = y;
  *_w = w;
  *_h = h;
}

int   CGeometry::getX(){
  return (x);
}
int   CGeometry::getY(){
  return (y);
}
int   CGeometry::getW(){
  return (w);
}
int   CGeometry::getH(){
  return (h);
}

CGeometry*  CGeometry::setXYWH(int _x, int _y, int _w ,int _h){
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  return this;
}

CGeometry*  CGeometry::setX(int _x){
  x = _x;
  return this;
}

CGeometry*  CGeometry::setY(int _y){
  y = _y;
  return this;
}

CGeometry*  CGeometry::setW(int _w){
  w = _w;
  return this;
}

CGeometry*  CGeometry::setH(int _h){
  h = _h;
  return this;
}

bool        CGeometry::checkPos(int _x, int _y) {
  if ((_x >= x) && (_x <= x + w) && (_y >= y) && (_y <= y + h))
    return true;
  return false;
}