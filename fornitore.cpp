#include <cstdlib>
#include <iostream>
#include "fornitore.h"
using namespace std;

Fornitore::Fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti):Anagrafica(_nome,_telefono){
	denominazione=_denominazione;
	prodottiVenduti=_prodottiVenduti;
}

bool Fornitore:: operator == (const Fornitore& f){
	return denominazione= f.denominazione, prodottiVenduti= f.prodottiVenduti, nome= f.nome, n_Telefono= f.n_Telefono;
}

ostream &operator << (ostream & os, Fornitore &f){
	os << "Fornitore con denominazione: " << f.denominazione << " e prodotti venduti: " << f.prodottiVenduti<< endl;
	return os;
}
