/**
 * @file htable.hpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Définition du type Htable générique par type des clefs et des valeurs
**/
#ifndef HTABLE_H
#define HTABLE_H

#include "aliste.hpp"
#include "fonctionsDeHashage.hpp"
#include <vector>
#include <set>
//taille fixe de la table de hashage
#define TAILLE 50

/**
 * @class Htable<K,V> htable.hpp
 * 
 * @brief Patron de classe implémentant des tables de hashages K-->V
 * 
 */
template <typename K,typename V>
class Htable{
	private:
		//objet permettant de retourner un hash code en fonction d'un type de clef
		fonctionsDeHashage * hacher;
		// cet attribut permet de connaitre les indices du tableau contenant une Aliste non vide (permettant une recherche plus rapide des clefs pour trousseau)
		std::set<K> indices;
		Aliste<K,V> list[TAILLE];

	public :
		/**
		* @brief Constructeur, créé une Htable vide
		*
		* @b Complexité Θ(1)
		*/
		Htable();
		
		/**
		* @brief Desctructeur, libère la mémoire
		*
		* @b Complexité Θ(nbc), nbc = nombre de couples sctockés 
		*/
		~Htable();
		
		/**
		* @brief obtention d'un entier pour l'insertion dans la Htable
		* @param clef la clé du couple à "hasher"
		* @return un entier correspond au hash de la clef
		* @pre la clf est d'un des types suivants : entier, flottant, caractère, chaine de caractère
		* 
		* @b Complexité O(1), nbc = nombre de couples stockés
		*/
		int hash(K clf) const;
		
		/**
		* @brief Ajout/Modification d'un couple
		* @param clef la clé du couple à ajouter/modifier
		* @param valr la valeur à lui associer
		* 
		* @b Complexité O(log nbc), nbc = nombre de couples stockés
		*/
		void associer(K clf,V valr); 
		
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
		* @pre il existe un couple contenant clf dans la hTable
		* 
		* @b Complexité O(log nbc), nbc = nombre de couples stockés
		*/
		V valeurAssociee(K clf) const;
		
		/**
		* @brief Suppression d'un couple
		* @param clf la clef du couple à supprimer
		* @attention Ne fait rien si aucun couple n'existe pour cette clef dans la Htable
		* 
		* @b Complexité O(log nbc), nbc = nombre de couples stockés
		*/
		void dissocier(K clf);
		
		/**
		* @brief Test de la présence d'un couple
		* @param clf la clef du couple à rechercher
		* @return vrai ssi il existe un couple de clef clf dans la Aliste
		* 
		* @b Complexité O(log nbc), nbc = nombre de couples stockés
		*/
		bool estClef(K clf) const;
		
		/**
		* @brief Accès à l'ensemble des clefs
		* @return un tableau contenant toutes les clefs utilisées dans la Htable
		* 
		* @b Complexité O(nbc), nbc = nombre de couples stockés
		*/
		std::vector<K> trousseau() const;

};



//---------------------------------------
#include "htable.tpp"
#endif
