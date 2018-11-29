#include <cstdlib>
#include <iostream>
#include "consumatore.h"
using namespace std;

Consumatore::Consumatore(char* nome, char* telefono, int _sconto):Anagrafica(nome, telefono){
   sconto = _sconto;
}

int Consumatore::getSconto()const{
	return sconto;
}

void Consumatore::putSconto(int s){
	sconto = s;
}

/*ostream& operator<< (ostream &os, const Consumatore &c){
	os<<c.get_nome()<<" "<<c.get_n_Telefono();
}*/

void Consumatore::stampa()const{
	cout << "sconto:" << sconto << endl;
}
