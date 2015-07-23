#ifndef FACTORY
#define FACTORY

#include "Entity.hh"


#include "CIdentifier.hh"
#include "CLabel.hh"
#include "CGeometry.hh"
#include "CColor.hh"
#include "CChildren.hh"
#include "CDrawRectangle.hh"
#include "CDrawGhost.hh"
#include "CEvent.hh"

class Factory
{
  int       id;
  SRender   *o;

public:
  Factory(SRender *);
  ~Factory();

  Entity *buildButton();
  Entity *buildPage();
};

#endif