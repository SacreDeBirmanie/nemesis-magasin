/*
* File : Hashage.cpp
* Fichier contenant l'implémentation de la classe Hashage
* Authors : Francois Hallereau & Sébastien Vallée
*/

#include "Hashage.hpp"
#include <typeinfo>
//---------------------------------------

//Constructeur
template<typename K, typename V>
Hashage<K,V>::Hashage() : hacher(new fonctionsDeHashage()){}


//Destructeur
template<typename K, typename V>
Hashage<K,V>::~Hashage() {}


//Fonction de hachage
template<typename K, typename V>
int Hashage<K,V>::hash(K cle) {
   return hacher->hash(cle,TAILLE);
}

//ajoute le couple (clf,valr) ou change la valeur associée à clf s'il y en avait une
template <typename K,typename V>
void Hashage<K,V>::associer(K clf,V valr){
	int hashageur = hash(clf);
	this->list[hashageur].associer(clf,valr);
	indices.insert(hashageur);
}


template <typename K,typename V>
bool Hashage<K,V>::estVide(){
   return indices.empty();

}

template <typename K,typename V>
V Hashage<K,V>::valeurAssociee(K clf){
    return this->list[hash(clf)].valeurAssociee(clf);
}

template <typename K,typename V>
void Hashage<K,V>::dissocier(K clf){
	int hashageur = hash(clf);
    this->list[hashageur].dissocier(clf);
    if(this->list[hashageur].estVide())
		indices.erase(hashageur);
    
}


template <typename K,typename V>
bool Hashage<K,V>::estClef(K cle){
    return this->list[hash(cle)].estClef(cle);
}

template <typename K,typename V>
std::vector<K> Hashage<K,V>::trousseau(){
    std::vector<K> clfs;
    int j,taille;
    if(! this->estVide() ) {
        std::set<int>::iterator it = this->indices.begin() ;
		for (it ; it != this->indices.end() ; it ++)
		{
           std::vector<K> temp; //on crée un tableau temporaire stockant les clef de la AList courante
			temp = (this->list[*it]).trousseau(); //on applique trousseau(...) sur la AList courante
			
			taille = int(temp.size());
            
            for(j = 0; j < taille; j++) { //on parcours le liste des clefs dans le tableau temporaire
                clfs.push_back(temp[j]); //on l'ajoute au tableau de réponse
            }
        }
    }
    return clfs;
}
