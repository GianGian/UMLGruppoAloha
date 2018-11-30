#include <cstdlib>
#include <iostream>
#include "ordineAcquisto.h"
#include "prodotto.h"
using namespace std;

OrdineAcquisto::OrdineAcquisto(int matricola, int _d, Fornitore *_f):Ordine(matricola, _d){
	f = _f;
}

void OrdineAcquisto::addProdotto(int prezzo, int quantita, Prodotto *p){
	p->addCosto_acquisto(prezzo, get_data());
	prodotto.insert(pair<int, Prodotto*> (quantita, p));
	
}

ostream& operator<< (ostream& os, OrdineAcquisto &oa){
	os<<"Ordine acquisto"<<" n."<<oa.get_n_ordine()<<" del " <<oa.get_data()<<" fatto da "<<oa.get_matricola()<<" con prodotti: ";
	multimap<int, Prodotto*>::iterator iter;
	for(iter = oa.prodotto.begin(); iter != oa.prodotto.end(); ++iter){
		os<<"-"<<*iter->second<<endl;
	}
	return os;
}
