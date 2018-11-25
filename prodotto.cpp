#include <cstdlib>
#include <iostream>
#include "prodotto.h"
using namespace std;
int Prodotto:: last_barcode = 0;

Prodotto::Prodotto(int _quantita, char* _colore, char* _marca, double _costo){
	quantita = _quantita;
	colore = _colore;
	marca = _marca;
	costo = _costo;
	barcode = last_barcode;
	last_barcode++;
}

Prodotto::getBarcode(){
	return barcode;
}

ostream & operator<<(ostream &os, Prodotto &p){
	os<<p.marca<<" "<<p.colore<<" PREZZO: "<<p.costo<< " QUANTITA': "<< p.quantita <<" BARCODE: "<<p.barcode;
	return os;
}
