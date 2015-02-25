#include <string>
#include <iostream>


#include "Hashage.cpp"

using namespace std;

int main(){
	Hashage<int,int> * liste1 = new Hashage<int,int>();
	//Aliste<string,int> * liste2 = new AListe<string,int>();
	//Aliste<int,string>  * liste2 = new AListe<int,string>();
	
	liste1->associer(1,3);
	liste1->associer(2,3);
	liste1->associer(3,1);
	liste1->associer(4,5);
	liste1->associer(51,74);
	liste1->associer(102,56);
	liste1->associer(101,45);
	liste1->associer(23,50);
	liste1->associer(18,45);
	liste1->associer(26,15);
	liste1->associer(30,50);
	liste1->associer(59,78);
	liste1->associer(501,12);
	
	cout<<liste1->valeurAssociee(23)<<endl;
	liste1->associer(23,12);
	cout<<liste1->valeurAssociee(23)<<endl;
	cout<<liste1->valeurAssociee(3)<<endl;
	cout<<liste1->estClef(50)<<endl;
	cout<<liste1->estClef(2)<<endl;
	cout<<liste1->estClef(1)<<endl;
	liste1->dissocier(1);
	cout<<liste1->estClef(1)<<endl;
	
	int N;
	vector<int> ens;
	ens = liste1->trousseau();

	
	std::cout << "[" << std::endl;
	for(std::vector<int>::iterator it=ens.begin(); it!=ens.end(); ++it)
    std::cout << *it << std::endl;
    std::cout << "]" << std::endl;

} 
