#include <cstdlib>
#include <iostream>
#include "fornitore.h"
using namespace std;

///Inizializza fornitore
Fornitore::Fornitore(char* _nome,char* _telefono,char* _denominazione,char* _prodottiVenduti):Anagrafica(_nome,_telefono){
	denominazione=_denominazione;
	prodottiVenduti=_prodottiVenduti;
}


///Ridefinizione operatore == per peremettere la ricerca nella lista
bool Fornitore::operator < (const Fornitore& f) const{
	if (denominazione<f.denominazione){
		return 1;
	}
	return 0;
}

char* Fornitore::get_denominazione()const{
	return denominazione;
}

char* Fornitore::get_prodottiVenduti()const{
	return prodottiVenduti;
}
/**
Ridefinizione operatore << per permettere la chiamata tramite cout<<Fornitore
*/
ostream& operator << (ostream & os, const Fornitore &f){
	os<<"Fornitore con denominazione: "<<f.denominazione<<" e prodotti venduti: "<<f.prodottiVenduti<<" servizi associati: ";
	set<Servizio>::iterator iter;
	for(iter=f.ser.begin();iter!=f.ser.end();++iter){
		os<<"["<<*iter<<"] ";
	}
	cout<<endl;
	return os;
}

void Fornitore::aggiungi_servizio(char* _nome, int _durata, int _franchigia, int _costoServizio){
	ser.insert(Servizio( _nome, _durata, _franchigia, _costoServizio));
}

void Fornitore::togli_servizio(char* _nome){
	set <Servizio>::iterator iter;
	iter = get_servizio(_nome);
	if(iter != ser.end()){
		ser.erase(iter);
		cout<<"Servizio rimosso"<<endl;
	}
	else cout<<"Servizio non trovato"<<endl;

}

set<Servizio>::iterator Fornitore::get_servizio(const char* _nome)const {
	set <Servizio>::iterator iter;
	for(iter=ser.begin(); iter!=ser.end();++iter){
		if(iter->get_nome() == _nome) return iter;
	}
    return ser.end();
}
void Fornitore::lista_servizio(){
	set<Servizio>::iterator iter;
	for(iter=ser.begin();iter!=ser.end();++iter){
		cout<<*iter;
	}
}
