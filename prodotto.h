//aggiunto riferimetno a servizio
#ifndef __PRODOTTO_H__
#define __PRODOTTO_H__
#include <iostream>
#include <map>
#include <algorithm>
#include "data.h"
using namespace std;

class Prodotto{
private:
    int quantita;
    char* colore;
    char* marca;
    map <Data, int> prezzo;
    static int last_barcode; //<Usato per avere barcode univoci
    int barcode;
    char* tipologia;
public:
Prodotto(int _quantita, char* _colore, char* _marca, int _costo, int _data, char* _tipologia);
int getBarcode();
void addCosto(int _costo, int _data);
friend ostream & operator<<(ostream &os, Prodotto &p);
};

ostream & operator<<(ostream &os, Prodotto &p);
#endif
