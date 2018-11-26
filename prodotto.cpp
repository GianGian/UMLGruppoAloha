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
}

Prodotto::getBarcode(){
	return barcode;
}

ostream & operator<<(ostream &os, Prodotto &p){
	os<<p.marca<<" "<<p.tipologia<< " "<<p.colore<< " QUANTITA': "<< p.quantita <<" BARCODE: "<<p.barcode;
	return os;
}
