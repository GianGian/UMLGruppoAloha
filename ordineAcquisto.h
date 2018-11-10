#ifndef __ORDINEACQUISTO_H__
#define __ORDINEACQUISTO_H__
#include <iostream>
#include "ordine.h"
using namespace std;

class OrdineAcquisto: public Ordine{
private:
    char* ID_Articolo;
    int costoUnitario;  
public:
    OrdineAcquisto (int _quantita,char* _ID_Articolo, int _costoUnitario);
    ~OrdineAcquisto();
};
#endif