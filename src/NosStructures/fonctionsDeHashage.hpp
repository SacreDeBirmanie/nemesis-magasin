#ifndef FONCTIONSDEHASHAGE_HPP
#define FONCTIONSDEHASHAGE_HPP

#include <iostream>
#include <string>

class fonctionsDeHashage{
	int hash(int clf,int taille);
	int hash(float clf,int taille);
	int hash(char clf, int taille);
	int hash(std::string clf, int taille);
		
};

#endif // FONCTIONSDEHASHAGE_HPP

