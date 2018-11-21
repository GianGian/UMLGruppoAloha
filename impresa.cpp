#include <cstdlib>
#include <iostream>
#include "impresa.h"
using namespace std;

Impresa::Impresa(char* _nome, char* _telefono, char* _piva, int _sconto):Consumatore(_nome, _telefono, _sconto){
	piva = _piva;
}
