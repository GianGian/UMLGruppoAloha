#include <cstdlib>
#include <iostream>
#include "ordineAcquisto.h"
using namespace std;

OrdineAcquisto::OrdineAcquisto (int _quantita,char* _ID_Articolo, int _costoUnitario): Ordine(_quantita){
    ID_Articolo=_ID_Articolo;
    costoUnitario=_costoUnitario;
    cout<<"Creato ordine di acquisto con ID "<<ID_Articolo<<endl;
}
OrdineAcquisto::~OrdineAcquisto(){
    cout<<"Distrutto ordine di acquisto con ID "<<ID_Articolo<<endl;
}
