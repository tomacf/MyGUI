#ifndef CDRAWRECTANGLE_HH_
#define CDRAWRECTANGLE_HH_

/*!
 * \file CDrawRectangle.hh
 * \brief Component Draw qui affiche un rectangle.
 * \author candio_m,cristi_a
 * \version 0.8 Alpha
 *
 *  Component qui affiche un rectangle.
 *
 */

#include <SFML/Graphics/RectangleShape.hpp>

#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CChildren.hh"

/*! \class CDrawRectangle
 *  \brief Classe héritant de CDraw et qui affiche un rectangle plein.
 */
class CDrawRectangle : public CDraw
{
  sf::RectangleShape rectangle;

public:
  CDrawRectangle(SRender *_o, Entity *_e);
  ~CDrawRectangle();

/*!
 *  \brief Affiche un rectangle
 */
  void        draw();
/*!
 *  \brief Check si les coordonées sont contenues dans le rectangle
 *  \return bool
 */
  bool        contains(int, int);
};

#endif