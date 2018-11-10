#ifndef __ORDINEVENDITA_H__
#define __ORDINEVENDITA_H__
#include <iostream>
#include "ordine.h"
using namespace std;

class OrdineVendita: public Ordine{
private:
    char* via;
  
public:
    OrdineVendita (int _quantita,char* _via);
    ~OrdineVendita();
};
#endif
