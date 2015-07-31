#ifndef FACTORY
#define FACTORY

/*!
 * \file Factory.hh
 * \brief Usine à entité préfabriquée
 * \author cristi_a,candio_m
 * \version 5.12
 *
 */


#include "Entity.hh"

#include "CChildren.hh"
#include "CColor.hh"
#include "CDrawButton.hh"
#include "CDrawCircle.hh"
#include "CDrawGhost.hh"
#include "CDrawLabel.hh"
#include "CDrawLine.hh"
#include "CDrawRectangle.hh"
#include "CDrawImage.hh"
#include "CDrawTriangle.hh"
#include "CDrawTextBox.hh"
#include "CEvent.hh"
#include "CGeometry.hh"
#include "CIdentifier.hh"
#include "CLabel.hh"

/*! \class Factory
 *  \brief Classe qui assemble les components pour préparer les objets demandé.
 *
 *  La Factory build les différents types d'objets avec les component dont ils ont besoin.
 *
 */
class Factory
{
  int       id;
  SRender   *o;

public:
  Factory(SRender *);
  ~Factory();

  /*!
  *  \brief Construit un bouton
  *
  *  Le label du bouton est centré il est peut être setté par l'intermediaire
  *  du component CLabel.
  *  Les positions et dimensions du bouton sont spécifié avec les variables
  *  x, y, w, h du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildButton();
  /*!
  *  \brief Construit un Cercle
  *
  *  Les positions et dimensions du cercle sont spécifié avec les variables
  *  x, y, w du component CGeometry (avec 'w' le rayon du cercle).
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildCircle();
  /*!
  *  \brief Construit un label
  *
  *  Le label du bouton est aligné à gauche et setté dans CLabel.
  *  Les positions du label sont spécifié avec les variables
  *  x, y du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildLabel();
  /*!
  *  \brief Construit une ligne
  *
  *  Les positions des deux points sont spécifié avec les variables
  *  x1, y1 et x2, y2 du component CGeometry.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildLine();
  /*!
  *  \brief Construit un container
  *
  *  La zone de réaction du container est spécifié dans les variables
  *  x, y, w, h du component CGeometry.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildPage();
  /*!
  *  \brief Construit un point
  *
  *  Les positions du point sont spécifié avec les variables
  *  x, y du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildPoint();
  /*!
  *  \brief Construit un rectangle
  *
  *  Les positions et dimensions du rectangle sont spécifié avec les variables
  *  x, y, w, h du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildRectangle();
  /*!
  *  \brief Construit un triangle
  *
  *  Les positions et dimensions du triangle sont spécifié avec les variables
  *  x, y, w (pour la hauteur du triangle) du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildTriangle();
  /*!
  *  \brief Construit un champ texte
  *
  *  Le texte et le fontsize sont setté par l'intermediaire du component CLabel.
  *  Les positions et dimensions du champ texte sont spécifié avec les variables
  *  x, y, w, h du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildTextBox();
  /*!
  *  \brief Construit une image
  *
  *  Le nom de l'image à charger est setté par le component CLabel.
  *  Les positions de l'image sont données par les variables x, y du component CGeometry.
  *  Les couleurs sont setté dans le component CColor.
  *  Les evenements sont setté avec le component CEvent.
  *  Les childrens sont ajouté dans le component CChildren.
  *
  * \return Entity *;
  */
  Entity *buildImage();
};

#endif