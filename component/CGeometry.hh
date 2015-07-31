#ifndef CGEOMETRY_HH_
#define CGEOMETRY_HH_

/*!
 * \file CGeometry.hh
 * \brief Component Geometry qui stocke toutes les données nécéssaire pour le draw.
 * \author candio_m,cristi_a
 * \version 4.1
 *
 */
#include "Component.hh"
#include <map>
#include <string>

class CGeometry;
typedef CGeometry* GEOMETRY;

typedef std::map<std::string, int> data_map;

/*! \class CGeometry
 *  \brief Classe héritant de Component.
 */
class CGeometry : public Component
{
  data_map data;

public:
  CGeometry();
  ~CGeometry();

 /*!
 *  \brief Récupère une donnée à partir de son nom en string
 *  \return int value
 */
  int           get(const std::string &);
 /*!
 *  \brief Récupère l'ensemble des données
 *  \return data_map data
 */
  data_map      &getData();
 /*!
 *  \brief Assigne la valeur à la clé correspondante
 *  \return CGeometry *this
 */
  CGeometry     *set(const std::string &, int);
 /*!
 *  \brief Assigne toute une map
 *  \return CGeometry *this
 */
  CGeometry     *setData(const data_map &);
 /*!
 *  \brief Ajoute à la valeur de la clé.
 *  \return CGeometry *this
 */
  CGeometry     *add(const std::string &, int);
   /*!
 *  \brief Soustrait à la valeur de la clé.
 *  \return CGeometry *this
 */
  CGeometry     *substract(const std::string &, int);
   /*!
 *  \brief Multiplie la valeur de la clé.
 *  \return CGeometry *this
 */
  CGeometry     *multiply(const std::string &, int);
   /*!
 *  \brief Divise la valeur de la clé.
 *  \return CGeometry *this
 */
  CGeometry     *divides(const std::string &, int);
};


#endif