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
    bool stato;
public:
Prodotto(int _quantita, char* _colore, char* _marca, int _costo, int _data, char* _tipologia);
int getBarcode();
void addCosto(int _costo, int _data);
int getPrezzo(int data);
friend ostream & operator<<(ostream &os, const Prodotto &p);
bool get_stato();
void disattiva_stato();
};

ostream & operator<<(ostream &os, const Prodotto &p);
#endif
