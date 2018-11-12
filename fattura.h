#ifndef __FATTURA_H__
#define __FATTURA_H__
#include <iostream>
using namespace std;
class Fattura{
private:
	static int n_Fattura;
	int totale;
	bool vendita;
public:
	Fattura(int _totale, bool _vendita);
	~Fattura();
};

#endif

