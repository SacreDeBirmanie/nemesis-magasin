#include "fonctionsDeHashage.hpp"
int fonctionsDeHashage::hash(int clf,int taille){
	return (cle%taille);
}

int fonctionsDeHashage::hash(float clf,int taille){
	return ( (int)(cle%taille) );
}

int fonctionsDeHashage::hash(char clf,int taille){
	
}

int fonctionsDeHashage::hash(string clf,int taille){
	int i = 0, nombreHache = 0;
	for (i = 0 ; clf[i] != clf.length ; i++)
	{
		nombreHache += clf[i];
	}
		nombreHache %= taille;
		return nombreHache;
}
