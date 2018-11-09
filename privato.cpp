#include <cstdlib>
#include <iostream>
#include "privato.h"
using namespace std;

Privato::Privato(char* _nome,char* _n_Telefono,int _sconto,char* _codiceFiscale,char* _cognome):Consumatore(_nome,_n_Telefono,_sconto){
    codiceFiscale=_codiceFiscale;
    cognome=_cognome;
    cout<<"Creato privato "<<cognome<<endl;
}
Privato::~Privato(){
    cout<<"Distrutto privato "<<cognome<<endl;
}
