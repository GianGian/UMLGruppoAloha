#include <cstdlib>
#include <iostream>
#include "ordineVendita.h"
using namespace std;

OrdineVendita::OrdineVendita(char* _via, int _matricola, int data):Ordine(_matricola,data){
	via = _via;
	pagamento = NULL;
	c = NULL;
	s = NULL;
}

void OrdineVendita::add_prodotto(int q,Prodotto* p){
	pro.insert(pair<int, Prodotto*> (q, p));
}

void OrdineVendita::add_servizio(Servizio &_s){
	s = &_s;	
}

void OrdineVendita::add_consumatore(Consumatore &_c){
	c = &_c;
}

void OrdineVendita::add_metodo_di_pagamento(MetodoDiPagamento *p){
	pagamento = p;
}


ostream& operator<< (ostream& os, const OrdineVendita &o){
	os<<"Ordine vendita n."<<o.get_n_ordine()<<" del "<<o.get_data()<<" di ";
	o.c->stampa();
	os<<" da consegnare in via: "<<o.via<<" con pagamento: "<<*o.pagamento;
	multimap<int,Prodotto*>::const_iterator it;
	os<<endl<<"Prodotti associati: ";
	for(it=o.pro.begin(); it!=o.pro.end(); ++it){
		os<<" -n."<<it->first<<" "<<*it->second<<endl;
	}
	if(o.s!= NULL){
		os<<"Servizio associato: [ ";
		os<<*o.s<< " ]";
	}
	
	os<<endl;
	return os;
}
