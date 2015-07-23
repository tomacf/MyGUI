#ifndef CCHILDREN_HH
#define CCHILDREN_HH

#include <map>
#include "Component.hh"
#include "Entity.hh"
#include "CIdentifier.hh"

class CChildren;
typedef CChildren* CHILDREN;

typedef std::map<int, Entity *> children_map;

class CChildren : public Component
{
  children_map children;

public:
  CChildren();
  ~CChildren();

  const children_map &getAll();
  CChildren *push(Entity *b);
  CChildren *remove(int);
};

#endif