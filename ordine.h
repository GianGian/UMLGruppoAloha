#ifndef __ORDINE_H__
#define __ORDINE_H__
#include <iostream>
#include "fattura.h"
#include "data.h"
using namespace std;
/**
*Classe ordine.
*/
class Ordine{
private:
	static int last_n_ordine; 
	int n_ordine;
	Data d;
	int matricola;
	Fattura *fattura;
public:
	Ordine(int _matricola, int data);
	void add_fattura(Fattura* f);
	int get_matricola();
	int get_n_ordine()const;
	int get_data()const;
	Fattura* get_fattura()const;
};
#endif
