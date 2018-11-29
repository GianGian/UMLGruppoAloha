#include <cstdlib>
#include <iostream>
#include "privato.h"
using namespace std;

Privato::Privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto):Consumatore(_nome, _telefono, _sconto){
	codiceFiscale = _codiceFiscale;
    cognome = _cognome;
    //imp=0;
    //pri=1;
}

ostream& operator<<(ostream &os, Privato &p){
	os<<p.get_nome()<<" "<<p.cognome<<" CF: "<<p.codiceFiscale<<" TEL: "<<p.get_n_Telefono()<<" SCONTO: "<<p.getSconto();
	return os;
}

/*void Impresa:: stampa() const{
	cout << "privato:" << codiceFiscale<< endl;
}*/
