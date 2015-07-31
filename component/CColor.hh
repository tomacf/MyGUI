#ifndef CCOLOR_HH
#define CCOLOR_HH

/*!
 * \file CColor.hh
 * \brief Component Color
 * \author candio_m,cristi_a
 * \version 23
 *
 *  Component qui stocke les couleurs associées à une entité
 *
 */

#include "Component.hh"

class CColor;
typedef CColor* COLOR;

/*! \class CColor
 * \brief Classe héritant de Component et composé des variables RGBA
 *
 */
class CColor : public Component
{
  int       r;
  int       g;
  int       b;
  int       a;

public:
  CColor();
  ~CColor();

  /*!
   *  \brief Setter des 4 variables
   *
   *  \return CColor *this
   */
  CColor    *setRGBA(int, int , int, int);
  /*!
   *  \brief Setter du canal RED
   *
   *  \return CColor *this
   */
  CColor    *setR(int);
  /*!
   *  \brief Setter du canal GREEN
   *
   *  \return CColor *this
   */
  CColor    *setG(int);
  /*!
   *  \brief Setter du canal BLUE
   *
   *  \return CColor *this
   */
  CColor    *setB(int);
  /*!
   *  \brief Setter du canal ALPHA
   *
   *  \return CColor *this
   */
  CColor    *setA(int);
  /*!
   *  \brief Récupérer l'ensemble des couleurs
   *
   *  Methode qui permet de récupérer les 4 variables en passant des pointeurs sur Int
   *
   */
  void      getRGBA(int *, int *, int *, int *);
  /*!
   *  \brief Récupérer la valeur du canal RED
   *
   *  \return int red
   */
  int       getR();
  /*!
   *  \brief Récupérer la valeur du canal GREEN
   *
   *  \return int green
   */
  int       getG();
  /*!
   *  \brief Récupérer la valeur du canal BLUE
   *
   *  \return int blue
   */
  int       getB();
  /*!
   *  \brief Récupérer la valeur du canal ALPHA
   *
   *  \return int alpha
   */
  int       getA();
};

#endif