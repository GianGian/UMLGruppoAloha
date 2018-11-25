//aggiunto riferimetno a servizio
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
    static int last_barcode; //<Usato per avere barcode univoci
    int barcode;
public:
Prodotto(int _quantita, char* _colore, char* _marca, double _costo);
int getBarcode();
friend ostream & operator<<(ostream &os, Prodotto &p);
};

ostream & operator<<(ostream &os, Prodotto &p);
#endif
