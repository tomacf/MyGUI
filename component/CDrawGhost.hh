#ifndef CDRAWRGHOST_HH_
#define CDRAWRGHOST_HH_

#include "CDraw.hh"

class CDrawGhost : public CDraw
{
public:
  CDrawGhost(Entity *_e);
  ~CDrawGhost();

  void        draw();
};

#endif