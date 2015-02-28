/* 
	Definition des méthodes de Aliste

*/
#include <assert.h>
using namespace std;

/////////////////////////////////////////////////////
template < typename k, typename v >
Aliste< k, v >::Aliste() // constructeur par défaut, crée Aliste vide
{
	ch.tete = NULL;	//Initialisation de la tete à l'adresse NULL
	ch.nb_elt = 0;	//Initialisation du nombre d'élément à 0
}

/////////////////////////////////////////////////////
template < typename k, typename v >
Aliste< k, v > ::~Aliste() // destructeur, libère la mémoire
{
	while ( ch.tete != NULL ) {
		dissocier( (*ch.tete).clef );
	}	
} 

/////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
bool Aliste< k, v > :: estVide() const // vrai si et seulement si aucune clef n'est stockée
{
	return ch.nb_elt == 0;
}

//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
bool Aliste< k, v > :: estClef(k clef) const
{
	Maillon * c;		// maillon de parcours
	bool trouve ;		// booléen à retourner

	trouve = false;		// initialisation du booléen à faux
	c = ch.tete;		// initialisation du maillon de parcours avec la tête
	if ( !estVide() ) {	// s'il y a des couples
		while ( c != NULL ) {			// on parcourt chaque maillon
			if ( (*c).clef == clef ) {	// si la clef est présente dans un maillon
				trouve = true;		// le booléen passe à vrau
			}
			c = (*c).succ;			
		}
	}
	return trouve;	// retourne le booléen
}


//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
void Aliste< k, v > :: associer( k clef, v valr ) //ajoute le couple (clef,valr), ou change la valeur associée à clef s'il y en a une
{

	Maillon * c;		// maillon de parcours
	c = ch.tete;		// initialisation du maillon de parcours avec le maillon de tête pour commencer au début

	if ( estClef(clef) ) {	// si la clef donné en paramètre est déjà utilisée
		while ((*c).clef != clef ) {	// on parcourt le chaînage jusqu'a trouvé le maillon contenant cette clef
			c = (*c).succ;	
		}
		(*c).valr=valr;			// on change la valeur du maillon avec la valeur donnée en paramètre	
	}
	else {
		Maillon * nouveau; 		// nouveau maillon à insérer
		nouveau = new (Maillon);	// allocation mémoire pour le nouveau maillon
		(*nouveau).clef = clef;		// la clef du nouveau maillon est celle placée en paramètre
		(*nouveau).valr = valr; 	// la valeur du nouveau maillon est celle placée en paramètre
		(*nouveau).succ = NULL;		// le nouveau maillon sera la queue du chainage

		if ( ch.nb_elt == 0){ 		// cas où le chaînage est vide
			ch.tete = nouveau;	// le nouveau maillon devient la tête du chaînage
			(*nouveau).succ = NULL; // le successeur du nouveau maillon ne pointe sur aucun maillon
		}
		else {				// cas où le chaînage n'est pas vide
			while ( (*c).succ != NULL ) {	// tant que le successeur du maillon de parcours est suivis par un autre maillon
				c = (*c).succ;		// le maillon de parcours passe au maillon suivant
			}
			(*c).succ = nouveau;		// la queue devient le nouveau maillon
		}
	ch.nb_elt = ch.nb_elt + 1;	//mise a jour du nombre de couple (clef, valeur) dans la aliste
	}
}
	

/////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
v Aliste< k, v > :: valeurAssociee(k clef) const
{
	assert(estClef(clef));	// assertion qui vérifié si la clef donné en paramètre est utilisée
	
	Maillon * c;		// maillon de parcours

	c = ch.tete;		// initialisation du maillon de parcours avec le maillon de tête
	while ( (*c).clef != clef ) {	// tant que le maillon de parcours ne contient pas la clef donné en paramètre
		c = (*c).succ;		// on passe au maillon suivant
	}
	return (*c).valr;		// on retourne la valeur du maillon associé à la clef donné en paramètre
}

//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
void Aliste< k, v > :: dissocier(k clef)
{
	Maillon * c;	// maillon de parcours
	Maillon * pred;	// maillon précédent le maillon de parcours
	
	c = ch.tete;	// initialisation du maillon de parcours avec le maillon de tête
	if ( (*c).clef == clef ) {
		ch.tete = (*ch.tete).succ;
		delete(c);
		ch.nb_elt = ch.nb_elt - 1;
	}
	else {
		while ( c != NULL && (*c).clef != clef ) {
			pred = c;
			c = (*c).succ;
		}
		if ( c != NULL ){
			(*pred).succ = (*c).succ;
			delete(c);
			ch.nb_elt = ch.nb_elt - 1;
		}
	}
	
}


//////////////////////////////////////////////////////////////////////////
template < typename k, typename v >
std::vector<k> Aliste< k, v > :: trousseau()
{
	std::vector<k> clfs;
	Maillon * c;		// maillon de parcours
	int i = 0;		// indice du tableau

	c=ch.tete;		// maillon de parcours initialisé à la tête
	while ( c != NULL) {	// tant que le maillon de parcours pointe sur un maillon du chainage
		clfs.push_back((*c).clef);	// on stocke les clefs de chaque maillon dans le tableau donné en paramètre
		i = i+1;		// on met a jours l'indice
		c = (*c).succ;		// on passe au maillon suivant
	}		
	return clfs;
}



