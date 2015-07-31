#ifndef CDRAWLABEL_HH_
#define CDRAWLABEL_HH_

/*!
 * \file CDrawLabel.hh
 * \brief Component Draw qui affiche un label
 * \author cristi_a,candio_m
 * \version 3.9
 *
 *  Component qui n'affiche pas l'entité mais ses enfants.
 *
 */
#include <SFML/Graphics/Text.hpp>

#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CLabel.hh"
#include "CChildren.hh"

/*! \class CDrawLabel
 *  \brief Classe héritant de CDraw et qui affiche un simple texte.
 *
 */
class CDrawLabel : public CDraw
{
  bool      ready;
  sf::Text  text;

public:
  CDrawLabel(SRender *_o, Entity *_e);
  ~CDrawLabel();

  void        init();
/*!
 *  \brief Affiche label
 */
  void        draw();
/*!
 *  \brief Check si les coordonées sont contenues dans le rectangle du label
 *  \return bool
 */
  bool        contains(int, int);
};

#endif