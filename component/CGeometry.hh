#ifndef CGEOMETRY_HH_
#define CGEOMETRY_HH_

#include "Component.hh"

class CGeometry;
typedef CGeometry* GEOMETRY;

// Garder un stockage sous forme de SDL::Rect

class CGeometry : public Component
{
  int       x;
  int       y;

  int       w;
  int       h;

public:
  CGeometry();
  ~CGeometry();

  void  getXYWH(int *, int *, int *, int *);
  int   getX();
  int   getY();
  int   getW();
  int   getH();

  CGeometry  *setXYWH(int, int, int, int);
  CGeometry  *setX(int);
  CGeometry  *setY(int);
  CGeometry  *setW(int);
  CGeometry  *setH(int);

  bool        checkPos(int, int);
};


#endif