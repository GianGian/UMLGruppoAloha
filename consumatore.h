#ifndef __CONSUMATORE_H__
#define __CONSUMATORE_H__
#include <iostream>
#include "anagrafica.h"
using namespace std;

class Consumatore:public Anagrafica{
private:
   int sconto;

public:
	Consumatore(char* nome, char* telefono, int _sconto);
	int getSconto()const;
	void putSconto(int s);

	
	virtual void stampa()const;
};	
	
#endif
