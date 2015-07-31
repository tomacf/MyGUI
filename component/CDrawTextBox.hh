#ifndef CDRAWTEXTBOX_HH_
#define CDRAWTEXTBOX_HH_

/*!
 * \file CDrawTextBox.hh
 * \brief Component Draw qui affiche un textarea.
 * \author candio_m,cristi_a
 * \version 7.8
 *
 *  Component qui affiche un rectangle qui sert de cadre et un texte.
 *
 */

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CLabel.hh"
#include "CChildren.hh"

/*! \class CDrawTextBox
 *  \brief Classe héritant de CDraw et qui affiche un cadre et un texte.
 */
class CDrawTextBox : public CDraw
{
  bool      ready;

  sf::RectangleShape  cadre;
  sf::Text            texte;


public:
  CDrawTextBox(SRender *_o, Entity *_e);
  ~CDrawTextBox();

  void        init();
  /*!
 *  \brief Affiche le champ texte
 */
  void        draw();
  /*!
  *  \brief Reviens à la ligne si le texte sort du cadre
  */
  void        wordwrap();
  /*!
  *  \brief Check si les coordonées sont contenues dans le contenaire
  */
  bool        contains(int, int);
};

#endif