/**
 * @file magasin.hpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Définition d'un patron de classe Magasin<TA<K,V>>
 *        paramétré par un type TA<K,V> qui doit être conforme
 *        à la spécification de AListe
**/

#ifndef __MAGASIN_HPP__
#define __MAGASIN_HPP__

#include <string>
#include <vector>
#include "produit.hpp"

/**
 * @class Magasin magasin.hpp
 * 
 * @brief Patron de classe implémentant un magasin de Produits
 * 
 * Le magasin dispose d'un catalogue de produits ;
 * Il associe à chacun un prix unitaire et un stock ;
 * Le paramètre template TableAssociative<K,V> définit
 * la structure de stockage des informations ; il doit
 * être conforme à la spécification de AListe
 */
template < template <typename K, typename V> class TableAssociative >
class Magasin
{
   private:
      // Ensemble des Produits au catalogue du magasin
      std::vector<Produit> catalogue_;

      // Table associative Etiquette-->Prix de vente unitaire
      // Note : tout produit en catalogue a un prix associé
      TableAssociative<unsigned int,double> prix_;

      // Table associative Etiquette-->Quantité en stock
      // Note : les produits du catalogue épuisés ne sont pas en stock
      TableAssociative<unsigned int,unsigned int> stock_;

   public:
      /** 
       * @brief Constructeur, construit le magasin à partir d'un entrepôt
       * @param entrepot le nom du fichier entreposant les produits et leurs informations
       * @attention L'entrepôt peut contenir des produits dont le stock est nul ; 
       * en ce cas, ils sont ajoutés au catalogue et à la liste des prix, mais pas 
       * au stock @n <em>=> le trousseau du stock peut différer du catalogue</em>
       * 
       * @b Complexité Θ(nbp), nbp = nombre de produits dans le fichier entrepot
       */
      Magasin(std::string entrepot);

      /** 
       * @brief Accès (en lecture seulement) au catalogue de produits du magasin
       * @return le catalogue (référence constante => donnée partagée mais immuable)
       * 
       * @b Complexité Θ(1)
       */
      const std::vector<Produit> & catalogue() const;

      /** 
       * @brief Accès au prix unitaire d'un produit en catalogue
       * @param p le produit
       * @return le prix unitaire du produit p
       * @pre le produit est dans le catalogue
       * 
       * @b Complexité <em>À déterminer</em>
       */
      double tarif(const Produit & p) const;

      /** 
       * @brief Accès au stock d'un produit
       * @param p le produit
       * @return la quantité du produit p en stock, ou 0 s'il n'est pas en stock
       * @pre le produit est dans le catalogue
       * 
       * @b Complexité <em>À déterminer</em>
       */
      unsigned int stock(const Produit & p) const;		

      /** 
       * @brief Vendre un produit à un client
       * @param p produit
       * @param qt la quantité à retirer au stock
       * @pre Le produit doit exister dans le catalogue et être en quantité suffisante
       *        en stock
       * @post si sa quantité tombe à 0, le produit est retiré du stock
       * 
       * @b Complexité <em>À déterminer</em>
       */
      void vendre(const Produit & p, unsigned int qt);

      /** 
       * @brief Appliquer une promotion au prix d'un produit en catalogue
       * @param p le produit à solder
       * @param promo un entier entre 1 et 99, le pourcentage de promotion
       * @pre Le produit doit exister dans le catalogue
       * 
       * @attention À implémenter
       * 
       * @b Complexité <em>À déterminer</em>
       */
      void solder(const Produit & p, unsigned int promo);
      
      /** 
       * @brief Identifier les produits du catalogue à réapprovisionner
       * @return l'ensemble des produits dont le stock est inexistant ou strictement 
       * inférieur à 10 unités
       * 
       * @b Complexité <em>À déterminer</em>
       */
      std::vector<Produit> inventaire() const;

      /** 
       * @brief Calculer le capital marchand du magasin
       * @return le prix total des marchandises stockées
       * 
       * 
       * @b Complexité <em>À déterminer</em>
       */
      double capital();

      /** 
       * @brief Supprimer les produits inutiles du stock
       * 
       * Un produit est inutile si sa valeur stockée (prix*quantité) est strictement inférieure à 10
       * @return le prix total des produits jetées
       * 
       * @b Complexité <em>À déterminer</em>
       */
      double nettoyageDePrintemps();
};

#include "magasin.tpp"

#endif // __MAGASIN_HPP__
