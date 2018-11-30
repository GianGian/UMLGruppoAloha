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
	if (q>(p->get_quantita())){
		cout<<"Impossibile inserire il prodotto, quantita presente in magazzino: "<<p->get_quantita()<<endl;
	}else{
		prodotto.insert(pair<int, Prodotto*> (q, p));
	}
	
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

int OrdineVendita::conferma_ordine(){
	multimap<int, Prodotto*>::iterator iter;
	int totale = 0;
	if(prodotto.empty() == 1) return 0;
	else{
		for(iter = prodotto.begin(); iter != prodotto.end(); ++iter){
			totale+=(iter->second->getPrezzo(get_data())*iter->first);
			iter->second->cambia_quantita(-iter->first);
		}
		totale+=pagamento->get_commissione();
		totale+=s->get_costo();
		totale-=(totale*(c->getSconto()))/100;
		return totale;
	}
}
ostream& operator<< (ostream& os, const OrdineVendita &o){
	if(o.prodotto.empty()==1){
		cout<<"Ordine vuoto"<<endl;
	}else{
	os<<"Ordine vendita n."<<o.get_n_ordine()<<" del "<<o.get_data()<<" di ";
	o.c->stampa();
	os<<" da consegnare in via: "<<o.via<<" con pagamento: "<<*o.pagamento;
	multimap<int,Prodotto*>::const_iterator it;
	os<<endl<<"Prodotti associati: ";
	for(it=o.prodotto.begin(); it!=o.prodotto.end(); ++it){
		os<<" -n."<<it->first<<" "<<*it->second<<endl;
	}
	if(o.s!= NULL){
		os<<"Servizio associato: [ ";
		os<<*o.s<< " ]";
	}
	if(o.get_fattura()!= NULL){
		os<<endl<<"Fattura associata: "<<*o.get_fattura();
	}
	os<<endl;
}
	
	return os;
}
