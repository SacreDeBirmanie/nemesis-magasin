#include <string>
#include <iostream>


#include "Hashage.hpp"

using namespace std;

int main(){
	Hashage<int,int> * liste1 = new Hashage<int,int>();
	//Aliste<string,int> * liste2 = new AListe<string,int>();
	//Aliste<int,string>  * liste2 = new AListe<int,string>();
	
	liste1->associer(1,3);
	liste1->associer(2,3);
	liste1->associer(3,1);
	liste1->associer(4,5);
	liste1->associer(23,50);
	
	cout<<liste1->valeurAssocie(23)<<endl;
	liste1->associer(23,12);
	cout<<liste1->valeurAssocie(23)<<endl;
	cout<<liste1->valeurAssocie(3)<<endl;
	cout<<liste1->estClef(50)<<endl;
	cout<<liste1->estClef(2)<<endl;
	cout<<liste1->estClef(1)<<endl;
	liste1->dissocier(1);
	cout<<liste1->estClef(1)<<endl;
	
	int N;
	set<int> ens;
	ens = liste1->trousseau(N);
	
	std::cout << "[" << std::endl;
	for(std::set<int>::iterator it=ens.begin(); it!=ens.end(); ++it)
    std::cout << *it << std::endl;
    std::cout << "]" << std::endl;

} 
