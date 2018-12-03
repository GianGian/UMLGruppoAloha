#include <cstdlib>
#include <iostream>
#include "fornitore.h"
using namespace std;

///Inizializza fornitore
Fornitore::Fornitore(char* _nome,char* _telefono,char* _denominazione,char* _prodottiVenduti):Anagrafica(_nome,_telefono){
	denominazione=_denominazione;
	prodottiVenduti=_prodottiVenduti;
}

/**
Ridefinizione operatore << per permettere la chiamata tramite cout<<Fornitore
*/
ostream& operator << (ostream & os, const Fornitore &f){
	os<<"Fornitore con denominazione: "<<f.denominazione<<" e prodotti venduti: "<<f.prodottiVenduti<<" servizi associati: ";
	map<char*,Servizio>::const_iterator iter;
	if(f.ser.empty()){
		os<<" nessun servizio associato.";
	}else{
	for(iter=f.ser.begin();iter!=f.ser.end();++iter){
		 os<<"["<<(iter->second)<<"] ";
	}
}
	//os<<endl;
	return os;
}

void Fornitore::aggiungi_servizio(char* _nome, int _durata, int _franchigia, int _costoServizio){
	  ser.insert(pair<char*, Servizio> (_nome,Servizio(_nome, _durata, _franchigia, _costoServizio)));
}

void Fornitore::togli_servizio(char* _nome){
	map<char*, Servizio>::iterator iter;
	iter = ser.find(_nome);
	if(iter != ser.end()){
		ser.erase(iter);
		cout<<"Servizio rimosso"<<endl;
	}
	else cout<<"Servizio non trovato"<<endl;

}

Servizio* Fornitore::get_servizio(char* _nome) {
	map <char*,Servizio>::iterator iter;
	iter = ser.find(_nome);
	if(iter!=ser.end()){
		return &iter->second;
	}
	return NULL;
}

void Fornitore::lista_servizio(){
	map<char*,Servizio>::iterator iter;
	for(iter=ser.begin();iter!=ser.end();++iter){
		if(&iter->second == NULL){
			cout<<" nessun servizio associato."<<endl;
		}else cout<<iter->second;
	}
}

