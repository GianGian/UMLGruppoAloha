//aggiunto attributo pagamento e modificato costruttore
#ifndef __ORDINEVENDITA_H__
#define __ORDINEVENDITA_H__
#include <iostream>
#include "ordine.h"
#include "metodoDiPagamento.h"
#include "servizio.h"
#include "list"
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
    list<Prodotto> pro;
public:
	OrdineVendita(char* _via, int matricola);
	void add_prodotto(Prodotto p);
	void add_servizio(Servizio &_s);
	void add_consumatore(Consumatore &_c);
	void add_metodo_di_pagamento( MetodoDiPagamento &p);
	friend ostream& operator<< (ostream& os, OrdineVendita &o);
};

ostream& operator<< (ostream& os, OrdineVendita &o);
#endif
