#ifndef CDRAWRECTANGLE_HH_
#define CDRAWRECTANGLE_HH_

#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CChildren.hh"

class CDrawRectangle : public CDraw
{
public:
  CDrawRectangle(SRender *_o, Entity *_e);
  ~CDrawRectangle();

  void        draw();
  void        propagateChildren();
};

#endif