#include <cstdlib>
#include <iostream>
#include "privato.h"
using namespace std;

Privato::Privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto):Consumatore(_nome, _telefono, _sconto){
	codiceFiscale = _codiceFiscale;
    cognome = _cognome;
}

void  Privato::stampa() const{
	cout<<get_nome()<<" "<<cognome<<" CF: "<<codiceFiscale<<" TEL: "<<get_n_Telefono()<<" SCONTO: "<<getSconto();
}
