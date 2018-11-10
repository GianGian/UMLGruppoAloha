#include <cstdlib>
#include <iostream>
#include "prodotto.h"
using namespace std;

int Prodotto::barcode=0;

Prodotto::Prodotto(int _quantita, char* _colore, char* _marca, double _costo, Servizio* _s){
    quantita=_quantita;
    colore=_colore;
    marca=_marca;
    costo=_costo;
    barcode++;
    s = _s;
    cout<<"Creato prodotto "<<marca<<" "<<colore<<endl;
    if (s != NULL) cout<< "Aggiunto servizio a prodotto"<<endl;
    else cout<<"Senza nessun servizio"<<endl;
    cout<<"barcode"<<barcode<<endl; //solo di debug
    
}

Prodotto::~Prodotto(){
    cout<<"Distrutto prodotto"<<marca<<endl;
}

void Prodotto::stampa()const{
    cout<<quantita<<" "<<colore<<" "<<marca<<" "<<costo<<" "<<barcode<<endl;
}
