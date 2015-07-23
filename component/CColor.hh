#ifndef CCOLOR_HH
#define CCOLOR_HH

#include "Component.hh"

class CColor;
typedef CColor* COLOR;

class CColor : public Component
{
  int       r;
  int       g;
  int       b;
  int       a;

public:
  CColor();
  ~CColor();

  CColor    *setRGBA(int, int , int, int);
  CColor    *setR(int);
  CColor    *setG(int);
  CColor    *setB(int);
  CColor    *setA(int);

  void      getRGBA(int *, int *, int *, int *);
  int       getR();
  int       getG();
  int       getB();
  int       getA();
};

#endif