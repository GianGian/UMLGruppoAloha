#include <cstdlib>
#include <iostream>
#include "anagrafica.h"
using namespace std;

Anagrafica::Anagrafica(char* _nome,char* _n_Telefono){
    nome=_nome;
    n_Telefono=_n_Telefono;
    cout<<"Creata anagrafica di "<<nome<<endl;
}

Anagrafica::~Anagrafica(){
    cout<<"Distrutta anagrafica di "<<nome<<endl;
}
