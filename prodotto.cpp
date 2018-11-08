#include <cstdlib>
#include <iostream>
#include "prodotto.h"
using namespace std;

int Prodotto::barcode=0;
Prodotto::Prodotto(int _quantita, char* _colore, char* _marca, double _costo){
    quantita=_quantita;
    colore=_colore;
    marca=_marca;
    costo=_costo;
    barcode++;
    cout<<"Creato prodotto"<<marca<<endl;
    cout<<"barcode"<<barcode<<endl; //solo di debug
}

Prodotto::~Prodotto(){
    cout<<"Distrutto prodotto"<<marca<<endl;
}

void Prodotto::stampa()const{
    cout<<quantita<<" "<<colore<<" "<<marca<<" "<<costo<<" "<<barcode<<endl;
}
