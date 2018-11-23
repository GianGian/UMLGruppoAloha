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
	Dipendente(char* _nome, char* _telefono,char* _ruolo, int _matricola); 
	friend ostream& operator<<(ostream& os,Dipendente& dip);  
};

ostream& operator<<(ostream& os,Dipendente& dip);
#endif
