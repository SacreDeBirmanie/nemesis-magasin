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
}

template <typename K,typename V>
bool Hashage<K,V>::estVide(){
    bool res = true;
    for(int i=0;i<TAILLE;i++){
        if(!this->list[i].estALVide())
            res=false;
    }
    return res;
}


template <typename K,typename V>
V Hashage<K,V>::valeurAssocie(K clf){
    return this->list[hash(clf)].valeurAssociee(clf);
}

template <typename K,typename V>
void Hashage<K,V>::dissocier(K clf){
    this->list[hash(clf)].dissocier(clf);
}


template <typename K,typename V>
bool Hashage<K,V>::estClef(K cle){
    return this->list[hash(cle)].estClef(cle);
}

template <typename K,typename V>
void Hashage<K,V>::trousseau(K* clfs, int N ){
    K* temp;
    int i,j,taille;
    int cur = 0; //indice du prochain ajout
    if(! this->estVide() ) {
        for(i = 0; i < TAILLE; i++) { //on parcours toutes les AList de la table de hashage
            temp = new K[100]; //on crée un tableau temporaire stockant les clés de la AList courante
            this->tab[i].trousseau(temp,taille); //on applique trousseau(...) sur la AList courante
            N += taille; //on met à jour la taille de N

            for(j = 0; j < taille; j++) { //on parcours le liste des clefs dans le tableau temporaire
                clfs[cur] = temp[j]; //on l'ajoute au tableau de réponse
                cur++; //on met à jour l'indice d'ajout dans le tableau de réponse
            }
            delete[] temp;
        }
    }
}
