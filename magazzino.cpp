#include <cstdlib>
#include <iostream>
#include "magazzino.h"
using namespace std;

Magazzino::Magazzino(char* _via, char* _denominazione, double _fondoCassa){
    via=_via;
    denominazione=_denominazione;
    fondoCassa=_fondoCassa;
    cout<<"Creato magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;
    
}

void Magazzino::stampa()const{
    cout<<"Magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;
}
