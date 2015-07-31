#ifndef CCHILDREN_HH
#define CCHILDREN_HH

/*!
 * \file CChildren.hh
 * \brief Component Container
 * \author cristi_a,candio_m
 * \version 23
 *
 *  Component qui permet à n'importe qu'elle Entity d'être mère
 *
 */

#include <map>
#include "Component.hh"
#include "Entity.hh"
#include "CIdentifier.hh"

class CChildren;
typedef CChildren* CHILDREN;

typedef std::map<int, Entity *> children_map;

/*! \class CChildren
 * \brief Classe héritant de Component et fait d'une map d'entitée
 *
 */
class CChildren : public Component
{
  children_map children;

public:
  CChildren();
  ~CChildren();

  /*!
   *  \brief Récupérer l'ensemble des enfants
   *
   *  Methode qui permet de récupérer les enfants de l'entitée mère
   *
   *  \return children_map
   */
  const children_map &getAll();
  /*!
   *  \brief Ajout d'une entitée
   *
   *  Methode qui permet d'ajouter une entitée en tant qu'enfant
   *
   *  \param Entity * : l'entitée
   *  \return CChildren *: pour permettre des appels en batterie
   */
  CChildren *push(Entity *);
    /*!
   *  \brief Supression d'une entitée
   *
   *  Methode qui permet de supprimer une entitée des enfants
   *
   *  \param int id: L'id de l'entitée a supprimer
   *  \return this pour permettre des appels en batterie
   */
  CChildren *remove(int);
};

#endif