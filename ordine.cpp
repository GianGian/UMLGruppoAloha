#include <cstdlib>
#include <iostream>
#include "ordine.h"
using namespace std;

int Ordine::n_ordine=0;

Ordine::Ordine (int _quantita){
    quantita=quantita;
    n_ordine++;
    cout<<"Creato ordine numero "<<n_ordine<<endl;
}

Ordine::~Ordine(){
    cout<<"Distrutto ordine numero "<<n_ordine<<endl;
}
