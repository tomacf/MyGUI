#include "CGeometry.hh"

CGeometry::CGeometry() : Component() {
}
CGeometry::~CGeometry(){
}

int  CGeometry::get(const std::string &key) {
  if (data.find(key) != data.end())
    return data[key];
  return 0;
}

data_map  &CGeometry::getData() {
  return data;
}

CGeometry*  CGeometry::set(const std::string &key, int value){
  data[key] = value;
  change = true;
  return this;
}

CGeometry*  CGeometry::setData(const data_map &settedMap){
  change = true;
  return this;
}


CGeometry*  CGeometry::add(const std::string &key, int value){
  if (data.find(key) != data.end())
    data[key] += value;
  change = true;
  return this;
}

CGeometry*  CGeometry::substract(const std::string &key, int value){
  if (data.find(key) != data.end())
    data[key] -= value;
  change = true;
  return this;
}

CGeometry*  CGeometry::multiply(const std::string &key, int value){
  if (data.find(key) != data.end())
    data[key] *= value;
  change = true;
  return this;
}

CGeometry*  CGeometry::divides(const std::string &key, int value){
  if (data.find(key) != data.end())
    data[key] /= value;
  change = true;
  return this;
}


// bool        CGeometry::checkPos(int _x, int _y) {
//   if ((_x >= x) && (_x <= x + w) && (_y >= y) && (_y <= y + h))
//     return true;
//   return false;
// }