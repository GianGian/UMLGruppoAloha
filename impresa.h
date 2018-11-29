#ifndef __IMPRESA_H__
#define __IMPRESA_H__
#include <iostream>
#include "consumatore.h"
using namespace std;

class Impresa: public Consumatore{
private:
    char* piva;
    //bool imp; //aggiunte silvia
    //bool pri;

public:
	Impresa(char* _nome, char* _telefono, char* _piva, int _sconto);
	friend ostream& operator<< (ostream &os, Impresa &i);
	void stampa()const;
};

ostream& operator<< (ostream &os, Impresa &i);
#endif
