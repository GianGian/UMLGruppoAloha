#include <cstdlib>
#include <iostream>
#include "ordine.h"
using namespace std;

int Ordine::last_n_ordine=0;

Ordine::Ordine(int _matricola){
	matricola = _matricola;
	n_ordine = last_n_ordine;
	fattura = NULL;
	last_n_ordine++;
}

void Ordine::add_fattura(Fattura* f){
	fattura = f;
}
