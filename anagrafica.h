#ifndef __ANAGRAFICA_H__
#define __ANAGRAFICA_H__
#include <iostream>
using namespace std;

class Anagrafica{
private:
    char* nome;
    char* n_Telefono;

public:
    Anagrafica(char* _nome,char* _n_Telefono);
    ~Anagrafica();
};
#endif
