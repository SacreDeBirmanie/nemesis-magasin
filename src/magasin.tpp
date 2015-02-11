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
   // À IMPLÉMENTER
   return 0.0;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
unsigned int Magasin<TableAssociative>::stock(const Produit & p) const
{
   // À IMPLÉMENTER
	return 0;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
void Magasin<TableAssociative>::vendre(const Produit & p, unsigned int qt)
{
   // À IMPLÉMENTER
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
void Magasin<TableAssociative>::solder(const Produit & p, unsigned int promo)
{
   // À IMPLÉMENTER
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
std::vector<Produit> Magasin<TableAssociative>::inventaire() const
{
   std::vector<Produit> res;
   // À IMPLÉMENTER
   return res;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
double Magasin<TableAssociative>::capital()
{
   // À IMPLÉMENTER
   return 0.0;
}

//--------------------------------------------------------------------
template < template <typename K, typename V> class TableAssociative >
double Magasin<TableAssociative>::nettoyageDePrintemps()
{
   // À IMPLÉMENTER
   return 0.0;
}
