#include <cstdlib>
#include <iostream>
#include "consumatore.h"
using namespace std;

Consumatore::Consumatore(char* nome, char* telefono, int _sconto):Anagrafica(nome, telefono){
   sconto = _sconto;
}

int Consumatore::getSconto(){
	return sconto;
}

void Consumatore::putSconto(int s){
	sconto = s;
}
