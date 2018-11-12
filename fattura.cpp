#include "fattura.h"
#include <iostream>
using namespace std;

int Fattura::n_Fattura=0;
Fattura::Fattura(int _totale, bool _vendita){
   n_Fattura++;
   totale = _totale;
   vendita = _vendita;
   cout<<"Creata fattura numero: "<<n_Fattura<< " totale "<<totale<<endl;
}

Fattura::~Fattura(){
	cout<<"Distrutta fattura"<<endl;
}
