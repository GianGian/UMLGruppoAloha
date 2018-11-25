#include "fattura.h"
#include <iostream>
using namespace std;

int Fattura::last_n_Fattura=0;

/*
*
*Crea un'istanza della classe fattura, il numero della fattura viene auto incrementato.
*
*/

Fattura::Fattura(int _totale, bool _vendita){
   last_n_Fattura++;
   n_Fattura = last_n_Fattura;
   totale = _totale;
   vendita = _vendita;
   //cout<<"Creata fattura numero: "<<n_Fattura<< " totale "<<totale<<endl;
}

Fattura::~Fattura(){
	//cout<<"Distrutta fattura"<<endl;
}

int Fattura::get_n_Fattura(){
	return n_Fattura;
}

ostream& operator<< (ostream &os, Fattura &f){
	os<<"Fattura di ";
	if(f.vendita == 1) os<<"vendita ";
	else os<<"acquisto ";
	os<<"n. "<<f.n_Fattura<<" totale: "<<f.totale;
	return os;
}
