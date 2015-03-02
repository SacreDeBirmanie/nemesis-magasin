/**
 * @file mappe.hpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Définition d'un patron de classe Mappe<K,V> conforme à la spécification de AListe
**/

#ifndef __MAPPE_HPP__
#define __MAPPE_HPP__

#include <map>
#include <vector>

/**
 * @class Mappe<K,V> mappe.hpp
 * 
 * @brief Patron de classe implémentant des mappes K-->V
 * 
 * Implémentée comme une adaptation de la classe std::map de la STL
 * ==> nécessite que l'opérateur < soit défini pour le type K des clefs
 */
template <typename K, typename V>
class Mappe
{
   private:
      // stockage des couple dans un std::map<K,V>
      std::map<K, V> contenu;

   public:
      /**
       * @brief Constructeur, crée une Mappe vide
       * 
       * @b Complexité Θ(1)
       */
      Mappe();

      /**
       * @brief Destructeur, libère la mémoire
       * 
       * @b Complexité Θ(nbc), nbc = nombre de couples stockés
       */
      ~Mappe();

      /**
       * @brief Ajout/Modification d'un couple
       * @param clf la clé du couple à ajouter/modifier
       * @param valr la valeur a lui associer
       * 
       * @b Complexité O(log(nbc)), nbc = nombre de couples stockés
       */
      void associer(K clf, V valr);

      /**
       * @brief Test de l'absence de couple
       * @return vrai ssi aucun couple n'est stocké
       * 
       * @b Complexité Θ(1)
       */
      bool estVide() const;

      /**
       * @brief Accès à la valeur associée à une clef
       * @param clf la clef recherchée
       * @return la valeur associée
       * @pre il existe un couple contenant clf dans la Mappe
       * 
       * @b Complexité O(log(nbc)), nbc = nombre de couples stockés
       */
      V valeurAssociee(K clf) const;

      /**
       * @brief Suppression d'un couple
       * @param clf la clef du couple à supprimer
       * @attention Ne fait rien si aucun couple n'existe pour cette clef dans la Mappe
       * 
       * @b Complexité O(log(nbc)), nbc = nombre de couples stockés
       */
      void dissocier(K clf);

      /**
       * @brief Test de la présence d'un couple
       * @param clf la clef du couple à rechercher
       * @return vrai ssi il existe un couple de clef clf dans la Mappe
       * 
       * @b Complexité O(log(nbc)), nbc = nombre de couples stockés
       */
      bool estClef(K clf) const;

      /**
       * @brief Accès à l'ensemble des clefs
       * @return un tableau contenant toutes les clefs utilisées dans la Mappe
       * 
       * @b Complexité Θ(nbc), nbc = nombre de couples stockés
       */
      std::vector<K> trousseau() const;
}; // Mappe

#include "mappe.tpp"

#endif // __MAPPE_HPP__
