#ifndef __PRIVATO_H__
#define __PRIVATO_H__
#include <iostream>
#include "consumatore.h"
using namespace std;

class Privato: public Consumatore{
private:
    char* codiceFiscale;
    char* cognome;
    //bool imp;
    //bool pri;
public:
Privato(char* _nome,char* _cognome,char* _telefono, char* _codiceFiscale, int _sconto);
friend ostream& operator<<(ostream &os, Privato &p);
void stampa()const;
};

ostream& operator<<(ostream &os, Privato &p);
#endif

