#include <iostream>
#include <ctime>

#include "produit.hpp"
#include "magasin.hpp"

#include "aliste.hpp"
#include "htable.hpp"
#include "mappe.hpp"
using namespace std;

//------------------------------------------------------------------------------
// Fonctionnalités de chronométrage
/**
 * @var chrono
 * @brief chronomètre du programme
**/
clock_t chrono;

/**
 * @def START
 * @brief démarre le chronomètre
**/
#define START chrono=clock()

/**
 * @def STOP
 * @brief arrête le chronomètre
**/
#define STOP chrono=clock()-chrono

/**
 * @def TEMPS
 * @brief donne le temps du chronomètre (après arrêt)
**/
#define TEMPS double(chrono)/CLOCKS_PER_SEC

//------------------------------------------------------------------------------
// Programme principal
int main()
{

   cout << "CONSTRUCTION" << endl;
   cout << "------------" << endl;
   START;
   Magasin<Mappe> m("entrepot_11.txt");
   STOP;
   cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

   cout << "AFFICHAGE" << endl;
   cout << "---------" << endl;
   START;
   for (auto p : m.catalogue())
   {
      p.afficher();
      cout << " :  prix=";
      cout.width(4);
      cout.fill('0');
      cout << m.tarif(p) << "€";
      cout << "  qté=" << m.stock(p) << endl;
   }
   STOP;
   cout << ">>> Temps : " << TEMPS << "s" << endl << endl;
   
   // À COMPLÉTER ...
   
   return 0;
}
