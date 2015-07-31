#ifndef COMPONENT_HH_
#define COMPONENT_HH_

/*!
 * \file Component.hh
 * \brief Component, classe parent de tous les component.
 * \author candio_m,cristi_a
 * \version 3.8
 *
 */

#include <SDL2/SDL.h>

/*! \class Component
 * \brief Parent de tous les components.
 *
 * En plus de permettre de stocker tous les components au meme endroit
 * Component contient aussi un boolean qui permet de savoir si un
 * changement a été effectué.
 *
 */
class Component
{
protected:
  bool    change;

public:
  Component();
  ~Component();

 /*!
  *  \brief Renvoie la value de change
  *
  * Si un changement a été effectué change est mis à true.
  * la fonction renverra ainsi true si nécéssaire et passera le change à false
  * le changement ayant bien été notifié.
  *
  * \return boolean change
  *
  */
  bool  hasChange();
};

#endif