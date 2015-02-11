#include "AListe.hpp"

template <typename K, typename V>
AListe<K,V>::AListe (){
	this->tete = NULL;
	this->nb=0;
}
	
template <typename K, typename V>
AListe<K,V>::~AListe (){
	
}

template <typename K, typename V>
void AListe<K,V>::associer(K clf,V valr){
	
	
	if(estALVide()){
		maillon * mama = new maillon;
		mama->suivant=NULL;
		mama->clf=clf;
		mama->elt=valr;
		
		this->tete = mama;
		this->nb++;
	}
	else{
		maillon * precedent = NULL;
		maillon * courant = this->tete;
		bool trouve = false;
		
		while(courant != NULL && trouve==false){
			if(courant->clf==clf)
				trouve=true;
			else{
				precedent = courant;
				courant = courant->suivant;
			}
		}
		if(trouve==false){
			maillon * mama = new maillon;
			mama->suivant=NULL;
			mama->clf=clf;
			mama->elt=valr;
			precedent->suivant = mama;
			this->nb++; 
		}
		else
			courant->elt=valr;
	}
}

template <typename K, typename V>
bool AListe<K,V>::estALVide(){
	return this->nb==0;
}
template <typename K, typename V>
V AListe<K,V>::valeurAssocie(K clf){
	
	maillon * courant = this->tete;
	V res = NULL;
	bool trouve = false;
	
	while(courant != NULL && trouve==false){
		if(courant->clf==clf){
			res = courant->elt;
			trouve = true;
		}
		else
			courant = courant->suivant;
	}
	
	return res;
	
}
template <typename K, typename V>
void AListe<K,V>::dissocier(K clf){
	
	maillon * precedent = NULL;
	maillon * courant = this->tete;
	bool trouve = false;
	
	while(courant != NULL && !trouve){
		if(courant->clf == clf ){
			trouve = true;
			if(precedent == NULL){
				maillon * tmp = this->tete;
				this->tete = this->tete->suivant;
				delete(tmp);
			}
			else{
				precedent->suivant = courant->suivant;
				delete(courant);
			}
			this->nb--;
		}
		else
			courant = courant ->suivant;
	}
}
template <typename K, typename V>
bool AListe<K,V>::estClef(K clf){
		maillon * courant = this->tete;
		bool trouve = false;
		
		while(courant != NULL && !trouve){
			if(courant->clf==clf)
				trouve=true;
			else
				courant = courant->suivant;
		}
		
		return trouve;
}
template <typename K, typename V>
std::set<K> AListe<K,V>::trousseau(int & N ){
	std::set<K> clfs ;
	if(estALVide()){
		N = 0;
	}
	else{
		N = 0;
		maillon * courant = this->tete;
		
		while(courant !=NULL){
			clfs.insert(courant->clf);
			N = N + 1;
			courant = courant->suivant;
		}
	}
	
	return clfs;
}

