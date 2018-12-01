#ifndef __FATTURA_H__
#define __FATTURA_H__
#include <iostream>
#include "data.h"
using namespace std;
/**
*Classe che descrive una fattura.
* \arg last_n_Fattura permette di tenere traccia del numero
* di fattura a cui e' arrivato il software per avere un ID univoco.
* \todo Aggiungere data alla fattura
*/
class Fattura{
private:
	static int last_n_Fattura;
	int n_Fattura;
	int totale;
	bool vendita;
	Data d;
public:
	Fattura(int _totale, bool _vendita, int data);
	int get_n_Fattura(); ///< Ritorna il numero di fattura associato all'istanza.
	friend ostream& operator<< (ostream &os, Fattura &f);
};

ostream& operator<< (ostream &os, Fattura &f);
#endif
