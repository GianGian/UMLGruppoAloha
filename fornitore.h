#ifndef __FORNITORE_H__
#define __FORNITORE_H__
#include <iostream>
#include "anagrafica.h"
using namespace std;

class Fornitore:public Anagrafica{
private:
    char* denominazione;
    char* prodottiVenduti;

public:
	Fornitore(char* _nome,char*_telefono,char* _denominazione,char* _prodottiVenduti);
};
#endif
