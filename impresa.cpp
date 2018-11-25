#include <cstdlib>
#include <iostream>
#include "impresa.h"
using namespace std;

Impresa::Impresa(char* _nome, char* _telefono, char* _piva, int _sconto):Consumatore(_nome, _telefono, _sconto){
	piva = _piva;
}

ostream& operator<< (ostream &os, Impresa &i){
	os<<i.nome<<" PIVA: "<<i.piva<<" TEL: "<<i.n_Telefono<<" SCONTO: "<<i.getSconto();
	return os;
}
