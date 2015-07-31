#ifndef CDRAWIMAGE_HH_
#define CDRAWIMAGE_HH_

/*!
 * \file CDrawImage.hh
 * \brief Component Draw une image
 * \author candio_m,cristi_a
 * \version 2.4
 *
 *  Component qui affiche une image.
 *
 */
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "CDraw.hh"
#include "CColor.hh"
#include "CGeometry.hh"
#include "CChildren.hh"
#include "CLabel.hh"

/*! \class CDrawImage
 *  \brief Classe héritant de CDraw et qui affiche une image.
 *
 * La texture est load en cas de changement et le sprite aussi.
 *
 */
class CDrawImage : public CDraw
{
  sf::Texture texture;
  sf::Sprite  sprite;

public:
  CDrawImage(SRender *_o, Entity *_e);
  ~CDrawImage();

  /*!
   *  \brief Affiche l'image
   */
  void        draw();
  /*!
   *  \brief Check si les coordonées sont contenues dans l'image
   *  \return bool
   */
  bool        contains(int, int);
};

#endif