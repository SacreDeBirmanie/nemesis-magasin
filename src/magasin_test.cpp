#include <iostream>
#include <ctime>

#include "produit.cpp"
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
	Magasin<Htable> m("entrepot_11.txt");
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
	
	cout << "REDUCTION" << endl;
	cout << "------------" << endl;
	START;
	m.solder(m.catalogue()[2], 99);
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "VENTE" << endl;
	cout << "------------" << endl;
	START;
	m.vendre(m.catalogue()[3], 1);
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "AFFICHAGE APRES VENTE ET REDUCTION" << endl;
	cout << "---------" << endl;
	START;
	cout << "vente de 3 dessert_1 " << endl;
	cout << "reduction de 99% sur le fromage_1" << endl;
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

	cout << "AFFICHAGE DE L'INVENTAIRE" << endl;
	cout << "---------" << endl;
	START;
	for (auto p : m.inventaire())
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

	cout << "CALCUL DU CAPITAL" << endl;
	cout << "---------" << endl;
	START;
	cout << m.capital() << endl;
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;

	cout << "NETTOYAGE DE PRINTEMPS" << endl;
	cout << "---------" << endl;
	START;
	cout << m.nettoyageDePrintemps() << endl;
	STOP;
	cout << ">>> Temps : " << TEMPS << "s" << endl << endl;


   return 0;
}
