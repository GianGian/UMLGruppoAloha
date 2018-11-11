#include <cstdlib>
#include <iostream>
#include "ordineVendita.h"
using namespace std;

OrdineVendita::OrdineVendita (int _quantita,char* _via, MetodoDiPagamento* _pagamento,Servizio *_s): Ordine(_quantita){
    via=_via;
    pagamento= _pagamento;
    s=_s;
    if (s != NULL) cout<< "Aggiunto servizio a prodotto"<<endl;
    else cout<<"Senza nessun servizio"<<endl;
    cout<<"Creato ordine di vendita in via "<< via << " e con metodo di pagamento "<< pagamento->get_nome() <<endl;
}
OrdineVendita::~OrdineVendita(){
    cout<<"Distrutto ordine di vendita in via "<<via << " e con metodo di pagamento "<< pagamento->get_nome() <<endl;
}
