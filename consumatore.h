#ifndef __CONSUMATORE_H__
#define __CONSUMATORE_H__
#include <iostream>
#include "anagrafica.h"
using namespace std;

class Consumatore:public Anagrafica{
private:
    int sconto;

public:
    Consumatore(char* _nome,char* _n_Telefono,int _sconto);
    ~Consumatore();
};
#endif
