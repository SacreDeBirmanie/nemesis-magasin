/**
 * @file magasin.tpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Implémentation des fonctions de la classe Magasin
**/

#include <cassert>
#include <fstream>
#include <string>
#include <sstream>

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
Magasin<TableAssociative>::Magasin(std::string entrepot)
{
	// ouverture du fichier entrepot
	std::ifstream fic(entrepot);
	// erreur en cas de lecture impossible
	assert(fic.is_open());
	// lecture de l'entrepot
	std::string ligne;
	getline(fic,ligne);
	while(!fic.eof())
	{  // traitement d'une ligne du fichier
	std::stringstream ss(ligne);
	std::string nom;
	double poids,prix;
	int codebarre;
	unsigned int quantite;
	// récupération des données de la ligne : le fichier est supposé bien formé
	ss >> codebarre >> nom >> poids >> prix >> quantite;
	// ajout du produit au catalogue
	catalogue_.push_back(Produit(nom,poids,codebarre));
	// association du prix
	prix_.associer(codebarre,prix);
	// association du stock
	if (quantite>0)
	{
	 stock_.associer(codebarre,quantite);
	}
	// lecture de la prochaine ligne (si elle existe)
	getline(fic,ligne);
	}
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
const std::vector<Produit> & Magasin<TableAssociative>::catalogue() const
{
	return catalogue_;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
double Magasin<TableAssociative>::tarif(const Produit & p) const
{  
	return prix_.valeurAssociee(p.codebarre());
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
unsigned int Magasin<TableAssociative>::stock(const Produit & p) const
{
	if ( stock_.estClef(p.codebarre()) ){
   		return stock_.valeurAssociee(p.codebarre());
	}
	else {
		return 0;
	}
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
void Magasin<TableAssociative>::vendre(const Produit & p, unsigned int qt)
{
	int diff;

	diff = stock(p) - qt;
	if ( diff >= 0 ){
		if ( diff == 0 ) {
			stock_.dissocier( p.codebarre() );
		}
		else {
			stock_.associer( p.codebarre(), diff );
		}
	}
   	
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
void Magasin<TableAssociative>::solder(const Produit & p, unsigned int promo)
{
	if ( prix_.estClef(p.codebarre()) && promo >= 1 && promo <= 99 ){
		prix_.associer( p.codebarre(), tarif(p)-( tarif(p)*((1.0*promo)/100)) );
	}
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
std::vector<Produit> Magasin<TableAssociative>::inventaire() const
{
	std::vector<Produit> res;

	for( auto p : catalogue() ){
		if ( stock(p) < 10 ){
			res.push_back(p);
		}
	}
	return res;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
double Magasin<TableAssociative>::capital()
{
	double somme = 0;	

	for( auto p : catalogue() ){
		somme = somme + (tarif(p)*stock(p));
	}
	return somme;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
double Magasin<TableAssociative>::nettoyageDePrintemps()
{
	double somme = 0;	

	for( auto p : catalogue() ){
		if ( (tarif(p)*stock(p)) < 10 ) { 
			somme = somme + (tarif(p)*stock(p));
		}
	}
	return somme;
}
