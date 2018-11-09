#ifndef __FORNITORE_H__
#define __FORNITORE_H__
#include <iostream>
#include "anagrafica.h"
using namespace std;

class Fornitore:public Anagrafica{
private:
    char* denominazione;
    int prodottiVenduti;

public:
    Fornitore(char* _nome,char* _n_Telefono,char* _denominazione,int _prodottiVenduti);
    ~Fornitore();
};
#endif
