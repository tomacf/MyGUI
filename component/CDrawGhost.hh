#ifndef CDRAWRGHOST_HH_
#define CDRAWRGHOST_HH_

/*!
 * \file CDrawGhost.hh
 * \brief Component Draw qui n'affiche pas
 * \author candio_m,cristi_a
 * \version 7.8
 *
 *  Component qui n'affiche pas l'entité mais ses enfants.
 *
 */

#include "CDraw.hh"

/*! \class CDrawGhost
 *  \brief Classe héritant de CDraw et qui affiche les enfants.
 */
class CDrawGhost : public CDraw
{
public:
  CDrawGhost(Entity *_e);
  ~CDrawGhost();

/*!
 *  \brief Check si les coordonées sont contenues dans le contenaire
 *  \return bool
 */
  bool contains(int, int);
/*!
 *  \brief N'affiche rien
 */
  void        draw();
};

#endif