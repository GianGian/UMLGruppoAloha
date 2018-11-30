#ifndef __ORDINEACQUISTO_H__
#define __ORDINEACQUISTO_H__
#include <iostream>
#include "ordine.h"
#include "prodotto.h"
#include "fornitore.h"
#include "data.h"
#include <map>
#include <algorithm>
using namespace std;

class OrdineAcquisto: public Ordine{
private:
	multimap<int, Prodotto*> prodotto;
	Fornitore *f;
public:
	OrdineAcquisto(int matricola,int _d, Fornitore *_f);
	void addProdotto(int prezzo, int quantita, Prodotto *p);
	friend ostream& operator<< (ostream& os, OrdineAcquisto &oa);
	int conferma_ordine();
};

ostream& operator<< (ostream& os, OrdineAcquisto &oa);
#endif
