#ifndef CIDENTIFIER_HH_
#define CIDENTIFIER_HH_

/*!
 * \file CIdentifier.hh
 * \brief Component ID qui identifie de manière unique une entité.
 * \author candio_m,cristi_a
 * \version 7.8
 *
 */

#include "Component.hh"

class CIdentifier;
typedef CIdentifier* ID;

/*! \class CIdentifier
 *  \brief Classe héritant de Component stockant l'id.
 */
class CIdentifier : public Component
{
  int id;

public:
  CIdentifier();
  ~CIdentifier();

/*!
 *  \brief Assigne une ID
 *  \return CIdentifier *this
 */
  CIdentifier   *setId(int);
/*!
 *  \brief Récupère une ID
 *  \return int id
 */
  int           getId();
};

#endif