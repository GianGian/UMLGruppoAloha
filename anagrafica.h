#ifndef __ANAGRAFICA_H__
#define __ANAGRAFICA_H__
#include <iostream>
using namespace std;

class Anagrafica{
private:
    char* nome;
    char* n_Telefono;
    bool stato;

public:
Anagrafica(char* _nome, char* _n_Telefono);
void put_telefono(char* _n_Telefono);
char* get_nome() const;
char* get_n_Telefono() const;
bool get_stato()const;
void disattiva_stato();
};
#endif
