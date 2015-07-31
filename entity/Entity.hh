#ifndef ENTITY_HH_
#define ENTITY_HH_

/*!
 * \file Entity.hh
 * \brief Classe container de component
 * \author candio_m,cristi_a
 * \version 1.8
 *
 */

#include "Component.hh"
#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <map>
#include <string>

typedef std::map<std::type_index, Component*> component_map;

/*! \class Entity
 *  \brief Classe possédant une map de component et gérant les accès.
 *
 *  La component_map est faite de Component* indexé par l'Id de leur classe
 *
 */
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

  /*!
  *  \brief Crée un component
  *
  * Ajoute le component passé en template à la map avec comme clé
  * L'id de la classe du component
  * Effectue un cast du component créé et le return
  * \return T *component
  */
  template <typename T>T            *setAttr() {
    if (vm.find(typeid(T*)) != vm.end())
      delete vm[typeid(T*)];
    vm[typeid(T*)] = new T();
    return static_cast<T*>(vm[typeid(T*)]);
  }

  /*!
  *  \brief Assigne un component
  *
  * Ajoute le component passé en paramètre à la map avec comme clé l'id de la classe
  * Effectue un cast du component créé dans la classe templaté et le return
  * \return T component
  */
  template <typename T>T            setAttr(Component *c) {
      if (vm.find(typeid(T)) != vm.end())
        delete vm[typeid(T)];
    vm[typeid(T)] = c;
    return static_cast<T>(vm[typeid(T)]);
  }

 /*!
  *  \brief Récupère un component
  *
  * Renvoie le component de la classe passé en template en se servant de son id de classe.
  * Effectue un cast pour passer de Component * à T.
  *  \return T component
  */
  template <typename T>T          getAttr() {
    if (vm.find(typeid(T)) == vm.end())
      return NULL;

    return static_cast<T>(vm[typeid(T)]);
  }
};

#endif