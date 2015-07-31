#ifndef CDRAWBUTTON_HH_
#define CDRAWBUTTON_HH_

/*!
 * \file CDrawButton.hh
 * \brief Component Draw spécialisé du boutton
 * \author cristi_a,candio_m
 * \version 12.1
 *
 *  Component qui affiche un boutton, avec un label et un cadre.
 *
 */

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CLabel.hh"
#include "CChildren.hh"

/*! \class CDrawButton
 * \brief Classe héritant de CDraw et qui contient le cadre et le label
 *
 */
class CDrawButton : public CDraw
{
  bool      ready;

  sf::RectangleShape  button;
  sf::Text            label;


public:
  CDrawButton(SRender *_o, Entity *_e);
  ~CDrawButton();

/*!
 *  \brief Fonction qui va chercher la police du label
 */
  void        init();
/*!
 *  \brief Affichage du boutton
 */
  void        draw();
/*!
 *  \brief Check si les coordonées sont contenues dans le boutton
 *  \return bool
 */
  bool        contains(int, int);
};

#endif