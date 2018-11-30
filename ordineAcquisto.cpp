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
		os<<"- n."<<iter->first<<" "<<*iter->second<<endl;
	}
	if(oa.get_fattura()!=NULL){
		os<<endl<<"Fattura associata: "<<*oa.get_fattura();
	}
	return os;
}

int OrdineAcquisto::conferma_ordine(){
	multimap<int, Prodotto*>::iterator iter;
	int totale = 0;
	if(prodotto.empty() == 1) return 0;
	else{
		for(iter = prodotto.begin(); iter != prodotto.end(); ++iter){
			totale+=(iter->second->getPrezzo(get_data())*iter->first);
			iter->second->cambia_quantita(iter->first);
		}
		return totale;
	}
}
