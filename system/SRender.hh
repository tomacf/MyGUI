#ifndef SRENDER_HH
#define SRENDER_HH

/*!
 * \file SRender.hh
 * \brief Classe de gestion de la lib
 * \author candio_m,cristi_a
 * \version 5.12
 *
 */

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>


#include <string>
#include <iostream>
#include "Entity.hh"

/*! \class SRender
 * \brief Classe d'encapsulation de la lib.
 *
 * Initialise la librairie, récupère les évenements, et affiche les élements.
 *
 */
class SRender
{
  bool                  env_ready;
  sf::Font              font;
  sf::ContextSettings   settings;
  sf::RenderWindow      win;

  Entity                *focused;
  int                   w;
  int                   h;

public:
  SRender();
  ~SRender();

 /*!
  *  \brief Crée la fenêtre et charge les fonts
  *  \return boolean
  */
  bool start(const std::string &title = "Engine", int width = 800, int height = 600);

/*!
  *  \brief Met à jour l'évenement
  *  \return int > 0 si il y a eu un event
  */
  int       update(sf::Event &);

/*!
  *  \brief Vide la fenêtre
  */
  void  clear();
/*!
  *  \brief Affiche la fenêtre
  */
  void  display();
/*!
  *  \brief Récupère la fenêtre pour faire l'affichage de l'extérieur
  *  \return sf::RenderWindow &
  */
  sf::RenderWindow &getWin();
/*!
  *  \brief Récupère la police pour tout affichage texte
  *  \return sf::Font &
  */
  sf::Font         &getFont();
/*!
  *  \brief Récupère la largeur de la fenêtre
  *  \return int
  */
  int               getWidth();
/*!
  *  \brief Récupère la hauteur de la fenêtre
  *  \return int
  */
  int               getHeight();
/*!
 *  \brief Vérifie que la fenêtre est ouverte
 *  \return boolean
 */
  bool              isOpen();
/*!
 *  \brief Ferme la fenêtre
 */
  void              close();
/*!
 *  \brief Récupère l'entité qui a le focus ou assigne le focus a une entité
 *  \return Entity *
 */
  Entity            *focus(Entity * = NULL);
};


#endif