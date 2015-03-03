# options de compilation
CFLAGS = -g -std=c++11 -pedantic -Wfatal-errors -Wconversion -Wredundant-decls -Wshadow -Wall -Wextra
# liste des fichiers implémentant une Table Associative
TA = mappe.hpp mappe.tpp aliste.hpp aliste.tpp htable.hpp htable.tpp

all : magasin_test.exe TA_test.exe

%.o : %.cpp %.hpp
	g++ $(CFLAGS) -c -o $@ $< 

TA_test.exe : TA_test.cpp $(TA)
	g++ $(CFLAGS) TA_test.cpp -o TA_test.exe

magasin_test.exe : magasin_test.cpp magasin.hpp magasin.tpp $(TA) produit.o
	g++ $(CFLAGS) magasin_test.cpp produit.o -o magasin_test.exe

clean :
	@rm *.o *.exe

.PHONY: all clean
