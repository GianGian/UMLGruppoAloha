//aggiunto riferimetno a servizio
#ifndef __PRODOTTO_H__
#define __PRODOTTO_H__
#include <iostream>
#include "servizio.h"
using namespace std;

class Prodotto{
private:
    int quantita;
    char* colore;
    char* marca;
    double costo;
    static int barcode;
    Servizio* s;
public:
    Prodotto(int quantita, char* _colore, char* _marca, double _costo, Servizio* _s = NULL);
    void stampa()const;
    ~Prodotto();
};

#endif
