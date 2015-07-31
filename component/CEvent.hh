#ifndef CEVENT_HH_
#define CEVENT_HH_

/*!
 * \file CEvent.hh
 * \brief Component Event qui réagit aux evenements.
 * \author candio_m,cristi_a
 * \version 7.8
 *
 *  Component qui stocke les fonctions qui doivent être appelée
 *  en fonction d'un event Type, et qui se charge de les appeler.
 *
 */

#include <map>
#include "Entity.hh"
#include "Component.hh"
#include "SRender.hh"
#include "CChildren.hh"
#include "CDraw.hh"

class CEvent;
typedef CEvent* EVENT;

/*! \class CEvent
 *  \brief Classe héritant de Component qui gère les Event.
 *
 * La classe possède un pointeur sur le SRender et sur l'entity ainsi qu'un tableau
 * de pointeur sur fonction indexé par EventType.
 *
 * Les fonctions doivent respecter ce prototype void fct(Entity *, sf::Event &)
 * Elles recevront en premier paramètre l'entitée et en deuxième paramètre l'event SFML
 *
 */
class CEvent : public Component
{
  SRender     *o;
  Entity      *e;

  std::map<sf::Event::EventType, void (*)(Entity *, sf::Event &)> map_function;

public:
  CEvent(SRender *, Entity *);
  ~CEvent();

  /*!
   *  \brief Spécifie une réaction par rapport à un évenement.
   *  \return CEvent *
   */
  CEvent *setEvent(sf::Event::EventType, void (*)(Entity *, sf::Event &));
  /*!
   *  \brief Reçois un évenement et appelle la fonction correspondante.   *  \return CEvent *
   */
  CEvent *receiveEvent(sf::Event &);
  /*!
   *  \brief Reçois un évenement et vérifie si il devient le focus, si il doit réagir
   *  \return CEvent *
   */
  CEvent *checkEvent(sf::Event &);
    /*!
   *  \brief Propage l'évenement aux enfants.
   */
  void    propagateChildren(sf::Event &);

};

#endif