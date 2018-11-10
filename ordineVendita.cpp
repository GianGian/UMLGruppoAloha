#include <cstdlib>
#include <iostream>
#include "ordineVendita.h"
using namespace std;

OrdineVendita::OrdineVendita (int _quantita,char* _via, MetodoDiPagamento* _pagamento): Ordine(_quantita){
    via=_via;
    pagamento= _pagamento;
    cout<<"Creato ordine di vendita in via "<< via << " e con metodo di pagamento "<< pagamento->get_nome() <<endl;
}
OrdineVendita::~OrdineVendita(){
    cout<<"Distrutto ordine di vendita in via "<<via << " e con metodo di pagamento "<< pagamento->get_nome() <<endl;
}
