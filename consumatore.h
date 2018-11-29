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
	int getSconto();
	void putSconto(int s);
	friend ostream& operator<< (ostream &os, const Consumatore &c); //aggiunta solo per far funzionare le cose 
	//da togliere quando abbiamo capito come va implementato ordinevendita
	
	//virtual void stampa const();
};	

ostream& operator<< (ostream &os, const Consumatore &c);		
#endif
