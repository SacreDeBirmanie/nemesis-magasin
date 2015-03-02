/**
 * @file TA_test.cpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Programme de test des implémentations de Table Associative
**/

#include <iostream>
#include <climits>
#include <vector>

#include "aliste.hpp"
#include "htable.hpp"
#include "mappe.hpp"

using namespace std;

//------------------------------------------------------------------------------
// Programme principal
int main()
{
	Aliste<int,double> m;
	vector<int> clefs;

	cout << boolalpha;
	cout << "initialement vide ? " << m.estVide() << endl;

	for (int i=1; i<INT_MAX/2; i*=2)
	{
	m.associer(i,i/4.0);
	}

	cout << "toujours vide ? " << m.estVide() << endl;
	cout << "m.estClef(1024) ? " << m.estClef(1024) << endl;
	clefs = m.trousseau();
	for (int i=0; i<clefs.size(); i++){
		cout << "clef : " << clefs[i] << ", valeur : " << m.valeurAssociee(clefs[i]) << endl;
	}
	cout << " --------------------------------- " << endl;
	cout << "suppresion du couple qui a pour clef 1024 " << endl;
	cout << " --------------------------------- " << endl;
	m.dissocier(1024);
	clefs = m.trousseau();
	for (int i=0; i<clefs.size(); i++){
		cout << "clef : " << clefs[i] << ", valeur : " << m.valeurAssociee(clefs[i]) << endl;
	}
	cout << "m.estCleft(1024) ? " << m.estClef(1024) << endl;
	
   
   return 0;
}
