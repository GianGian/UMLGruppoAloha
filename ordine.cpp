#include <cstdlib>
#include <iostream>
#include "ordine.h"

using namespace std;

int Ordine::last_n_ordine=0;

Ordine::Ordine(int _matricola, int data):d(data){
	matricola = _matricola;
	n_ordine = last_n_ordine;
	fattura = NULL;
	last_n_ordine++;
}

void Ordine::add_fattura(Fattura* f){
	fattura = f;
}

int Ordine::get_matricola(){
	return matricola;
}

int Ordine::get_n_ordine()const{
	return n_ordine;		
}

int Ordine::get_data()const{
	return d.data;
}
