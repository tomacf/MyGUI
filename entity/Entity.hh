#ifndef ENTITY_HH_
#define ENTITY_HH_

#include "Component.hh"
#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <map>
#include <string>

typedef std::map<std::type_index, Component*> component_map;

class Entity
{
  component_map vm;

public:
  Entity() {

  }

  ~Entity() {
    for (component_map::iterator i = vm.begin(); i != vm.end(); ++i) {
      delete (*i).second;
    }
    vm.clear();
  }

  template <typename T>Entity      *setAttr() {
    if (vm.find(typeid(T*)) != vm.end())
      delete vm[typeid(T*)];
    vm[typeid(T*)] = new T();
    return this;
  }

  template <typename T>Entity      *setAttr(Component *c) {
      if (vm.find(typeid(T)) != vm.end())
        delete vm[typeid(T)];
    vm[typeid(T)] = c;
    return this;
  }

  template <typename T>T          getAttr() {
    if (vm.find(typeid(T)) == vm.end())
      return NULL;

    return static_cast<T>(vm[typeid(T)]);
  }
};

#endif