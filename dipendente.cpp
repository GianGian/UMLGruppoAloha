#include <cstdlib>
#include <iostream>
#include "dipendente.h"
using namespace std;

Dipendente::Dipendente(char* _nome,char* _n_Telefono,char* _ruolo,int _matricola):Anagrafica(_nome,_n_Telefono){
    ruolo=_ruolo;
    matricola=_matricola;
    cout<<"Creato dipendente con matricola"<<matricola<<endl;
}
Dipendente::~Dipendente(){
    cout<<"Distrutto dipendente con matricola "<<matricola<<endl;
}

int Dipendente::get_matricola()const{
    return matricola;
}
