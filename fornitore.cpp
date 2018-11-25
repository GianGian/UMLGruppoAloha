#include <cstdlib>
#include <iostream>
#include "fornitore.h"
using namespace std;

///Inizializza fornitore
Fornitore::Fornitore(char* _nome,char* _telefono,char* _denominazione,char* _prodottiVenduti):Anagrafica(_nome,_telefono){
	denominazione=_denominazione;
	prodottiVenduti=_prodottiVenduti;
}


///Ridefinizione operatore == per peremettere la ricerca nella lista
bool Fornitore::operator == (const Fornitore& f){
	if (denominazione==f.denominazione && prodottiVenduti== f.prodottiVenduti && nome==f.nome && n_Telefono==f.n_Telefono){
		return 1;
	}
	return 0;
}

/**
Ridefinizione operatore << per permettere la chiamata tramite cout<<Fornitore
*/
ostream& operator << (ostream & os, Fornitore &f){
	os<<"Fornitore con denominazione: "<<f.denominazione<<" e prodotti venduti: "<<f.prodottiVenduti<<endl;
	return os;
}
