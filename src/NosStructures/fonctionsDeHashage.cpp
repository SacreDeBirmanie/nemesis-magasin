#include "fonctionsDeHashage.hpp"
int fonctionsDeHashage::hash(int clf,int taille){
	return (clf%taille);
}

int fonctionsDeHashage::hash(float clf,int taille){
	return (int(clf)%taille) ;
}

int fonctionsDeHashage::hash(char clf,int taille){
	return 1;
}

int fonctionsDeHashage::hash(std::string clf,int taille){
	int i = 0, nombreHache = 0;
	for (i = 0 ; clf[i] != clf.size() ; i++)
	{
		nombreHache += clf[i];
	}
		nombreHache %= taille;
		return nombreHache;
}
