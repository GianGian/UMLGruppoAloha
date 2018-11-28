#include <cstdlib>
#include <iostream>
#include "ordineVendita.h"
using namespace std;

OrdineVendita::OrdineVendita(char* _via, int _matricola):Ordine(_matricola){
	via = _via;
	pagamento = NULL;
	c = NULL;
}

void OrdineVendita::add_prodotto(Prodotto p){
	pro.push_back(p);
}

void OrdineVendita::add_servizio(Servizio &_s){
	s = &_s;	
}

void OrdineVendita::add_consumatore(Consumatore &_c){
	c = &_c;
}

void OrdineVendita::add_metodo_di_pagamento( MetodoDiPagamento &p){
	pagamento = &p;
}

ostream& operator<< (ostream& os, OrdineVendita &o){
	os<<"Ordine vendita di "<<*o.c<<" da consegnare in via: "<<o.via<<" con pagamento: "<<*o.pagamento;
	os<<endl;
	return os;
}
