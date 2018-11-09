#include <cstdlib>
#include <iostream>
#include "fornitore.h"
using namespace std;

Fornitore::Fornitore(char* _nome,char* _n_Telefono,char* _denominazione,int _prodottiVenduti):Anagrafica(_nome,_n_Telefono){
    denominazione=_denominazione;
    prodottiVenduti=_prodottiVenduti;
    cout<<"Creato fornitore "<<denominazione<<endl;
}
Fornitore::~Fornitore(){
    cout<<"Distrutto fornitore "<<denominazione<<endl;
}
