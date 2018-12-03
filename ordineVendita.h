//aggiunto attributo pagamento e modificato costruttore
#ifndef __ORDINEVENDITA_H__
#define __ORDINEVENDITA_H__
#include <iostream>
#include "ordine.h"
#include "metodoDiPagamento.h"
#include "servizio.h"
#include "map"
#include "algorithm"
#include "prodotto.h"
#include "consumatore.h"
using namespace std;

class OrdineVendita: public Ordine{
private:
    char* via;
    MetodoDiPagamento *pagamento;
    Servizio *s;
    Consumatore *c;
    multimap<int,Prodotto*> prodotto;
public:
	OrdineVendita(char* _via, int matricola, int data, Consumatore& _c);
	void add_prodotto(int q, Prodotto* p);
	void add_servizio(Servizio &_s);
	void add_metodo_di_pagamento(MetodoDiPagamento *p);
	friend ostream& operator<< (ostream& os, const OrdineVendita &o);
	int conferma_ordine();
};

ostream& operator<< (ostream& os, const OrdineVendita &o);
#endif
