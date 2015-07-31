#ifndef CDRAWLINE_HH_
#define CDRAWLINE_HH_

/*!
 * \file CDrawLine.hh
 * \brief Component Draw qui affiche une ligne
 * \author candio_m,cristi_a
 * \version 0.8 Alpha
 *
 *  Component qui affiche une ligne
 *
 */

#include <SFML/Graphics/VertexArray.hpp>
#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CChildren.hh"

/*! \class CDrawLine
 *  \brief Classe héritant de CDraw et qui affiche une ligne.
 *  Les coordonées x1,y1 et x2,y2 sont utilisées.
 */
class CDrawLine : public CDraw
{
  sf::VertexArray lines;

public:
  CDrawLine(SRender *_o, Entity *_e);
  ~CDrawLine();
/*!
 *  \brief Affiche la ligne
 */
  void        draw();
/*!
 *  \brief Check si les coordonées sont contenues dans la ligne
 *  \return bool
 */
  bool        contains(int, int);
};

#endif