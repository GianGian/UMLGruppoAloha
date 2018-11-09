#ifndef __PRIVATO_H__
#define __PRIVATO_H__
#include <iostream>
#include "consumatore.h"
using namespace std;

class Privato:Consumatore{
private:
    char* codiceFiscale;
    char* cognome;
public:
    Privato(char* _nome,char* _n_Telefono,int _sconto,char* _codiceFiscale,char* _cognome);
    ~Privato();
};
#endif

