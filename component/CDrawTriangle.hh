#ifndef CDRAWTRIANGLE_HH_
#define CDRAWTRIANGLE_HH_

/*!
 * \file CDrawTriangle.hh
 * \brief Component Draw qui affiche un triangle.
 * \author candio_m,cristi_a
 * \version 7.8
 *
 *  Component qui affiche un triangle à partir de 3 points donnés.
 *
 */

#include <SFML/Graphics/CircleShape.hpp>
#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CChildren.hh"

/*! \class CDrawTriangle
 *  \brief Classe héritant de CDraw et qui affiche un triangle.
 */
class CDrawTriangle : public CDraw
{
  sf::CircleShape triangle;

  /*!
  *  \brief Fonction utilitaire, appellée par le contains.
  *  \return float
  */
  float       sign(sf::Vector2f &, sf::Vector2f &, sf::Vector2f &);
public:
  CDrawTriangle(SRender *_o, Entity *_e);
  ~CDrawTriangle();

  /*!
  *  \brief Affiche le triangle.
  */
  void        draw();
  /*!
  *  \brief Check si les coordonées sont contenues dans le triangle
  *  \return bool
  */
  bool        contains(int, int);
};

#endif