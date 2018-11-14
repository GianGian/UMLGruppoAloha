#ifndef __DIPENDENTE_H__
#define __DIPENDENTE_H__
#include <iostream>
#include "anagrafica.h"
using namespace std;

class Dipendente:public Anagrafica{
private:
    char* ruolo;
    int matricola;

public:
    Dipendente(char* _nome,char* _n_Telefono,char* _ruolo,int _matricola);
    ~Dipendente();
    int get_matricola()const;
    void stampa()const;
    friend ostream& operator <<(ostream &os,Dipendente &d);   
};
#endif
