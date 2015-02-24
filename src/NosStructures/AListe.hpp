#ifndef ALISTE_HPP
#define ALISTE_HPP

#include <vector>
template <typename K, typename V>
class AListe{
	private:
	
		
		struct maillon{
				K clf;
				V elt;
				maillon * suivant;	
		};
		typedef struct maillon maillon;
		
		maillon * tete;
		int nb;
		
	public :
		///constructeur, crée une AListe vide
		AListe ();
		/// destructeur, libère la mémoire
		~AListe ();
		///ajoute le couple (clf,valr) dans la AListe ou modifie la valr associé à la clef
		/// @param clf, la clef de la valeur
		/// @param valr, la valr qui va être stocké à la clef donné 
		void associer(K clf,V valr); 
		///retourne un booléen pour savoir si la AListe est vide
		bool estALVide();
		///
		V valeurAssocie(K clf); //donne la valeur associée à la clef clf
		void dissocier(K clf); //supprime le couple (clf,.) ; ne fait rien s'il n'y en a pas
		bool estClef(K clf); //teste l'existence d'un couple (clf,.)
		std::vector<K> trousseau(int & N); // mets les clefs présentes dans un ensemble et la taille dans N passé en référence
		
};

#endif // ALISTE_HPP
