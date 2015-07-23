#ifndef CLABEL_HH_
#define CLABEL_HH_

#include <string>
#include "Component.hh"

class CLabel;
typedef CLabel* LABEL;

class CLabel : public Component
{
  std::string label;

public:
  CLabel();
  ~CLabel();

  CLabel            *setLabel(const std::string &);
  const std::string &getLabel();
};

#endif