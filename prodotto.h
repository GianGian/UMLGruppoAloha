#ifndef __PRODOTTO_H__
#define __PRODOTTO_H__
#include <iostream>
using namespace std;

class Prodotto{
private:
    int quantita;
    char* colore;
    char* marca;
    double costo;
    static int barcode;
public:
    Prodotto(int quantita, char* _colore, char* _marca, double _costo);
    void stampa()const;
    ~Prodotto();
};

#endif
