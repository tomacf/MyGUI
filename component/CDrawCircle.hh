#ifndef CDRAWCIRCLE_HH_
#define CDRAWCIRCLE_HH_

/*!
 * \file CDrawCircle.hh
 * \brief Component Draw spécialisé du cercle
 * \author candio_m,cristi_a
 * \version 7.8
 *
 *  Component qui affiche un cercle.
 *
 */

#include <SFML/Graphics/CircleShape.hpp>
#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CChildren.hh"

/*! \class CDrawCircle
 * \brief Classe héritant de CDraw et qui contient le sf::CircleShape
 *
 */
class CDrawCircle : public CDraw
{
  sf::CircleShape circle;

public:
  CDrawCircle(SRender *_o, Entity *_e);
  ~CDrawCircle();

/*!
 *  \brief Affichage du cercle
 */
  void        draw();
/*!
 *  \brief Check si les coordonées sont contenues dans le cercle
 *  \return bool
 */
  bool        contains(int, int);
};

#endif