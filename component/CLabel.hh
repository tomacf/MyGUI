#ifndef CLABEL_HH_
#define CLABEL_HH_

/*!
 * \file CLabel.hh
 * \brief Component Label qui contient les informations texte.
 * \author candio_m,cristi_a
 * \version 0.34
 *
 *  Component qui contient les informations texte et le fontsize associés à une entité.
 *
 */

#include <string>
#include "Component.hh"

class CLabel;
typedef CLabel* LABEL;

/*! \class CLabel
 *  \brief Classe héritant de Component contient le label en string et le fontsize en int.
 */
class CLabel : public Component
{
  std::string label;
  int         fontSize;

public:
  CLabel();
  ~CLabel();

/*!
 *  \brief Assigne un label à l'entité
 *  \return CLabel *this
 */
  CLabel            *setLabel(const std::string &);
/*!
 *  \brief Récupère le label de l'entité
 *  \return const std::string &label
 */
  const std::string &getLabel();
/*!
 *  \brief Assigne une taille de police au label
 *  \return CLabel *this
 */
  CLabel            *setFontSize(int);
/*!
 *  \brief Récupère la tailel de police
 *  \return int
 */
  int                getFontSize();
};

#endif