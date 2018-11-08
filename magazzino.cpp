#include <cstdlib>
#include <iostream>
#include "magazzino.h"
using namespace std;

Magazzino::Magazzino(char* _via, char* _denominazione, double _fondoCassa){
    via=_via;
    denominazione=_denominazione;
    fondoCassa=_fondoCassa;
    p=NULL;
    cout<<"Creato magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;   
}

Magazzino::~Magazzino(){
    if(p!=NULL){
    delete p;
    }
    cout<<"Distrutto magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;   
}

void Magazzino::stampa()const{
    cout<<"Magazzino "<<denominazione<<" in via "<<via<<" con fondocassa "<<fondoCassa<<endl;
}

void Magazzino::inserisci_prodotto(int _quantita, char* _colore, char* _marca, double _costo){
    if(p==NULL){//se avessi più prodotti dovrei fare una lista?
    p= new Prodotto(_quantita,_colore,_marca, _costo);
}
}
