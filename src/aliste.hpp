/**
 * @file aliste.hpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Définition du type AListe générique par type des clefs et des valeurs
**/

#ifndef ALIST_HPP
#define ALIST_HPP
#include <vector>

/**
 * @class Aliste<K,V> aliste.hpp
 * 
 * @brief Patron de classe implémentant des tables assiociatives K-->V
 * 
 */
template < typename K, typename V >
class Aliste
{
	private :
		//Enregistrement Maillon
		typedef
		struct _maillon {
			//Clé associé à la valeur
			K clef;
			//Valeur associée à la clé         
			V valr;
			//Pointeur vers le maillon suivant		
			struct _maillon * succ;     
		}
		Maillon;                    
	
		//Enregistrement Chainage
		typedef
		struct {
			//Pointeur vers le maillon de tete
			Maillon * tete;
			//Nombre d'élément dans le chainage     
			int nb_elt;         
		}
		Chainage;           
		
		// stockage des couple dans un chainage
		Chainage ch;

	public :
		/**
		* @brief Constructeur, créé un Aliste vide
		*
		* @b Complexité Θ(1)
		*/
		Aliste();

		/**
		* @brief Desctructeur, libère la mémoire
		*
		* @b Complexité Θ(nbc), n = nombre de couples sctockés 
		*/
		~Aliste(); 
	   
		/**
		* @brief Ajout/Modification d'un couple
		* @param clef la clé du couple à ajouter/modifier
		* @param valr la valeur à lui associer
		* 
		* @b Complexité O(nbc), nbc = nombre de couples stockés
		*/
		void associer(K clef, V valr);

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
		* @pre il existe un couple contenant clf dans la Aliste
		* 
		* @b Complexité O(nbc), nbc = nombre de couples stockés
		*/
		V valeurAssociee(K clf) const;

		/**
		* @brief Suppression d'un couple
		* @param clf la clef du couple à supprimer
		* @attention Ne fait rien si aucun couple n'existe pour cette clef dans la Aliste
		* 
		* @b Complexité O(nbc), nbc = nombre de couples stockés
		*/
		void dissocier(K clf);

		/**
		* @brief Test de la présence d'un couple
		* @param clf la clef du couple à rechercher
		* @return vrai ssi il existe un couple de clef clf dans la Aliste
		* 
		* @b Complexité O(nbc), nbc = nombre de couples stockés
		*/
		bool estClef(K clf) const;

		/**
		* @brief Accès à l'ensemble des clefs
		* @return un tableau contenant toutes les clefs utilisées dans la Aliste
		* 
		* @b Complexité Θ(nbc), nbc = nombre de couples stockés
		*/
		std::vector<K> trousseau() const;

}; // class Aliste<K,V>

#include "aliste.tpp" // définition des méthodes 
/******************************************************************************/
// K.Gonnord , V.Sébastien
#endif // ALISTE_HPP
