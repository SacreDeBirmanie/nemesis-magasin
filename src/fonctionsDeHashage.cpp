/**
 * @file Htable.tpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Implémentation de la classe Htable<K,V>
 * 
 * @b Note s'agissant d'un patron de classe, ce fichier est inclus dans htable.hpp
**/

int fonctionsDeHashage::hash(const int clf,int taille){
	return (clf%taille);
}

int fonctionsDeHashage::hash(unsigned int clf,int taille){
	return (clf%taille);
}

int fonctionsDeHashage::hash(float clf,int taille){
	return (int(clf)%taille) ;
}

int fonctionsDeHashage::hash(char clf,int taille){
	return clf%taille;
}

int fonctionsDeHashage::hash(char *clf,int taille){
	int i = 0, nombreHache = 0;
	
	for (i = 0 ; clf[i] != '\0' ; i++){

        nombreHache += clf[i];
	}
	nombreHache %= taille;
	
	return nombreHache;
}

int fonctionsDeHashage::hash(std::string clf,int taille){
	int i = 0, nombreHache = 0;
	for (i = 0 ; clf[i] != int(clf.size()) ; i++)
	{
		nombreHache += clf[i];
	}
		nombreHache %= taille;
		return nombreHache;
}
