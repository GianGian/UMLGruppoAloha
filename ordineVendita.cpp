#include <cstdlib>
#include <iostream>
#include "ordineVendita.h"
using namespace std;

OrdineVendita::OrdineVendita(char* _via, int _matricola, int data, Consumatore& _c):Ordine(_matricola,data){
	via = _via;
	pagamento = NULL;
	c = &_c;
	if(c == NULL){
		cout<<"Errore, consumatore non trovato"<<endl;
	}
	s = NULL;
}

void OrdineVendita::add_prodotto(int q,Prodotto* p){
	if(p == NULL){
			cout<<"impossibile aggiungere il prodotto all'ordine. E' inesistente?"<<endl;
			}else{
	if (q>(p->get_quantita())){
		cout<<"Impossibile inserire il prodotto, quantita presente in magazzino: "<<p->get_quantita()<<endl;
		}else{
			bool trovato = 0; //mi serve per capire se ho già trovato nel for o meno l'elemento
	        multimap<int, Prodotto*>::iterator it;
	        for(it=prodotto.begin(); it != prodotto.end(); ++it){
	        	if(it->second == p){ //se trovo già inserito il prodotto
	        		trovato = 1;
	        		int qtemp = it->first;
	        		prodotto.erase(it);	
	        		qtemp+= q;
					if(qtemp>p->get_quantita()){ //e la nuova quantita richiesta è troppo elevata
						cout<<"Impossibile inserire il prodotto, quantita presente in magazzino: "<<p->get_quantita()<<endl;
						prodotto.insert(pair<int, Prodotto*> ((qtemp-q), p));
					}else{
						prodotto.insert(pair<int, Prodotto*> (qtemp, p));
					} 
				}
			}
			if(trovato == 0){ //faccio questo inserimento solo se non ho fatto prima tramite il for
				prodotto.insert(pair<int, Prodotto*> (q, p));
			}
			
		}
		
	}
	
}

void OrdineVendita::add_servizio(Servizio &_s){
	if(&_s == NULL){
		cout<<"Servizio non trovato"<<endl;
	}
	s = &_s;	
}


bool OrdineVendita::add_metodo_di_pagamento(MetodoDiPagamento *p){
	if((p->get_massimale())>sub_totale()){
		pagamento = p;
		return 1;
	}
	return 0;
	
}

int OrdineVendita::conferma_ordine(){
	multimap<int, Prodotto*>::iterator iter;
	int totale = 0;
	if(prodotto.empty() == 1|| pagamento == NULL) return -1;
	else{
		for(iter = prodotto.begin(); iter != prodotto.end(); ++iter){
			totale+=(iter->second->getPrezzo(get_data())*iter->first);
			iter->second->cambia_quantita(-iter->first);
			if((s!=NULL)&&(iter->second->get_servizio()==1)){
			totale+=(s->get_costo() * iter->first);
			}	
		}
		totale+=pagamento->get_commissione();
		
		totale-=(totale*(c->getSconto()))/100;
		return totale;
	}
}

int OrdineVendita::sub_totale(){
	
	multimap<int, Prodotto*>::iterator iter;
	int totale = 0;
	if(prodotto.empty() == 1) return 0;
	else{
		for(iter = prodotto.begin(); iter != prodotto.end(); ++iter){
			totale+=(iter->second->getPrezzo(get_data())*iter->first);
			if((s!=NULL)&&(iter->second->get_servizio()==1)){
			totale+=(s->get_costo() * iter->first);
			}	
		}		
		totale-=(totale*(c->getSconto()))/100;
		return totale;
	}
	
}

ostream& operator<< (ostream& os, const OrdineVendita &o){
	if(o.prodotto.empty()==1){
		cout<<"Ordine vuoto"<<endl;
	}else{
	os<<"Ordine vendita n."<<o.get_n_ordine()<<" del "<<o.get_data()<<" creato da: "<<o.get_matricola()<<" di ";
	o.c->stampa();
	os<<" da consegnare in via: "<<o.via<<" con pagamento: "<<*o.pagamento;
	multimap<int,Prodotto*>::const_iterator it;
	os<<endl<<"Prodotti associati:"<<endl;
	for(it=o.prodotto.begin(); it!=o.prodotto.end(); ++it){
		os<<" -n."<<it->first<<" "<<*it->second;
		if(o.s!= NULL && it->second->get_servizio()==1){
		os<<" servizio associato: [ ";
		os<<*o.s<< " ]";
	} else{
		os<<" nessun servizio associato.";
	}
	cout<<endl;
	}
	
	if(o.get_fattura()!= NULL){
		os<<endl<<"Fattura associata: "<<*o.get_fattura();
	}
	os<<endl;
}
	
	return os;
}
