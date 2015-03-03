/**
 * @file produit.cpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Implémentation de la classe Produit
**/

#include "produit.hpp"
#include <iostream>

//------------------------------------------------------------------------------
Produit::Produit(std::string n, double p, unsigned int e)
// initialisation à la déclaration des attributs
: nom_(n), poids_(p), codebarre_(e)
{
   // rien à faire
}

//------------------------------------------------------------------------------
std::string Produit::nom() const
{
   return nom_;
}

//------------------------------------------------------------------------------
double Produit::poids() const
{
   return poids_;
}

//------------------------------------------------------------------------------
unsigned int Produit::codebarre() const
{
   return codebarre_;
}

//------------------------------------------------------------------------------
void Produit::afficher() const
{
   std::cout << "[" << codebarre_ << "] ";
   std::cout.width(20);
   std::cout.fill('.');
   std::cout << std::left << nom_;
   std::cout.width(5);
   std::cout.fill('0');
   std::cout << poids_ << "kg";
}
