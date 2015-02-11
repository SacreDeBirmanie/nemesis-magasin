/**
 * @file produit.hpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Définition d'une classe Produit
**/

#ifndef __PRODUIT_HPP__
#define __PRODUIT_HPP__

#include <string>

/**
 * @class Produit produit.hpp
 * 
 * @brief Classe implémentant un produit étiqueté pour commercialisation
 * 
 * Un produit a un nom, un poids et une étiquette (code-barre) ; 
 * le code-barre est un identifiant unique pour tout produit
 */
class Produit
{
   private :
      // attributs
      std::string nom_; // nom du produit : une chaîne
      double poids_; // poids du produit en kg : un réel
      unsigned int codebarre_; // étiquette du produit : un entier

   public :
      // méthodes
      /**
       * @brief Constructeur, crée un produit
       * @param n Le nom du produit
       * @param p Son poids
       * @param e Son étiquette
       */
      Produit(std::string n, double p, unsigned int e);

      /**
       * @brief Accès au nom du produit
       * @return le nom du produit
       */
      std::string nom() const;

      /**
       * @brief Accès au poids du produit
       * @return le poids du produit
       */
      double poids() const;

      /**
       * @brief Accès à l'étiquette du produit
       * @return le code-barre du produit
       */
      unsigned int codebarre() const;
      
      /**
       * @brief Affichage des données du produit sur la sortie standard
       */
      void afficher() const;
};

#endif // __PRODUIT_HPP__
