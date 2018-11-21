#ifndef __IMPRESA_H__
#define __IMPRESA_H__
#include <iostream>
#include "consumatore.h"
using namespace std;

class Impresa: public Consumatore{
private:
    char* piva;

public:
	Impresa(char* _nome, char* _telefono, char* _piva, int _sconto);
};
#endif
