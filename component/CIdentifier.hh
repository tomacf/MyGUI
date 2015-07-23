#ifndef CIDENTIFIER_HH_
#define CIDENTIFIER_HH_

#include "Component.hh"

class CIdentifier;
typedef CIdentifier* ID;

class CIdentifier : public Component
{
  int id;

public:
  CIdentifier();
  ~CIdentifier();

  CIdentifier   *setId(int);
  int           getId();
};

#endif