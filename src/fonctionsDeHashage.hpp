/**
 * @file fonctionsdeHashage.hpp
 * @author Gonnord Kévin, Vallée Sébastien
 * @since 11/02/2015
 * @brief Définition du type fonctionsDeHashage permettant de retourner un code entier en fonction de différent type générique

**/

#ifndef FONCTIONSDEHASHAGE_HPP
#define FONCTIONSDEHASHAGE_HPP

#include <iostream>
#include <string>

class fonctionsDeHashage{
	public :
		int hash(const int clf,int taille);
		int hash(float clf,int taille);
		int hash(unsigned int clf,int taille);
		int hash(char clf, int taille);
		int hash(char *clf,int taille);
		int hash(std::string clf, int taille);
		
};
#include "fonctionsDeHashage.cpp"
#endif // FONCTIONSDEHASHAGE_HPP

