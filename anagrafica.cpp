#include <cstdlib>
#include <iostream>
#include "anagrafica.h"
using namespace std;

Anagrafica::Anagrafica(char* _nome, char* _n_Telefono){
	nome = _nome;
	n_Telefono = _n_Telefono;
}

void Anagrafica::put_telefono(char* _n_Telefono){
	n_Telefono = _n_Telefono;
}

