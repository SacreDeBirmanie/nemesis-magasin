/**
 * @file htable.tpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Implémentation de la classe Htable<K,V>
 * 
 * @b Note s'agissant d'un patron de classe, ce fichier est inclus dans htable.hpp
**/
#include <typeinfo>
//---------------------------------------

//Constructeur
template<typename K, typename V>
Htable<K,V>::Htable() : hacher(new fonctionsDeHashage()){}//creation de l'objet pour les fonctions de hash


//Destructeur
template<typename K, typename V>
Htable<K,V>::~Htable() {}


//Fonction de hachage
template<typename K, typename V>
int Htable<K,V>::hash(K cle) const {
   return hacher->hash(cle,TAILLE);//retourne le code de hash de la clef
}

//ajoute le couple (clf,valr) ou change la valeur associée à clf s'il y en avait une
template <typename K,typename V>
void Htable<K,V>::associer(K clf,V valr){
	int hashageur = hash(clf);
	this->list[hashageur].associer(clf,valr);//insere dans la Aliste de l'indice du code de hash
	indices.insert(hashageur);//insert l'indice dans l'ensemble des indices utilisés
}


template <typename K,typename V>
bool Htable<K,V>::estVide() const{
   return indices.empty();

}

template <typename K,typename V>
V Htable<K,V>::valeurAssociee(K clf) const{
    return this->list[hash(clf)].valeurAssociee(clf);
}

template <typename K,typename V>
void Htable<K,V>::dissocier(K clf){
	int hashageur = hash(clf);
    this->list[hashageur].dissocier(clf);//dissocie la clef de la Aliste
    if(this->list[hashageur].estVide())//on vérifie si la Aliste est vide
		indices.erase(hashageur);//sioui on l'enleve de l'ensemble des indices
    
}


template <typename K,typename V>
bool Htable<K,V>::estClef(K cle) const{
    return this->list[hash(cle)].estClef(cle);
}

template <typename K,typename V>
std::vector<K> Htable<K,V>::trousseau() const{
    std::vector<K> clfs;//vector à retourner
    int j,taille;
    if(! this->estVide() ) { //on vérifie quenotre htable n'est pas vide
        std::set<int>::iterator it = this->indices.begin() ;
		for (it ; it != this->indices.end() ; it ++) // on parcour la l'ensemble des indices contenant au moins une valeur
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
