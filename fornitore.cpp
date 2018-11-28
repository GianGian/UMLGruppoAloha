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
	os<<"Fornitore con denominazione: "<<f.denominazione<<" e prodotti venduti: "<<f.prodottiVenduti<<endl;
	return os;
}

void Fornitore::aggiungi_servizio(char* _nome, int _durata, int _franchigia, int _costoServizio){
	ser.push_back(Servizio( _nome, _durata, _franchigia, _costoServizio));
}

void Fornitore::togli_servizio(char* _nome, int _durata, int _franchigia, int _costoServizio){
	 list <Servizio>::iterator iter;
	 iter=find(ser.begin(),ser.end(),Servizio( _nome, _durata, _franchigia, _costoServizio));
	 if(iter != ser.end()){
	 	cout<<"Servizio rimosso"<<endl;
	 	ser.remove(*iter);
	 }	
	 else cout<<"Errore servizio non trovato"<<endl;
}

void Fornitore::lista_servizio(){
	list<Servizio>::iterator iter;
	for(iter=ser.begin();iter!=ser.end();++iter){
		cout<<*iter;
	}
}
