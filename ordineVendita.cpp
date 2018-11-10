#include <cstdlib>
#include <iostream>
#include "ordineVendita.h"
using namespace std;

OrdineVendita::OrdineVendita (int _quantita,char* _via): Ordine(_quantita){
    via=_via;
    cout<<"Creato ordine di vendita in via "<<via<<endl;
}
OrdineVendita::~OrdineVendita(){
    cout<<"Distrutto ordine di vendita in via "<<via<<endl;
}
