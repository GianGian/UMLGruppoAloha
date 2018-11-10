//aggiunto attributo pagamento e modificato costruttore
#ifndef __ORDINEVENDITA_H__
#define __ORDINEVENDITA_H__
#include <iostream>
#include "ordine.h"
#include "metodoDiPagamento.h"
using namespace std;

class OrdineVendita: public Ordine{
private:
    char* via;
    MetodoDiPagamento *pagamento; //aggiunto
  
public:
    OrdineVendita (int _quantita,char* _via, MetodoDiPagamento* _pagamento);
    ~OrdineVendita();
};
#endif
