#include <cstdlib>
#include <iostream>
#include "anagrafica.h"
using namespace std;

Anagrafica::Anagrafica(char* _nome, char* _n_Telefono){
	nome = _nome;
	n_Telefono = _n_Telefono;
	stato=1;
}

void Anagrafica::put_telefono(char* _n_Telefono){
	n_Telefono = _n_Telefono;
}

char* Anagrafica::get_nome() const{
	return nome;
}
char* Anagrafica::get_n_Telefono() const{
	return n_Telefono;
}

bool Anagrafica::get_stato()const{
	return stato;
}

void Anagrafica::disattiva_stato(){
	stato=0;
}
