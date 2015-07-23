#ifndef CDRAW_HH_
#define CDRAW_HH_

#include "Entity.hh"
#include "Component.hh"
#include "SRender.hh"

#include "CChildren.hh"


class CDraw;
typedef CDraw * DRAW;

class CDraw : public Component
{
protected:
  SRender     *o;
  Entity      *e;

public:
  CDraw(SRender *, Entity *);
  ~CDraw();

  virtual void      draw() = 0;
  CDraw *setRender(SRender *);
  SRender *getRender();
};

#endif