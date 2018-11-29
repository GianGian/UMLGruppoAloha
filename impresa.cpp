#include <cstdlib>
#include <iostream>
#include "impresa.h"
using namespace std;

Impresa::Impresa(char* _nome, char* _telefono, char* _piva, int _sconto):Consumatore(_nome, _telefono, _sconto){
	piva = _piva;
}

/*ostream& operator<< (ostream &os, Impresa &i){
	os<<i.get_nome()<<" PIVA: "<<i.piva<<" TEL: "<<i.get_n_Telefono()<<" SCONTO: "<<i.getSconto();
	return os;
}*/

void Impresa:: stampa()const {
	//cout << "impresa:" << piva;
	cout<<get_nome()<<" PIVA: "<<piva<<" TEL: "<<get_n_Telefono()<<" SCONTO: "<<getSconto();
}
