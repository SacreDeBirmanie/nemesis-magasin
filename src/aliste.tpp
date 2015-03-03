/**
 * @file alist.tpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Implémentation de la classe Aliste<K,V>
 * 
 * @b Note s'agissant d'un patron de classe, ce fichier est inclus dans alist.hpp
**/
#include <assert.h>
using namespace std;

/////////////////////////////////////////////////////
template < typename k, typename v >
Aliste< k, v >::Aliste()
{
	// Initialisation de la tete à l'adresse NULL
	ch.tete = NULL;	
	// Initialisation du nombre d'élément à 0
	ch.nb_elt = 0;	
}

/////////////////////////////////////////////////////
template < typename k, typename v >
Aliste< k, v > ::~Aliste() 
{
	// désallocation chaque maillon
	while ( !estVide() ) {
		dissocier( (*ch.tete).clef );
	}	
} 

/////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
bool Aliste< k, v > :: estVide() const
{
	return ch.nb_elt == 0;
}

//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
bool Aliste< k, v > :: estClef(k clef) const
{
	// maillon de parcours
	Maillon * c;		
	// booléen à retourner
	bool trouve ;		

	// initialisation du booléen à faux
	trouve = false;	
	// initialisation du maillon de parcours avec la tête	
	c = ch.tete;
	// parcourt du chainage s'il y a au moins un couple,
	// le booléen devient vrai si la clef donnée en paramètre correspond à la clef d'un couple		
	if ( !estVide() ) {	
		while ( c != NULL ) {			
			if ( (*c).clef == clef ) {
				trouve = true;		
			}
			c = (*c).succ;	
		}
	}
	return trouve;
}


//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
void Aliste< k, v > :: associer( k clef, v valr )
{
	// nouveau maillon
	Maillon * nouveau; 		

	// allocation mémoire pour le nouveau maillon
	nouveau = new (Maillon);
	// la clef du nouveau maillon est celle placée en paramètre	
	(*nouveau).clef = clef;	
	// la valeur du nouveau maillon est celle placée en paramètre	
	(*nouveau).valr = valr;
	// si la clef donnée en paramètre est déjà utilisée on supprime le couple	
	if ( estClef(clef) ) {		
		dissocier(clef);
	}
	// sinon mise a jour du nombre de couple (clef, valeur) dans la Aliste
	else {					
		ch.nb_elt = ch.nb_elt + 1; 
	}
	// insertion en tête du nouveau maillon
	(*nouveau).succ = ch.tete;
	ch.tete = nouveau;
	
}
	

/////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
v Aliste< k, v > :: valeurAssociee(k clef) const
{	
	// maillon de parcours
	Maillon * c;		
	
	// initialisation du maillon de parcours avec le maillon de tête
	c = ch.tete;
	// parcourt du chainage jusqu'au maillon contenant la clef donnée en paramètre
	while ( (*c).clef != clef ) {	
		c = (*c).succ;
	}
	return (*c).valr;
}

//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
void Aliste< k, v > :: dissocier(k clef)
{
	// maillon de parcours
	Maillon * c;
	// maillon précédent le maillon de parcours	
	Maillon * pred;	
	
	// initialisation du maillon de parcours avec le maillon de tête
	c = ch.tete;	
	// si la clef se trouve en tête, mise à jour de la tête avec le maillon suivant, suppression du maillon, et mise à jour du nombre de couples
	if ( (*c).clef == clef ) {
		ch.tete = (*ch.tete).succ;
		delete(c);
		ch.nb_elt = ch.nb_elt - 1;
	}
	// sinon parcourt du chainage jusqu'au maillon contenant la clef si présente
	else {
		while ( c != NULL && (*c).clef != clef ) {
			pred = c;
			c = (*c).succ;
		}
		// si la clef est présente, suppresion du maillon et mise à jour du nombre de couples
		if ( c != NULL ){
			(*pred).succ = (*c).succ;
			delete(c);
			ch.nb_elt = ch.nb_elt - 1;
		}
	}
	
}


//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
std::vector<k> Aliste< k, v > :: trousseau() const
{
	// vecteur contenant les clefs
	std::vector<k> clfs;
	// maillon de parcours
	Maillon * c;
	// indice du vecteur		
	int i = 0;		

	// maillon de parcours initialisé à la tête
	c=ch.tete;
	// parcourt du chainage en ajoutant les clefs de chaque couples dans le vecteur
	while ( c != NULL) {
		clfs.push_back((*c).clef);	
		i = i+1;		
		c = (*c).succ;
	}		
	return clfs;
}



