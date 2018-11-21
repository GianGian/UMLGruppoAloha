#include <cstdlib>
#include <iostream>
#include "fornitore.h"
using namespace std;

Fornitore::Fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti):Anagrafica(_nome,_telefono){
	denominazione=_denominazione;
	prodottiVenduti=_prodottiVenduti;
}
