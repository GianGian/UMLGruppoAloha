#ifndef __ORDINE_H__
#define __ORDINE_H__
#include <iostream>
#include "fattura.h"
using namespace std;
/**
*Classe ordine.
*\todo Correggere uso di static.
*/
class Ordine{
private:
	static int last_n_ordine; 
	int n_ordine;
	int matricola;
	Fattura *fattura;
public:
	Ordine(int _matricola);
	void add_fattura(Fattura& f);
};
#endif
