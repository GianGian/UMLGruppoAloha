#include <cstdlib>
#include <iostream>
#include "prodotto.h"
using namespace std;
int Prodotto:: last_barcode = 0;

Prodotto::Prodotto(int _quantita, char* _colore, char* _marca, int _costo, int _data,char* _tipologia){
	quantita = _quantita;
	colore = _colore;
	marca = _marca;
	Data d(_data);
	prezzo.insert(pair<Data, int> (d, _costo));
	barcode = last_barcode;
	tipologia= _tipologia;
	last_barcode++;
	stato=1;
}

Prodotto::getBarcode(){
	return barcode;
}

void Prodotto::addCosto(int _costo, int _data){
	if(prezzo.find(_data)==prezzo.end()){
		prezzo.insert(pair<Data,int> (Data(_data), _costo));
		cout<<"prezzo inserito"<<endl;
	}
	else{
		cout<<"Prezzo per questa data gia' inserito!"<<endl;
	}
}

int Prodotto::getPrezzo(int data){
	map<Data,int>::reverse_iterator it;
	bool trovato=0;
	for(it = prezzo.rbegin(); it!=prezzo.rend(); ++it){
	   if(it->first.data<=data){
	   		trovato = 1;
	   		it;
	   		return it->second;
	   }
	}
	cout<<"Prezzo non trovato"<<endl;
	return -1; ///<Ritorno -1 che non è plausibile, quindi so che il prezzo non esiste.
}

void Prodotto::addCosto_acquisto(int _costo, int _data){
	if(prezzo.find(_data)==prezzo.end()){
		prezzo.insert(pair<Data,int> (Data(_data), _costo));
		cout<<"prezzo inserito"<<endl;
	}
	else{
		cout<<"Prezzo per questa data gia' inserito!"<<endl;
	}
}

int Prodotto::getPrezzo_acquisto(int data){
	map<Data,int>::reverse_iterator it;
	bool trovato=0;
	for(it = prezzo.rbegin(); it!=prezzo.rend(); ++it){
	   if(it->first.data<=data){
	   		trovato = 1;
	   		it;
	   		return it->second;
	   }
	}
	cout<<"Prezzo non trovato"<<endl;
	return -1; ///<Ritorno -1 che non è plausibile, quindi so che il prezzo non esiste.
}

ostream & operator<<(ostream &os, const Prodotto &p){
	map<Data,int>::const_iterator it;
	os<<p.marca<<" "<<p.tipologia<< " "<<p.colore<< " QUANTITA': "<< p.quantita <<" BARCODE: "<<p.barcode<< " PREZZO: ";
	for(it=p.prezzo.begin();it!=p.prezzo.end(); it++){
		os<<it->second<<" ["<<it->first.data<<"] ";
	}
	return os;
}

bool Prodotto::get_stato(){
	return stato;
}
void Prodotto::disattiva_stato(){
	stato=0;
}
