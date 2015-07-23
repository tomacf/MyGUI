#include "CChildren.hh"

CChildren::CChildren() {

}

CChildren::~CChildren() {
for (children_map::iterator i = children.begin(); i != children.end(); ++i) {
      delete (*i).second;
    }
    children.clear();
}

const children_map &CChildren::getAll() {
  return children;
}

CChildren *CChildren::push(Entity *b) {
  children[b->getAttr<ID>()->getId()] = b;
  return this;
}

CChildren *CChildren::remove(int id) {
  delete children[id];
  return this;
}