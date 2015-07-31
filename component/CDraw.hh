#ifndef CDRAW_HH_
#define CDRAW_HH_

/*!
 * \file CDraw.hh
 * \brief Component draw général
 * \author candio_m,cristi_a
 * \version 23
 *
 *  Component qui sert de parent à tout les component Draw spécialisé
 *
 */

#include "Entity.hh"
#include "Component.hh"
#include "SRender.hh"
#include "CChildren.hh"


class CDraw;
typedef CDraw * DRAW;

/*! \class CDraw
 * \brief Classe héritant de Component et composé du nécéssaire pour afficher.
 *
 *  CDraw stocke un pointeur sur le SRender et un pointeur sur l'entité actuelle.
 *  Le children_map contient les enfants de l'entité, il est mis à jour en cas de changement.
 *
 */
class CDraw : public Component
{
protected:
  SRender             *o;
  Entity              *e;
  children_map        children;

public:
  CDraw(SRender *, Entity *);
  ~CDraw();

  /*!
   *  \brief Fonction draw qui affiche imposée aux enfants
   *
   */
  virtual void      draw() = 0;
  /*!
   *  \brief Fonction contains qui vérifie si l'entité est cliquée
   *
   */
  virtual bool      contains(int, int) = 0;
  /*!
   *  \brief En cas de changement de SRender
   *  \return CDraw *this
   */
  CDraw             *setRender(SRender *);
  /*!
   *  \brief Getter du render system
   *  \return SRender *o
   */
  SRender           *getRender();
  /*!
   *  \brief Appel les draws des enfant
   */
  void              propagateChildren();
};

#endif