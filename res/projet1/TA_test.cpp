/**
 * @file TA_test.cpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Programme de test des implémentations de Table Associative
**/

#include <iostream>
#include <climits>

#include "aliste.hpp"
#include "htable.hpp"
#include "mappe.hpp"

using namespace std;

//------------------------------------------------------------------------------
// Programme principal
int main()
{
   Mappe<int,double> m;

   cout << boolalpha;
   cout << "initialement vide ? " << m.estVide() << endl;
   
   for (int i=1; i<INT_MAX/2; i*=2)
   {
      m.associer(i,i/4.0);
   }
   
   cout << "toujours vide ? " << m.estVide() << endl;
   cout << "m.estClef(1024) ? " << m.estClef(1024) << endl;

   // À COMPLÉTER ...
   
   return 0;
}
